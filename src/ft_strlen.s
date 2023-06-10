global ft_strlen

section .text

ft_strlen:
  push rbp
  mov rbp, rsp
  call ft_strlen_init
  call ft_strlen_loop
  pop rbp
  ret

ft_strlen_init:
  xor rax, rax
  ret

ft_strlen_inc:
  inc rax
  jmp ft_strlen_loop

ft_strlen_loop:
  cmp byte [rdi+rax], 0x0
  jnz ft_strlen_inc
  ret
