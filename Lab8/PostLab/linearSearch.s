; John Link, jwl9vq@virginia.edu, 10/31/21, linearSearch.s
global linearSearch
section .text
linearSearch:
xor r10d, r10d
xor r11d, r11d
xor eax, eax
loop:
cmp r10d, esi
je empty
mov r11d, [rdi+4*r10]
cmp edx, r11d
je found
inc r10d
jmp loop

found:
mov eax, r10d
ret

empty:
mov eax, -1
ret
