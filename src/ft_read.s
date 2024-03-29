
global ft_read
extern __errno_location

section .text
ft_read:                           ; rdi = int fildes, rsi = void *buf, rdx = size_t nbyte
  push rbp
  mov rbp, rsp
  mov rax, 0
  syscall
  test rax, rax
  jge ft_read_success
  neg rax                          ; get the positive value of read return
  mov rcx, rax                     ; stock return value of read syscall in rbx
  call __errno_location            ; calling to return pointer to errno location in rax
  mov [rax], rcx                   ; set errno with read syscall return value
  mov QWORD rax, -1
  pop rbp
  ret

ft_read_success:
  pop rbp
  ret
