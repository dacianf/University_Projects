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
    s1 db '+', '4', '2', 'a', '8', '4', 'X', '5'
    l1 equ $-s1
    s2 db 'a', '4', '5'
    l2 equ $-s2
    d times l1*l2 db 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ecx, l1
        mov edx, 0
        mov esi, 0
        mov edi, 0
        loop1:
            mov eax, esi
            mov bh, 3
            div bh
            mov bl, [s1+esi]
            inc esi
            cmp ah,0
            je mutare
            sf1:
            dec ecx
            cmp ecx,0
            jge loop1
            jb part2
        mutare:
            mov [d+edi], bl
            inc edi
            jmp sf1
        part2:
        mov ecx, l2-1
        loop2:
            mov bl, [s2+ecx]
            mov [d+edi],bl
            inc edi
            dec ecx
            cmp ecx,0
            jge loop2
            
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
