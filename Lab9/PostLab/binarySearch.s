;John Link, jwl9vq@virginia.edu, 11/2/21, binarySearch.s
global binarySearch

section .text
binarySearch:
cmp rsi, rdx
jg nfound
mov r10, rdx
add r10, rsi
shr r10, 1
cmp ecx, [rdi+4*r10]
jg right
jl left
mov rax, r10
ret

left:
mov rdx, r10
call binarySearch
ret

right:
inc r10
mov rsi, r10
call binarySearch
ret

nfound:
mov rax, -1
ret
