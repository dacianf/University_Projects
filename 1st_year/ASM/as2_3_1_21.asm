bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ... a,b,c - byte, d - word
    a db 100
    b db 50
    c db 80
    d dw 2000
; our code starts here
segment code use32 class=code
    start:
        ; Compute d-[3*(a+b+2)-5*(c+2)] =2000-(3*(100+50+2)-5*(80+2))
        ; =2000-(3*152-5*82)=2000-(456-410)=2000-46=1954
        mov AL, byte [a]    ;AL=100=64h
        add AL, byte [b]    ;AL=100+50=150=96h
        add AL, 2           ;AL=150+2=152=98h
        mov BL, 3           ;BL=3
        mul BL              ;AX=152*3=456=1C8h
        mov DX, AX          ;DX=456
        mov AX, 0           ;AX=0
        mov AL, byte [c]    ;AL=80=50h
        add AL, 2           ;AL=80+2=82=52h
        mov BL, 5           ;BL=5
        mul BL              ;AX=AL*BL=82*5=410=19Ah
        sub DX,AX           ;DX=456-410=46=2Eh
        mov AX, word [d]    ;AX=2000=7D0h
        sub AX,DX           ;AX=2000-46=1954=7A2h
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
