
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
  cmp byte [wspace+rsp], 0
  jz ft_atoi_is_wspace_exit_nofind
  cmp bl, byte [wspace+rsp]
  je ft_atoi_is_wspace_exit_find
  add rsp, 1
  jmp ft_atoi_check_is_wspace_loop

ft_atoi_check_is_wspace:
  enter 4, 0
  xor rax, rax
  mov bl, byte [rdi]
  jmp ft_atoi_check_is_wspace_loop


; =============== Atoi check base =============

ft_atoi_check_base_error:
  xor rax, rax
  mov rax, 0
  leave
  ret

;ft_atoi_check_base_loop:
;  

ft_atoi_check_base_syntax:
  enter 8, 0
  xor rax, rax
  call ft_atoi_check_is_wspace
  cmp rax, 1
  je ft_atoi_check_base_error
;  jmp ft_atoi_check_bas_syntaxe_loop
  mov rax, 1
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
  cmp rax, 1
  je ft_atoi_check_base_error
  leave
  ret
