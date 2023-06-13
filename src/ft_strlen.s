global ft_strlen

section .text

ft_strlen:
  push rbp
  mov rbp, rsp
  xor rax, rax            ; set rax = 0x0  => continue to next function

ft_strlen_loop:
  cmp byte [rdi+rax], 0x0 ; compare the byte behind the pointer [rdi+rax] to 0
  jz ft_strlen_ret       ; jump only if the comparison above is "true" (equal to zero)
  inc rax
  jmp ft_strlen_loop

ft_strlen_ret
  pop rbp
  ret
