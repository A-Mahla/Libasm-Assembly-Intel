
global ft_list_remove_if
extern free

section .text
ft_list_remove_if:        ; rdi = t_list **begin, rsi = void *data_ref, rdx = int (*cmp)(), rcx = void (*free_fct)(void *)
  enter 0, 0              ; r8 = t_list *prev, r9 = t_list *elem, r10 = t_list *next
  cmp rdx, 0x0
  je ft_list_remove_if_ret
  cmp rcx, 0x0
  je ft_list_remove_if_ret
  mov r9, QWORD [rdi]                           ; elem = *begin
  mov QWORD r8, 0                               ; prev = NULL


ft_list_remove_if_loop:
  cmp r9, 0x0                                   ; if next = NULL
  je ft_list_remove_if_ret
  push r8
  push r9
  push r10
  push rdi
  push rsi
  push rcx
  push rdx
  mov rdi, QWORD [r9]
  call [rsp]                                    ; call int (*cmp)() => rdi = elem->data, rsi = data_ref
  pop rdx
  pop rcx
  pop rsi
  pop rdi
  pop r10
  pop r9
  pop r8
  cmp rax, 0                                    ; if return of int (*cmp)() == 0 
  je ft_list_remove_if_equal
  mov QWORD r8, r9                              ; prev = elem
  mov QWORD r9, [r9+8]                          ; elem = elem->next
  jmp ft_list_remove_if_loop

ft_list_remove_if_equal:                        ; if int (*cmp)() == 0
  mov r10, [r9+8]                               ; next = elem->next
  push r8
  push r10
  push rdi
  push rsi
  push rdx
  push r9
  push rcx
  mov rdi, QWORD [r9]
  call [rsp]                                    ; call void (*free_fct)(void *) => rdi = elem->data
  mov rdi, QWORD [rsp+8]
  call free                                     ; call free => rdi = elem->data (rsp+8 == r9)
  pop rcx
  pop r9
  pop rdx
  pop rsi
  pop rdi
  pop r10
  pop r8
  mov r9, r10                                   ; elem = next
  cmp r8, 0                                     ; if prev == NULL
  je ft_list_remove_if_prev_null
  mov QWORD [r8+8], r9                          ; prev->next = elem
  jmp ft_list_remove_if_loop

ft_list_remove_if_prev_null:
  mov QWORD [rdi], r9                           ; *begin = elem
  jmp ft_list_remove_if_loop

ft_list_remove_if_ret:
  leave
  ret
