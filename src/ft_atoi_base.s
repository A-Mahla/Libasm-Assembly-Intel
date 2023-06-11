
global ft_atoi_base
extern ft_strlen

section .data
  wspace db 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x20, 0x2B, 0x2D, 0x00

section .text
ft_atoi_base:
  push rbp
  mov rbp, rsp
  push rdi
  push rsi
  call ft_atoi_check_base
  pop rsi
  pop rdi
  pop rbp
  ret

;ft_atoi_is_wspace_exit:
;  pop rcx
;  mov rax, 1
;  ret
;
;ft_atoi_is_wspace_loop:
;  cmp byte [wspace+rcx], 0
;  cmp bl, byte [wspace+rcx]
;  je ft_atoi_check_base_error
;
;  
;
;ft_atoi_check_is_wspace:
;  mov bl, byte [rsi+rcx]
;  push rcx
;  xor rcx, rcx
;  jmp ft_atoi_is_wspace_loop
;
ft_atoi_check_base_error:
  xor rax, rax
  mov rax, 0
  ret

ft_atoi_check_base:
  mov rdi, rsi
  call ft_strlen
  cmp rax, 1
  jle ft_atoi_check_base_error
  ;xor rax, rax
  ;xor rcx, rcx
  ;jmp ft_atoi_check_base_loop
  ret
