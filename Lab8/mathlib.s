; John Link, jwl9vq@virginia.edu, 10/30/21, mathlib.s
global product
global power

section .text
product:
xor r10, r10
xor rax, rax
mult:
cmp rsi, r10
je endloop
add rax, rdi
add r10, 1
jmp mult

power:
xor r11, r11
inc r11
mov rdx, rdi
xor rax, rax
inc rax
realPow:
cmp rsi, r11
je endloop
push rsi
mov rsi, rdx
call product
pop rsi
mov rdi, rax
sub rsi, 1
call realPow

endloop:
ret
