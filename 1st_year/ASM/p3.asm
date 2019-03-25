bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...a,b,c,d-byte, e,f,g,h-word
    b db 3
    c db 5
    e dw 7
    g dw 9
    h dw 13
; our code starts here
segment code use32 class=code
    start:
        ; ...(e+g-h)/3+b*c 
        mov dx, 0
        mov ax, [e]
        mov bx, [g]
        add ax, bx  ;ax=e+g
        mov bx, [h]
        sub ax, bx  ;ax=e+g-h
        mov bx, 3
        div bx      ;ax=(e+g+h)/3
        mov bx, ax  ;bx=ax=(e+g+h)/3
        mov al, [b]
        mov cl, [c]
        mul cl      ;ax=b*c
        add bx, ax
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
