
global ft_strcmp

global .text

ft_strcmp:
  push rbp
  mov rbp, rsp
  call ft_strcmp_loop
  pop rbp
  ret

ft_strcmp_inc:
  cmp byte [rdi], 0
  jz ft_strcmp_exit
  inc rdi
  inc rsi
  jmp ft_strcmp_loop

ft_strcmp_loop:
  mov al, byte [rdi]
  cmp al, byte [rsi]
  je ft_strcmp_inc
  call ft_strcmp_exit
  ret

ft_strcmp_exit_neg:
  neg rax
  ret

ft_strcmp_exit:
  xor rax, rax
  mov al, byte [rdi]
  sub al, byte [rsi]
  test al, al
  js ft_strcmp_exit_neg
  ret

