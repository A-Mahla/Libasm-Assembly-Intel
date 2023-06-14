
global ft_list_sort

section .text
ft_list_sort:              ; rdi = t_list **begin, rsi = int (*cmp)()
  enter 0, 0
  mov rbx, QWORD [rdi]     ; rbx = t_list *begin, rcx = t_list *current
  cmp rsi, 0
  jz ft_list_sort_ret

ft_list_sort_loop_begin:
  cmp rbx, 0
  jz ft_list_sort_ret
  mov rcx, [rbx+8]

  ft_list_sort_loop_current:
    cmp rcx, 0x0
    jz ft_list_sort_loop_begin_end
    push rbx
    push rcx
    push rdi
    push rsi
    mov rdi, [rbx]
    mov rsi, [rcx]
    call [rsp]            ; strcmp => rdi = elem, rsi = next
    pop rsi
    pop rdi
    pop rcx
    pop rbx
    cmp rax, 0            ; if return strcmp > 0
    jg ft_list_sort_swap  ; jump handle sort

  ft_list_sort_loop_current_end:
    mov rcx, [rcx+8]
    jmp ft_list_sort_loop_current

  ft_list_sort_swap:
    mov r8, QWORD [rbx]
    mov r9, QWORD [rcx]
    mov [rbx], r9
    mov [rcx], r8

ft_list_sort_loop_begin_end:
  mov rbx, [rbx+8]
  jmp ft_list_sort_loop_begin

ft_list_sort_ret:
  leave
  ret
