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
    a db 1
    b dw 10
    c dd 100
    d dq 1000

; our code starts here
segment code use32 class=code
    start:
        ; ...(c-a) + (b - d) +d
        mov ebx, 0
        mov bl,[a] ;ebx=a
        sub [c],ebx ;c=c-a
        mov eax, 0
        mov ax, word [b]
        mov edx,0
        sub eax, dword [d]
        sbb edx, dword [d+4]    ;edx:eax=b-d
        add eax, ebx
        adc edx, 0  ;edx:eax=(c-a) + (b - d)
        add eax, dword [d]
        adc edx, dword [d+4]    ;edx:eax=(c-a) + (b - d) + d
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
