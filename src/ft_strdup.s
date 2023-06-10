global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc

section .text

ft_strdup:
  push rbp
  mov rbp, rsp
  push rdi
  call ft_strlen
  mov rdi, rax
  call malloc WRT ..plt
  cmp rax, 0x0
  jz ft_strdup_null
  mov rdi, rax
  pop rsi
  call ft_strcpy
  pop rbp
  ret

ft_strdup_null:
  pop rdi
  pop rbp
  ret

