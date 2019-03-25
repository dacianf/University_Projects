bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf ; add printf and scanf as extern functions            
import exit msvcrt.dll    
import printf msvcrt.dll    ; tell the assembler that function printf is found in msvcrt.dll library
import scanf msvcrt.dll     ; similar for scanf

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    messA db "a = ",0
    messB db "b = ",0
    a dd 0
    b dd 0
    formatR db "%d",0
    formatC db "c = %xh",0
    c dd 0
; our code starts here
segment code use32 class=code
    start:
        ; Read two words a and b in base 10 from the keyboard. 
        ;Determine the doubleword c such that the low word of c is given 
        ;by the sum of the a and b and the high word of c is given by the
        ;difference between a and b. Display the result in base 16 Example:
                ;a = 574, b = 136
                ;c = 01B602C6h
        push messA
        call [printf]
        add esp, 4*1
        push dword a
        push dword formatR
        call [scanf]
        add esp, 4*2
        
        push messB
        call [printf]
        add esp, 4*1
        push dword b
        push dword formatR
        call [scanf]
        add esp, 4*2

        mov bx,word [a]
        mov cx,word [b]
        mov word [c], bx
        add word [c], cx
        mov word [c+2], bx
        sub word [c+2], cx
        
        
        
        push dword [c]
        push formatC
        call [printf]
        add esp, 4*2
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
