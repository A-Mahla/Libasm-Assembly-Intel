
global ft_list_sort

section .text
ft_list_sort:              ; rdi = t_list **begin, rsi = int (*cmp)()
  enter 0, 0
  mov rax, QWORD [rdi]     ; rax = t_list *elem, rbx = t_list *prev, rcx = t_list *next
  mov QWORD rbx, 0x0
  cmp rax, 0
  jz ft_list_sort_ret

ft_list_sort_loop:
  mov rdx, [rax+8]
  cmp rdx, 0x0             ; if next = NULL
  je ft_list_sort_ret
  inc rax                  ; i++
  mov rdi, QWORD [rdi+8]   ; begin = begin->next
  jmp ft_list_sort_loop

ft_list_sort_ret:
  leave
  ret
