bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    nr dd 0
    msg1 db 'cuvant: ',0xA,0xD,0
    msg2 db 'numar: ',0xA,0xD,0
    msg3 db '=> ',0
    
    formatNr db '%d',0
    formatCuv db '%s', 0
    
    cuvant times 100 db 0
    cuvantFinal times 100 db 0
    
    vocals db 'aeiouAEIOU',0
    lenVoc equ $-vocals
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov esi, cuvant
        mov edi, cuvantFinal
        
        push msg1
        call [printf]
        add esp, 4
        
        push cuvant
        push formatCuv
        call [scanf]
        add esp, 4*2
        
        push msg2
        call [printf]
        add esp, 4
        
        push nr
        push formatNr
        call [scanf]
        add esp, 4*2
        
        mov edx, 0
        mov eax, [nr]
        mov ebx, 2
        div ebx
        cmp edx, 0
        je par
        jne impar
        
        mov eax, 0
        
        par:
            lodsb
            cmp al, 0
            je final
            add al, 20
            stosb
        jmp par
        
        impar:
            lodsb
            cmp al, 0
            je final
            stosb
            jmp isVocal
        jmp impar
        
        isVocal:
            mov ecx, lenVoc
            ver:
                mov dl, [vocals+ecx-2]
                cmp dl, al
                je faTreaba
            loop ver
            jmp impar
            faTreaba:
                mov bl, al
                mov al, 'p'
                stosb
                mov al, bl
                stosb
        jmp impar
        final:
        push msg3
        call [printf]
        add esp, 4
        push cuvantFinal
        call [printf]
        add esp, 4
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
