
global ft_strcpy

global .text

ft_strcpy:
  push rbp
  mov rbp, rsp
  mov rax, rdi
  call ft_strcpy_loop
  pop rbp
  ret

ft_strcpy_inc:
  inc rdi
  inc rsi
  jmp ft_strcpy_loop

ft_strcpy_loop:
  mov bl, [rsi]          ; see Note
  mov [rdi], bl
  cmp byte [rdi], 0x0
  jnz ft_strcpy_inc
  ret

; Note: in assembly you cannot assign directly an indirect value pointed
;       by a register with an indirect value pointed by another register
;       Example:
;          You can't do => *a = *b
;          You have to do => c = *b && *a = c
