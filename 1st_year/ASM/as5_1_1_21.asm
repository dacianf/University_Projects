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
    sir DW 12345, 20778, 4596 
    len equ ($-sir)/2
    r times 100 dw 0
    lenR equ $-r
    cif times 6 db 0
    lenCif equ $-cif
    kCif dw 0
    zece dw 10
; our code starts here
segment code use32 class=code
    start:
        ; ...Being given a string of words, obtain the string (of bytes) of the digits in base 10 of each word from this string. 
        mov esi, sir
        mov edi,r
        mov ecx,len
        mov ebx,0
        cld
        parseSir:
            mov ebx,0                ;ebx=0
            mov word [kCif],0        ;kCif=0 --digits contor
            lodsw                    ;AX=s[0] esi+=2
            findCif:
                mov edx,0            ;edx=0 so dx=0 so dx:ax will be ax
                div word [zece]      ;ax=dx:ax/10  dx=dx:ax%10
                mov bx,word [kCif]   ;bx=[kCif] bx 'll be contor's value
                mov [cif+ebx],dx     ;put inside cif string digits of numbers
                inc word [kCif]      ;kCif++
                cmp ax,0             ;compares ax with 0
                ja findCif           ;if ax>0 repeat findCif
            dec word [kCif]          ;kCif-- 'cuz we need last of cif string
            mov ebx,0                ;ebx=0 so there will be no problems :)
            movInRes:
                mov bx, word [kCif]  ;bx=[kCif]
                mov al, [cif+ebx]    ;al=digits of sir[0]
                stosb                ;r= digits of sir[0] 
                dec word [kCif]      ;kCif--
                cmp word [kCif],0    ;compares kCif with 0
                jge movInRes         ;if kCif>=0 repeat movInRes
        loop parseSir
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
