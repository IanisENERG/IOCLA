; SPDX-License-Identifier: BSD-3-Clause

%include "printf64.asm"

section .data
    N: dq 7          ; N-th fibonacci number to calculate

section .text
    global main
    extern printf

main:
    push rbp
    mov rbp, rsp
    mov r9, 1
    mov r10, 0

    mov rcx, QWORD [N]       ; we want to find the N-th fibonacci number; N = RCX = 7
    PRINTF64 `%d\n\x0`, rcx  ; DO NOT REMOVE/MODIFY THIS LINE

    ; TODO: calculate the N-th fibonacci number (f(0) = 0, f(1) = 1)
    cmp rcx, 1
    jg itterate

    xor rax, rax

    leave
    ret

itterate:
    dec rcx
    mov r11, r9
    add r9, r10
    xchg r10, r11

    cmp rcx, 1
    jg itterate

    PRINTF64 `%d\n\x0`, r9
    
    xor rax, rax

    leave
    ret
