
global ft_write

section .text

ft_write:
  push rbp
  mov rbp, rsp
  mov rax, 1
  syscall
  pop rbp
  ret

