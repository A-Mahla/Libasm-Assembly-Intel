
global ft_write
extern __errno_location

section .text
ft_write:                          ; rdi = int fildes, rsi = void *buf, rdx = size_t nbyte
  push rbp
  mov rbp, rsp
  mov rax, 1
  syscall
  test rax, rax
  jge ft_write_success
  neg rax                          ; get the positive value of write return
  mov rcx, rax                     ; stock return value of write syscall in rbx
  call __errno_location            ; calling to return pointer to errno location in rax
  mov [rax], rcx                   ; set errno with write syscall return value
  mov QWORD rax, -1
  pop rbp
  ret

ft_write_success:
  pop rbp
  ret
