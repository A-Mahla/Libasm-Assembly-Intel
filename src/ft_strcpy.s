
global ft_strcpy

global .text

ft_strcpy:               ; rdi = char *dest, rsi = char *src
  push rbp
  mov rbp, rsp
  mov rax, rdi

ft_strcpy_loop:
  mov cl, BYTE [rsi]          ; see Note
  mov BYTE [rdi], cl
  cmp byte [rdi], 0x0
  jz ft_strcpy_ret
  inc rdi
  inc rsi
  jmp ft_strcpy_loop

ft_strcpy_ret
  pop rbp
  ret

; Note: in assembly you cannot assign directly an indirect value pointed
;       by a register with an indirect value pointed by another register
;       Example:
;          You can't do => *a = *b
;          You have to do => c = *b && *a = c
