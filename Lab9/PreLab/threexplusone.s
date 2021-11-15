;John Link, jwl9vq@virginia.edu, 11/1/21, threexplusone.s
;Optimizations used - removing all imul and idiv; finding a more effieient mod command; no beq or bra
global threexplusone

section .text
threexplusone:
xor rax, rax
xor r10, r10
cmp rdi, 1
jle end
inc r10
test rdi, 1   ;removed idiv checking for even/odd
jz even       ;removed unnecessary jmp statements
lea rdi, [rdi*2+rdi]              ;removed imul operation
inc rdi
push r10
call threexplusone
pop r10
add r10, rax
mov rax, r10
ret

even:
shr rdi, 1
push r10
call threexplusone
pop r10
add r10, rax
mov rax, r10
ret

end:
mov rax, r10
ret
