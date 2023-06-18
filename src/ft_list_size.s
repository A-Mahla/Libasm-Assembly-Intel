
global ft_list_size

section .text
ft_list_size:              ; rdi = t_list *begin
  enter 0, 0
  xor rax, rax

ft_list_size_loop:
  cmp rdi, 0x0             ; if begin = NULL
  je ft_list_size_ret
  inc rax                  ; i++
  mov rdi, QWORD [rdi+8]   ; begin = begin->next
  jmp ft_list_size_loop

ft_list_size_ret:
  leave
  ret
