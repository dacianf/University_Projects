; A file name and a text (defined in the data segment) are given. 
;The text contains lowercase letters, digits and spaces. 
;Replace all the digits on odd positions with the character ‘X’. 
;Create the file with the given name and write the generated 
;text to file. 
bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fprintf, fclose
import exit msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file_name db "sir.txt",0
    access_mode db "w",0
    file_descriptor dd -1
    text db "john is running toghether with 3 sheeps and 6 dogs",0
    lenTx equ $-text
; our code starts here
segment code use32 class=code
    start:
        mov esi, 0
        mov ecx, lenTx 
        mov ebx, 2
        changeLet:
            mov eax,ecx
            dec eax ;'cuz 0 is first element
            mov edx,0
            div ebx
            cmp edx,0
            jne putX
            jmp sf
            putX:
                mov byte [text+esi],'X'    
        sf:
        inc esi
        loop changeLet
        
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor],eax
        
        cmp eax,0
        je final
        
        push dword text
        push dword [file_descriptor]
        call [fprintf]
        add esp, 4*2
        
        push dword[file_descriptor]
        call [fclose]
        add esp, 4
        
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
