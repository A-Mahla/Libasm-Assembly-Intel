global ft_strlen

section .text

ft_strlen:
  push rbp
  mov rbp, rsp
  call init
  call loop
  pop rbp
  ret

init:
  xor rax, rax
  ret

increment:
  inc rax
  jmp loop

loop:
  cmp byte [rdi+rax], 0x0
  jnz increment 
  ret
