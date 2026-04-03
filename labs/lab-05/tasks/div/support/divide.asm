; SPDX-License-Identifier: BSD-3-Clause
; https://en.wikibooks.org/wiki/X86_Assembly/Arithmetic

%include "printf64.asm"

section .data
    dividend1 db 91
    divisor1 db 27
    dividend2 dd 67254
    divisor2 dw 1349
    dividend3 dq 69094148
    divisor3 dq 12345678
    dividend4 dq 0x00000000FFFFFFFF, 0x0000000000000000
    divisor4 dq 0x0000000000010000

section .text
extern printf
global main
main:
    push rbp
    mov rbp, rsp

    xor rax, rax

    mov al, byte [dividend1]
    mov bl, byte [divisor1]
    div bl

    xor rbx, rbx
    mov bl, al
    PRINTF64 `Quotient: %hhu\n\x0`, rbx

    xor rbx, rbx
    mov bl, ah
    PRINTF64 `Remainder: %hhu\n\x0`, rbx


    ; TODO: Calculate quotient and remainder for 67254 / 1349.

    xor rdx, rdx
    mov eax, dword [dividend2]
    mov dx, ax
    shr eax, 16
    xchg ax, dx
    mov bx, dword [divisor2]
    div bx

    xor ebx, ebx
    mov bx, ax
    PRINTF32 `Quotient: %hhu\n\x0`, rbx

    xor ebx, ebx
    mov bx, dx
    PRINTF32 `Remainder: %hhu\n\x0`, rbx


    ; TODO: Calculate quotient and remainder for 69094148 / 87621.

    leave
    ret
