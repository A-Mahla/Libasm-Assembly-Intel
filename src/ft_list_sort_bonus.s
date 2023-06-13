
global ft_list_sort

section .text
ft_list_sort:              ; rdi = t_list **begin, rsi = int (*cmp)()
  enter 0, 0
  mov rbx, QWORD [rdi]     ; rbx = t_list *elem, rcx = t_list *prev, rdx = t_list *next
  mov QWORD rcx, 0
  cmp rbx, 0
  jz ft_list_sort_ret

ft_list_sort_loop:
  mov rdx, [rbx+8]
  cmp rdx, 0x0             ; if next = NULL
  je ft_list_sort_ret
  push rdi
  push rsi
  mov rdi, [rbx]
  mov rsi, [rdx]
  call [rsp]
  pop rsi
  pop rdi
  cmp rax, 0
  jg ft_list_sort_if_elem_greater
  mov rcx, rbx
  mov rbx, rdx   ; begin = begin->next
  jmp ft_list_sort_loop

ft_list_sort_if_elem_greater:
  mov r8, [rbx+8]
  mov r9, [rdx+8]
  mov [rdx+8], r8
  mov [rbx+8], r9
  cmp rcx, 0
  je ft_list_sort_if_prev_null
  mov QWORD [rbx+8], rdx

ft_list_sort_if_elem_greater_end
  mov rbx, [rdi]
  mov QWORD rcx, 0
  jmp ft_list_sort_loop

ft_list_sort_if_prev_null:
  mov QWORD [rdi], rdx
  jmp ft_list_sort_if_elem_greater_end

ft_list_sort_ret:
  leave
  ret
