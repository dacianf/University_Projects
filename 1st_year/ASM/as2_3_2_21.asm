bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ... a,b,c,d-byte, e,f,g,h-word
    a db 2
    b db 3 
    c db 4 
    d db 5
    e dw 12
    f dw 13
    g dw 14
    h dw 15
    x dd 0
; our code starts here
segment code use32 class=code
    start:
        ; ... Compute (f*g-a*b*e)/(h+c*d) 
        mov AX, word [f]    ;AX=13
        mul word [g]        ;AX=13*14=182=B6h
        mov [x],AX          ;x=182
        mov [x+2],DX        ;x=182
        mov EBX, dword [x]  ;EBX=182
        mov EAX, 0          ;EAX=0
        mov AL, byte [a]    ;AL=2
        mul byte [b]        ;AX=2*3=6
        mul word [e]        ;DX:AX=6*12=72
        mov [x],AX          ;x=72
        mov [x+2],DX        ;x=72
        mov EAX, dword [x]  ;EAX=72
        sub EBX,EAX         ;EBX=182-72=110
        mov EAX, 0          ;EAX=0
        mov AL, byte [c]    ;AL=4
        mul byte [d]        ;AX=4*5=20
        add AX, word [h]    ;AX=20+15=35
        mov ECX, EAX
        mov EAX, EBX
        mov EDX, 0          ;EAX=0
        div ECX             ;EAX=EDX:EAX/ECX=110/35=3
                            ;EDX=5
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
