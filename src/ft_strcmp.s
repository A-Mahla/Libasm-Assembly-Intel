
global ft_strcmp

global .text

ft_strcmp:
  push rbp
  mov rbp, rsp
  xor rax, rax
  call ft_strcmp_loop
  pop rbp
  ret

ft_strcmp_loop:
  mov al, byte [rdi]
  cmp al, byte [rsi]
  jne ft_strcmp_exit
  cmp byte [rdi], 0
  jz ft_strcmp_exit_zero
  inc rdi
  inc rsi
  jmp ft_strcmp_loop
  ret

ft_strcmp_exit_neg:
  neg rax
  ret

ft_strcmp_exit:
  mov al, 1
  jle ft_strcmp_exit_neg 
  ret

ft_strcmp_exit_zero:
  mov al, 0
  ret
