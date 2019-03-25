bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ;   a - byte, b - word, c - double word, d - qword 
    ;   Signed representation
    a db 6
    b dw 10
    c dd 3
    d dq 100
; our code starts here
segment code use32 class=code
    start:
        ; compute d-a+(b+a-c)
        mov ax, word [b]
        cwde
        mov ebx, eax    ;ebx=b
        mov al, byte [a]
        cbw
        cwde            ;eax=a
        add eax,ebx ;eax=b+a
        sub eax,dword [c] ;eax=b+a-c
        mov ebx,eax ;ebx=b+a-c
        mov al, byte [a]
        cbw
        cwde
        cdq ;edx:eax=a
        sub dword[d],eax
        sbb dword[d+4],edx  ;d=d-a
        mov eax,ebx
        cdq ;edx:eax=(b+a-c)
        add dword[d],eax
        adc dword[d+4],edx
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
