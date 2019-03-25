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
    a db 2, 1, -3, 3, -4, 2, -6
    lenA equ $-a
    b db 5,4,3,2,1
    lenB equ $-b
    r times lenA+lenB db 0
    lenR equ $-r
; our code starts here
segment code use32 class=code
    start:
        ; ...Two byte strings A and B are given. Obtain the string R by concatenating the elements of B in reverse order and the negative elements of A. 
        mov ecx, lenB          ;ecx=lenB
        mov esi, lenB-1        ;esi=offset of b last element
        mov edi, 0             ;edi=offset of first elem of r
        cld                    ;direction flag=0 => left to right parsing
        loop1:                 ;loop1 copies B elements in reverse order in R
            std                ;set direction flag on 1 => right to left parsing
            mov al,[b+esi]
            dec esi            ;al=[esi] esi--
            cld                ;direction flag=0 => left to right parsing
            mov [r+edi],al
            inc edi            ;[edi]=al edi++
            dec ecx
            ja loop1           ;ecx-- jmp to loop1 instruction
            
        cld                    ;direction flag=0 => left to right parsing
        mov esi, 0             ;esi=offset of a first element
        mov ecx, lenA          ;ecx=lenA
        loop2:                 ;loop2 copies negative elements of A into R
            mov al,[a+esi]     
            inc esi            ;al=[esi] esi++
            cmp al,0           ;compare al value with 0
            jl comp            ;if above comparation is less than zero jump to comp 
            loop loop2         ;ecx-- jmp to loop2 instruction
        comp:                  ;comp is called when al value is < 0
            mov [r+edi],al     
            inc edi            ;[edi]=al; edi++
            loop loop2         ;ecx-- jmp to loop2 instruction
            
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
