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
    a dw 15
    b dw 9
    c dw 10
    d dw 16
; our code starts here
segment code use32 class=code
    start:
        ; compute a-c+d-7+b-(2+d)
        mov AX, word [a]    ;AX=15
        sub AX, word [c]    ;AX=15-10=5
        add AX, word [d]    ;AX=5+16=21
        sub AX, 7           ;AX=21-7=14
        add AX, word [b]    ;AX=14+9=23
        mov BX, word [d]    ;BX=16
        add BX, 2           ;BX=16+2=18
        sub AX, BX          ;AX=23-18=5
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
