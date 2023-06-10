global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc
extern __errno_location

section .text

ft_strdup:
  push rbp
  mov rbp, rsp
  push rdi                          ; push on the Stack value of 1st arg of ft_strdup to reuse it later
  call ft_strlen
  mov rdi, rax                      ; move return ft_strlen function in 1rst arg (size of alloc) of malloc 
  call malloc WRT ..plt
  cmp rax, 0x0                      ; check if return pointer by malloc is NULL
  jz ft_strdup_null
  mov rdi, rax                      ; move return of malloc in 2nd argument of ft_strcpy
  pop rsi                           ; pop value from the Stack of 1st arg of strdup in 1st arg of ft_strcpy
  call ft_strcpy
  pop rbp
  ret

ft_strdup_null:
  push rax                          ; push pointer NULL on the Stack in rax to reuse rax
  mov rbx, 12                       ; move value of errno : ENOMEM == 12 in rbx register
  call __errno_location WRT ..plt
  mov [rax], rbx                    ; move ENONEM errno value in errno variable
  pop rax                           ; retrieve return value of ft_strdup in rax register
  pop rdi
  pop rbp
  ret
