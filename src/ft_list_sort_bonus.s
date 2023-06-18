
global ft_list_sort

section .text
ft_list_sort:                    ; rdi = t_list **begin, rsi = int (*cmp)()
  enter 0, 0
  mov rdx, QWORD [rdi]           ; rdx = t_list *begin, rcx = t_list *current
  cmp rsi, 0
  jz ft_list_sort_ret

ft_list_sort_loop_begin:
  cmp rdx, 0                     ; if begin == NULL
  jz ft_list_sort_ret            ; return
  mov rcx, [rdx+8]               ; current = begin->next

ft_list_sort_loop_current:        
  cmp rcx, 0x0                   ; if current == NULL            
  jz ft_list_sort_loop_begin_end ; break
  push rdx
  push rcx
  push rdi
  push rsi
  mov rdi, [rdx]
  mov rsi, [rcx]
  call [rsp]                     ; int (*cmp)() => rdi = begin->data, rsi = current->data
  pop rsi
  pop rdi
  pop rcx
  pop rdx
  cmp rax, 0                     ; if return of int (*cmp)() > 0
  jg ft_list_sort_swap           ; jump handle sort

ft_list_sort_loop_current_end:
  mov rcx, [rcx+8]               ; current = current->next
  jmp ft_list_sort_loop_current

ft_list_sort_swap:
  mov r8, QWORD [rdx]
  mov r9, QWORD [rcx]
  mov [rdx], r9
  mov [rcx], r8
  jmp ft_list_sort_loop_current_end

ft_list_sort_loop_begin_end:
  mov rdx, [rdx+8]               ; begin = begin->next
  jmp ft_list_sort_loop_begin

ft_list_sort_ret:
  leave
  ret
