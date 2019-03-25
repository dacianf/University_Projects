bits 32

global convertToHEX
extern printf
import printf msvcrt.dll

segment data use32 class=data
    format db "0x%xh",0

; our code starts here
segment code use32 class=code public
    convertToHEX:
        mov eax, [esp+4]
        push eax
        push format
        call [printf]
		ret