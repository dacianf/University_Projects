bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    A dq 1111101010101010101010101010101010101010101010101010101010101010b ;1111 1010 1010 1010 1010 1010 1010 1010 1010 1010 1010 1010 1010 1010 1010 1010b
    B dd 0
    C db 0
    N db 0

; our code starts here
segment code use32 class=code
; ...Given the quadword A, obtain the integer number N represented on the bits 17-19 of A. 
    ;Then obtain the the doubleword B by rotating the high doubleword of A N positions to the left. 
    ;Obtain the byte C as follows:
        ;the bits 0-2 of C are the same as the bits 9-11 of B
        ;the bits 3-7 of C are the same as the bits 20-24 of B
    start:
        ; ...
        
        ;find the number N, in our case it is 5
        mov EAX,dword [A]       ;EAX has first 32 bits of A
        shr EAX,17
        and AL,00000111b
        mov byte [N],AL ;move the number we found into the variable N
        
        mov EAX,dword [A+4] ;put the high end part of [A]quadword in the register EAX 
        mov CL,byte [N] ;move the variable N in the register CL 
        rol EAX,CL ;shift EAX to the left with N positions EAX=‭1F55555540‬h
        mov dword [B],EAX ;put the result into the variable [b] 
            
        shr EAX,9 ;to form the first part of C we shift to the right nine times
        and EAX, 00000000000000000000000000000111b ;to get only the 3 values we isolate the bits from the positions 0-2 :010b
        
        mov EBX,dword [B] ;to find the bites from the positions 20-24 we put the value of B in EBX
        shr EBX,17 ;shift them to the right in order to get them on the positions 3-7
        and EBX,00000000000000000000000011111000b ;isolate the bits :10101b
        or EAX,EBX ;move our final solution into register EAX
        mov byte [C],AL ;10101010b = AAh
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
