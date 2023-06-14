
global ft_strcmp

global .text

ft_strcmp:                     ; rdi = char *s1, rsi = char *s2
  push rbp
  mov rbp, rsp
  mov rax, rax

ft_strcmp_loop:
  mov rax, [rdi]
  cmp rax, [rsi]
  jl ft_strcmp_exit_less
  jg ft_strcmp_exit_greater
  cmp QWORD [rdi], 0
  jz ft_strcmp_exit_equal
  inc rdi
  inc rsi
  jmp ft_strcmp_loop

ft_strcmp_exit_less:
  mov QWORD rax, -1
  pop rbp
  ret

ft_strcmp_exit_greater:
  mov rax, 1
  pop rbp
  ret

ft_strcmp_exit_equal:
  mov rax, 0
  pop rbp
  ret
