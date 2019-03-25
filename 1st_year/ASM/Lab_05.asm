bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import printf msvcrt.dll
; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
; our data is declared here (the variables needed by our program)


; our data is declared here (the variables needed by our program)
segment data use32 class=data
    s1 db '+', '4', '2', 'a', '8', '4', 'X', '5'  ;declare the first string of bytes
    l1 equ $-s1 ;compute the length of the string l1
    s2 db 'a', '4', '5'   ;declare the second string of bytes 
    l2 equ $-s2 ;compute the length of the string l1 
    d times l1*l2 db 0 ;reserve l1*l2 bytes for the destination string and initialize it

; our code starts here
segment code use32 class=code
    start:
        ; ;28.Se dau doua siruri de caractere S1 si S2. Sa se construiasca sirul D prin concatenarea elementelor de pe pozitiile multiplu de 3 din sirul S1 cu elementele sirului S2 in ordine inversa.
            ;Exemplu:
            ;S1: '+', '4', '2', 'a', '8', '4', 'X', '5'
            ;S2: 'a', '4', '5'
            ;D: '+', 'a', 'X', '5', '4', 'a'
    
        mov ecx,l1 ;we put the length l1 in ECX in order to make the loop
        mov esi,0
        mov edi,0
        jecxz Sfarsit 
        Repeta:
            mov al,[s1+esi]
            mov [d+edi],al 
            add esi,3
            inc edi
            cmp esi, ecx
        jle Repeta
  
        mov ecx,l2 ;we put the length l2 in ECX in order to make the loop
        mov esi,l2-1 

        Repeta2:
            mov al,[s2+esi]
            mov[d+edi],al 
            dec esi
            inc edi
        loop Repeta2
        Sfarsit: ;end of the program
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
