bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...a - byte, b - word, c - double word, d - qword - Unsigned representation
    a db 5
    b dw 10
    c dd 7
    d dq 11
; our code starts here
segment code use32 class=code
    start:
        ; ...d-(a+b)+(c+c) 
        mov eax, 0
        mov al, [a]
        mov ebx, 0
        mov bx, [b]
        add eax,ebx
        mov ebx,[c]
        add ebx, ebx
        mov ecx, 0
        adc ecx, 0  ;ecx:ebx=c+c
        sub dword [d], eax
        sbb dword [d+4],0
        add dword [d], ebx
        adc dword [d], ecx ;d=d-(a+b)+(c+c) 
        mov eax, dword [d]
        mov edx, dword [d+4]
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
