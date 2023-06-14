
global ft_list_sort

section .text
ft_list_sort:              ; rdi = t_list **begin, rsi = int (*cmp)()
  enter 0, 0
  mov rdx, QWORD [rdi]     ; rdx = t_list *begin, rcx = t_list *current
  cmp rsi, 0
  jz ft_list_sort_ret

ft_list_sort_loop_begin:
  cmp rdx, 0
  jz ft_list_sort_ret
  mov rcx, [rdx+8]

ft_list_sort_loop_current:
  cmp rcx, 0x0
  jz ft_list_sort_loop_begin_end
  push rdx
  push rcx
  push rdi
  push rsi
  mov rdi, [rdx]
  mov rsi, [rcx]
  call [rsp]            ; strcmp => rdi = elem, rsi = next
  pop rsi
  pop rdi
  pop rcx
  pop rdx
  cmp rax, 0            ; if return strcmp > 0
  jg ft_list_sort_swap  ; jump handle sort

ft_list_sort_loop_current_end:
  mov rcx, [rcx+8]
  jmp ft_list_sort_loop_current

ft_list_sort_swap:
  mov r8, QWORD [rdx]
  mov r9, QWORD [rcx]
  mov [rdx], r9
  mov [rcx], r8
  jmp ft_list_sort_loop_current_end

ft_list_sort_loop_begin_end:
  mov rdx, [rdx+8]
  jmp ft_list_sort_loop_begin

ft_list_sort_ret:
  leave
  ret
