
global ft_write
extern __errno_location

section .text
ft_write:
  push rbp
  mov rbp, rsp
  mov rax, 1
  syscall
  test rax, rax
  jge ft_write_success
  mov rbx, rax                     ; stock return value of write syscall in rbx
  call __errno_location WRT ..plt  ; calling to return pointer to errno location in rax
  mov [rax], rbx                   ; set errno with write syscall return value
  pop rbp
  ret

ft_write_success:
  pop rbp
  ret
