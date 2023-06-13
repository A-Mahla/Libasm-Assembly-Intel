
global ft_list_sort

section .text
ft_list_sort:              ; rdi = t_list **begin, rsi = int (*cmp)()
  enter 0, 0
  mov rbx, QWORD [rdi]     ; rbx = t_list *elem, rcx = t_list *prev, rdx = t_list *next
  mov QWORD rbx, 0x0
  cmp rbx, 0
  jz ft_list_sort_ret

ft_list_sort_loop:
  mov rdx, [rbx+8]
  cmp rdx, 0x0             ; if next = NULL
  je ft_list_sort_ret
  push rdi
  push rsi
  mov rdi, rbx
  mov rsi, rcx
  call rcx
  pop rsi
  pop rdi
  cmp rax, 0
  jg ft_list_sort_if_elem_greater
  mov rcx, rax
  mov rax, QWORD [rax+8]   ; begin = begin->next
  jmp ft_list_sort_loop

ft_list_sort_if_elem_greater:
  jmp ft_list_sort_loop

ft_list_sort_ret:
  leave
  ret
