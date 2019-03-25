bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ;done
    ; ...a-byte; b-word; e-doubleword; x-qword unsigned
    a db 12
    b dw 6 
    e dd 10
    x dq 5
; our code starts here
segment code use32 class=code
    start:
        ; ...(a*a/b+b*b)/(2+b)+e-x
        mov al, [a] ;al=a=12
        mul al      ;ax=al*a=a*a=12
        mov dx, 0   ;dx=0
                    ;dx:ax=a*a=144
        div word [b];ax=dx:ax/b=a*a/b=144/6=24
        mov bx,ax   ;bx=a*a/b
        mov ax, [b]
        mul ax      ;dx:ax=b*b
        mov cx, 0   ;cx:bx=a*a/b
        add ax, bx
        adc dx, cx  ;dx:ax=(a*a/b+b*b)
        ;----
        push dx
        push ax
        pop eax ;eax=(a*a/b+b*b)
        mov bx, word[b]
        mov cx,0
        add bx, 2
        adc cx, 0
        push cx
        push bx
        pop ebx
        mov edx, 0
        div ebx    ;eax=(a*a/b+b*b)/(2+b)
        mov ebx, eax    ;ebx=(a*a/b+b*b)/(2+b)
        ;---
        ;add word [b],2  ;b=b+2
        ;div word [b]    ;ax=dx:ax/b=(a*a/b+b*b)/(2+b)
        ;mov ebx,0
        ;mov bx,ax
        add ebx,dword [e];ebx=(a*a/b+b*b)/(2+b)+e
        mov ecx, 0       
        adc ecx, 0       ;ecx:ebx=(a*a/b+b*b)/(2+b)+e
        sub ebx,dword [x]
        sbb ecx,dword [x+4];ecx:ebx=(a*a/b+b*b)/(2+b)+e-x
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
