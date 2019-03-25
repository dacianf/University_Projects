bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...a-byte; b-word; e-doubleword; x-qword signed
    a db 12
    b dw 6 
    e dd 10
    x dq 5
; our code starts here
segment code use32 class=code
    start:
        ; ...(a*a/b+b*b)/(2+b)+e-x;
        mov al,[a]  ;al=a
        imul al ;ax=a*a
        mov dx,0
        idiv word [b]  ;ax=a*a/b
        mov bx,ax;bx=a*a/b 
        mov ax,b ;ax=b
        imul word[b]    ;dx:ax=b*b
        add ax,bx
        adc dx,0  ;dx:ax=a*a/b+b*b
        ;---
        push dx
        push ax
        pop ebx ;ebx=a*a/b+b*b
        mov ax, word [b]
        cwde
        add eax, 2;eax=b+2
        mov ecx, eax ;ecx=b+2
        mov eax,ebx; eax=a*a/b+b*b
        cdq         ; edx:eax=a*a/b+b*b
        idiv ecx   ; eax=(a*a/b+b*b)/(2+b)
        cdq ;edx:eax=(a*a/b+b*b)/(2+b)
        add eax, dword[e]
        adc edx, 0  ;edx:eax=(a*a/b+b*b)/(2+b)+e
        sub eax, dword[x]
        sbb edx, dword[x+4]
        ;---
        ;add word [b],2
        ;mov bx,[b]
        ;idiv bx ;ax=dx:ax/bx=(a*a/b+b*b)/(2+b)
        ;cwd     ;eax=(a*a/b+b*b)/(2+b)
        ;mov edx,0
        ;add eax,dword[e]
        ;adc edx,0   ;edx:eax=(a*a/b+b*b)/(2+b)+e
        ;sub eax, dword[x]
        ;sbb edx, dword[x+4] ;edx:eax=(a*a/b+b*b)/(2+b)+e-x
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
