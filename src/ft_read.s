
global ft_read
extern __errno_location

section .text
ft_read:
  push rbp
  mov rbp, rsp
  mov rax, 0
  syscall
  test rax, rax
  jge ft_read_success
  mov rbx, rax                     ; stock return value of read syscall un rbx
  call __errno_location WRT ..plt  ; calling to return pointer to errno location in rax
  mov [rax], rbx                   ; set errno with read syscall return value
  pop rbp
  ret

ft_read_success:
  pop rbp
  ret
