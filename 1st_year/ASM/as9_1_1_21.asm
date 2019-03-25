bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit 
extern convertToHEX             
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

;import function function.asm

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    x dd 0000001b
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push dword [x]
        call convertToHEX
        add esp, 4
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
