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
    a dw 0111011101010111b
    b dw 1001101110111110b
    c dd 0
; our code starts here
segment code use32 class=code
    start:
        ; ...Given the words A and B, compute the doubleword C as follows:
        ;the bits 0-3 of C are the same as the bits 5-8 of B
        ;the bits 4-10 of C are the invert of the bits 0-6 of B
        ;the bits 11-18 of C have the value 1
        ;the bits 19-31 of C are the same as the bits 4-15 of B
        mov ax, [b]
        and ax, 0000000111100000b   ;isolate bits 5-8 of b
        ;mov cl, 5
        ;ror ax, 5
        ror ax, 5
        mov bx,ax    ;bx=0-3 of C are the same as the bits 5-8 of B
        mov ax, [b]
        and ax, 0000000001111111b   ;ax= 0-6 bits of B
        not ax
        ;mov cl,9
        ;shl ax, cl
        shl ax, 9
        shr ax, 5;ax has on bits 4-10 invert of the bits 0-6 of B
        ;mov cl, 9
        ;shr ax, 9
        or bx, ax;bx has on bits 4-10 invert of the bits 0-6 of B and 0-3 are the same as the bits 5-8 of B
        mov ecx, 0
        mov cx, bx; ecx has on bits 4-10 invert of the bits 0-6 of B and 0-3 are the same as the bits 5-8 of B
        mov eax,00000000000001111111100000000000b
        or ecx,eax;ecx=ecx and bits 11-18 have the value 1
        
        mov eax,0   ;eax=0
        mov ax,[b]  ;eax=b
        and eax,00000000000000001111111111110000b ;isolate bits 4-15 of b
		shl eax,16  ;shift to left eax bits 16 positions
        ;mov cl, 16
        ;shl eax, cl
        or ecx, eax ;move in bits 19-31 of ecx eax bits which are bits 4-15 of b
        
        mov dword [c], ecx
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
