global mathlib
section .data
v1 DQ 0
v2 DQ 0
prod DQ 0
pow DQ 0

section .text

multiply:
add [prod], rdi
cpm rsi, 0
jeq endPgm
sub rsi, 1
jmp multiply

power:
mov [v]

endPgrm:
ret
