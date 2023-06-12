
global ft_atoi_base
extern ft_strlen

section .data
  wspace: db 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x20, 0x2B, 0x2D, 0x00

section .text

; ========== entrypoint ===============

ft_atoi_base:
  enter 0, 0
  push rdi
  push rsi
  mov rdi, rsi
  call ft_atoi_check_base
  pop rsi
  pop rdi
  leave
  ret

ft_ret:
  ret

; =========== is white space ==========

ft_atoi_is_wspace_exit_find:
  mov rax, 1
  leave
  ret

ft_atoi_is_wspace_exit_nofind:
  mov rax, 0
  leave
  ret

ft_atoi_check_is_wspace_loop:
  mov rax, [rsp]
  cmp BYTE [wspace+rax], 0
  jz ft_atoi_is_wspace_exit_nofind
  cmp bl, BYTE [wspace+rax]
  je ft_atoi_is_wspace_exit_find
  add DWORD [rsp], 1
  jmp ft_atoi_check_is_wspace_loop

ft_atoi_check_is_wspace:
  enter 8, 0
  xor rax, rax
  mov QWORD [rsp], 0
  mov bl, BYTE [rdi]
  jmp ft_atoi_check_is_wspace_loop


; =============== Atoi check base =============

ft_atoi_check_base_error:
  xor rax, rax
  mov rax, 0
  leave
  ret

ft_atoi_check_base_success:
  xor rax, rax
  mov rax, 1
  leave
  ret

ft_atoi_check_base_syntax_unique_loop:
  mov bl, BYTE [rdi]
  cmp bl, 0
  jz ft_atoi_check_base_success
  mov dl, BYTE [rdi+ecx]
  cmp bl, dl
  je ft_atoi_check_base_error
  cmp dl, 0
  cmovz ecx, 1
  cmovz rdi, rdi+1
  jmp ft_atoi_check_base_syntax_unique_loop:

ft_atoi_check_base_syntax_wspace_loop:
  mov bl, BYTE [rdi]
  cmp bl, 0
  jz ft_ret
  call ft_atoi_check_is_wspace
  cmp rax, 1
  je ft_atoi_check_base_error
  inc rdi
  jmp ft_atoi_check_base_syntax_loop

ft_atoi_check_base_syntax_loop:
  enter 0, 0
  push rdi
  call ft_atoi_check_base_syntax_wspace_loop
  pop rdi
  mov QWORD rcx, 1
  jmp ft_atoi_check_base_syntax_unique_loop


ft_atoi_check_base_syntax:
  enter 0, 0
  xor rax, rax
  call ft_atoi_check_base_syntax_loop
  cmp rax, 1
  je ft_atoi_check_base_error
  mov rax, 1
  jmp ft_atoi_check_base_syntax_loop
  leave
  ret

ft_atoi_check_base:
  enter 0, 0
  push rdi
  call ft_strlen
  pop rdi
  cmp rax, 1
  jle ft_atoi_check_base_error
  push rdi
  call ft_atoi_check_base_syntax
  pop rdi
  cmp rax, 0
  je ft_atoi_check_base_error
  leave
  ret
