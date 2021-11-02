;John Link, jwl9vq@virginia.edu, 11/2/21, binarySearch.s
global binarySearch

section .text
binarySearch:
cmp rsi, rdx
je nfound
mov r10, rdx
sub r10, rsi
shr r10, 1
lea r10, [r10 * 4]
cmp ecx, [edi+r10d]
jg right
jl left
mov rax, r10
ret

left:
mov rdx, r10
call binarySearch
ret

right:
mov rsi, r10
call binarySearch
ret

nfound:
mov rax, -1
ret
