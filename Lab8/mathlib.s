global mathlib
extern multiply
extern power
section .data
v1 DQ 0
v2 DQ 0
itr DQ 0
prod DQ 0
pow DQ 0

section .text
mathlib:
mov [v1], rdi
mov [v2], rsi
xor r10, r10
xor rax, rax

multiply:
mov [v1], rdi
mov [v2], rsi
xor r10, r10
xor rax, rax
loop:
cmp rsi, r10
je endloop
add rax, rdi
add r10, 1
jmp loop

power:
mov [v1], rdi
mov [v2], rsi
xor r10, r10
xor rax, rax
inc rax
realPow:
cmp rsi, r10
je endloop
mov [v2], rsi
mov rsi, [v1]
call multiply
mov rsi, [v2]
mov rdi, rax
sub rsi, 1
call realPow


endloop:
ret
