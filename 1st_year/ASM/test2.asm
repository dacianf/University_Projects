bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fread, printf, fopen, fclose     
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll                 

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    nameInFile db "fisierIN.txt",0 
    fileInAccess db "r",0
    fileInAddress dd 0

    readedString times 100 db 0
    lenStr equ $-readedString
    readFormat db "%s",0
    
    cuvant times 100 db 0
    k dd 0
    cuvantInvers times 100 db 0
    nrLitere dd 0
    
    propozitie times 100 db 0
    nrCuvinte dd 1
    
    nrPropozitie dd 1
    
    formatPrint db "Propozitia %d: %s Nr cuvinte: %d, Primul cuvand %s are %d litere.",0xA, 0xD,0
; our code starts here
segment code use32 class=code
    start:
        ;read from file
        push fileInAccess
        push nameInFile
        call [fopen]
        add esp, 4*2
        mov [fileInAddress], eax
        
        push dword [fileInAddress]
        push dword lenStr
        push dword 1
        push dword readedString
        call [fread]
        add esp, 4*4
        
        push dword [fileInAddress]
        call [fclose]
        add esp, 4
        
        mov esi, readedString
        mov edi, propozitie
        parcurge:
            lodsb
            cmp al, 0
            je final
            cmp al, '.'
            je afisProp
            cmp al, ' '
            je numaraCuv
            jne faCuvant
            rett1:
            stosb
            
        jmp parcurge
        ;print on the screen
        faCuvant:
            mov ebx, [k]
            mov byte [cuvant + ebx], al
            inc dword [k]
        jmp rett1
        numaraCuv:
            cmp dword [nrCuvinte], 1
            je reverseWord
            ret2:
            mov dword [k], 0
            inc dword [nrCuvinte]
        jmp rett1
        
        reverseWord:
            mov ecx, dword [k]
            dec ecx
            intoarce:
                mov bl, byte[cuvant+ecx]
                mov edx, [nrLitere]
                mov byte[cuvantInvers+edx], bl
                inc dword [nrLitere]
            loop intoarce
            mov edx, [nrLitere]
            inc dword [nrLitere]
            mov bl, byte[cuvant]
            mov byte[cuvantInvers+edx], bl
        jmp ret2
        
        afisProp:
            stosb
            push dword [nrLitere]
            push cuvantInvers
            push dword [nrCuvinte]
            push propozitie
            push dword [nrPropozitie]
            push formatPrint
            call [printf]
            add esp, 4*2
            mov dword[nrCuvinte], 0
            mov dword[nrLitere], 0
            inc dword [nrPropozitie]
            mov ecx, 99
            puneZ:
                mov byte[cuvantInvers+ecx], 0
                mov byte[propozitie + ecx], 0
            loop puneZ
            mov edi, propozitie
        jmp parcurge
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program