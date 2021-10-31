; John Link, jwl9vq@virginia.edu, 10/30/21, mathlib.s
global multiply
global power

section .text
multiply:
xor r10, r10
xor rax, rax
loop:
cmp rsi, r10
je endloop
add rax, rdi
add r10, 1
jmp loop

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
call multiply
pop rsi
mov rdi, rax
sub rsi, 1
call realPow

endloop:
ret
