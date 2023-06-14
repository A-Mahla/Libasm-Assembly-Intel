
global ft_atoi_base
extern ft_strlen

section .data
  wspace: db 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x20, 0x2B, 0x2D, 0x00

section .text

; ========== entrypoint ===============

ft_atoi_base:                       ; rdi = char *str, rsi = char *base
  enter 0, 0
  cmp rdi, 0x0
  je ft_atoi_base_error
  cmp rsi, 0x0
  je ft_atoi_base_error
  push rdi
  push rsi
  mov rdi, rsi
  mov rsi, wspace
  call ft_atoi_check_base
  pop rsi
  pop rdi
  mov QWORD r8, 0
  mov QWORD r9, 1
  cmp rax, 0
  je ft_atoi_base_error
  call ft_atoi_compute_result
  leave
  ret

; ==================== boolean ret tools =================

ft_atoi_base_error:
  xor rax, rax
  mov rax, 0
  leave
  ret

ft_atoi_base_success:
  xor rax, rax
  mov rax, 1
  leave
  ret

; =========== is in string (white-space / base) ==========

ft_atoi_check_is_in_string:
  enter 8, 0
  xor rax, rax
  mov QWORD [rsp], 0
  mov r10b, BYTE [rdi]           ; continue to next function

ft_atoi_check_is_in_string_loop:
  mov rax, [rsp]
  cmp BYTE [rsi+rax], 0
  jz ft_atoi_is_in_string_exit_nofind
  cmp r10b, BYTE [rsi+rax]
  je ft_atoi_is_in_string_exit_find
  add DWORD [rsp], 1
  jmp ft_atoi_check_is_in_string_loop

ft_atoi_is_in_string_exit_find:
  leave
  ret

ft_atoi_is_in_string_exit_nofind:
  mov QWORD rax, -1
  leave
  ret

; =============== Atoi check base =============

ft_atoi_check_base:
  enter 8, 0
  push rdi
  call ft_strlen
  pop rdi
  cmp rax, 1
  jle ft_atoi_base_error
  xor rax, rax
  mov QWORD [rsp], rdi           ; continue to next function

ft_atoi_check_base_syntax_wspace_loop:
  mov r10b, BYTE [rdi]
  cmp r10b, 0
  jz ft_atoi_check_base_middle
  call ft_atoi_check_is_in_string
  cmp rax, -1
  jne ft_atoi_base_error
  inc rdi
  jmp ft_atoi_check_base_syntax_wspace_loop

ft_atoi_check_base_middle:
  mov rdi, QWORD [rsp]
  mov QWORD rcx, 1               ; continue to next function

ft_atoi_check_base_syntax_unique_loop:
  mov r10b, BYTE [rdi]
  cmp r10b, 0
  jz ft_atoi_base_success
  mov dl, BYTE [rdi+rcx]
  cmp r10b, dl
  je ft_atoi_base_error
  inc rcx
  cmp BYTE [rdi+rcx], 0
  jne ft_atoi_check_base_syntax_unique_loop
  mov QWORD rcx, 1
  inc rdi
  jmp ft_atoi_check_base_syntax_unique_loop

; =========== Compute result =============

ft_atoi_compute_result:
  enter 8, 0
  xor rcx, rcx
  push rsi
  mov rsi, wspace        ; continue to next function

ft_atoi_compute_result_while_wspace:
  cmp BYTE [rdi], 0
  je ft_atoi_compute_result_middle
  call ft_atoi_check_is_in_string
  cmp rax, -1
  je ft_atoi_compute_result_middle
  mov r10b, BYTE [rdi]
  inc rdi
  cmp r10b, '-'
  jne ft_atoi_compute_result_while_wspace
  imul r9, -1
  jmp ft_atoi_compute_result_while_wspace

ft_atoi_compute_result_middle:
  pop rsi                   ; contine to next function

ft_atoi_compute_result_final_loop:
  cmp BYTE [rdi], 0
  je ft_atoi_base_final
  call ft_atoi_check_is_in_string
  cmp rax, -1
  je ft_atoi_base_final
  mov QWORD [rsp], rax
  xchg rdi, rsi
  call ft_strlen
  xchg rdi, rsi
  imul r8, rax
  add r8, QWORD [rsp]
  inc rdi
  jmp ft_atoi_compute_result_final_loop

ft_atoi_base_final:
  imul r8, r9
  mov QWORD rax, r8
  leave
  ret
