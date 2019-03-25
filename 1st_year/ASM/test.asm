bits 32 ; assembling for the 32 bits architecture
; crtl-shiftn new template
; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, fread, fopen, fclose, fscanf             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll  ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fread msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fscanf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    fileName db "fisierIN.txt"
    fileAddress dd 0
    fileAccess db "r",0
    readedString times 300 db 0
    readedFormat db "%s",0
    cuvant times 100 db 0
    
    propozitie times 100 db 0
    nrCuvinde dd 0
    nrLitere dd 0
    cuvantInvers times 100 db 0
    
    formatPrint db "Propozitia %d: %s Nr cuvinte: %d, Primul cuvand %s are %d litere\\n",0xA, 0xD,0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push fileAccess
        push fileName
        call [fopen]
        add esp, 4*2
        mov [fileAddress], eax
        
        citire:
            push cuvant
            push readedFormat
            push dword [fileAddress]
            call [fscanf]
            add esp, 4*2
        cmp byte[cuvant], 0
        jne citire
            
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
