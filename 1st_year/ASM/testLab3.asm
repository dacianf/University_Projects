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
    a db 10
    b dw 5
    c dd 100
    d dq 20
    use resd 1
; our code starts here
segment code use32 class=code
    start:
        ; ... (c-a) + (b - d) +d 
        mov EAX,0
        mov AX, 2555
        shl EAX, 0x16
        shr EAX, 0x16
        mov EAX, 0
        mov AL, byte [a]
        mov EBX, dword [c]
        sub EBX, EAX ;ebx=c-a
        mov dword [use], EBX ;use=c-a
        mov EDX, 0
        mov EAX, 0
        mov AX, b   ;edx:eax=b
        mov EBX, d  ;ebx=d
        mov ECX, 0  ;ecx:ebx=d
        sub EAX, EBX
        sbb EDX, ECX;edx:eax=b-d
        mov EBX, dword [use]
        mov ECX, 0
        add EAX, EBX
        adc EDX, ECX
        mov EBX, [d]
        mov ECX, [d+4]
        add EAX, EBX
        adc EDX, ECX
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
