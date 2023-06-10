global ft_strlen

section .text

ft_strlen:
  push rbp
  mov rbp, rsp
  call ft_strlen_init
  call ft_strlen_loop
  pop rbp
  ret

ft_strlen_init
  xor rax, rax           ; set rax = 0x0
  ret

ft_strlen_inc:
  inc rax
  jmp ft_strlen_loop

ft_strlen_loop:
  cmp byte [rdi+rax], 0x0 ; compare the byte behind the pointer [rdi+rax] to 0
  jnz ft_strlen_inc       ; jump only if the comparison above is "not true" (not zero)
  ret
