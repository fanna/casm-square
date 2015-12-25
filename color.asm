global color
extern fputc

section .text

color:
        push    ebp
        mov     ebp, esp
        sub     esp, 24

        mov     eax, dword [ebp+18H]
        mov     dword [esp+4H], eax
        mov     eax, dword [ebp+8H]
        mov     dword [esp], eax
        call    fputc

        mov     eax, dword [ebp+18H]
        mov     dword [esp+4H], eax
        mov     eax, dword [ebp+0CH]
        mov     dword [esp], eax
        call    fputc

        mov     eax, dword [ebp+18H]
        mov     dword [esp+4H], eax
        mov     eax, dword [ebp+10H]
        mov     dword [esp], eax
        call    fputc

        mov     eax, dword [ebp+18H]
        mov     dword [esp+4H], eax
        mov     eax, dword [ebp+14H]
        mov     dword [esp], eax
        call    fputc

        mov     esp, ebp
        pop     ebp
        ret
