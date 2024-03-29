
global ft_list_push_front
extern __errno_location
extern malloc

section .text

ft_list_push_front:             ; rdi = t_list **begin,  rsi = void *data
  enter 0, 0
  cmp rdi, 0x0                  ; check if begin == NULL
  je ft_list_push_front_error
  push rdi
  push rsi
  mov QWORD rdi, 16             ; sizeof(t_list *)
  call malloc
  pop rsi
  pop rdi
  cmp rax, 0x0                  ; if malloc failed
  jz ft_create_elem_error
  mov QWORD [rax], rsi          ; elem->data = data
  mov rcx, QWORD [rdi]
  mov QWORD [rax+8], rcx        ; elem->next = *begin
  mov QWORD [rdi], rax          ; *begin = elem
  leave
  ret

ft_list_push_front_error:
  leave
  ret

ft_create_elem_error:
  mov rcx, 12
  call __errno_location
  mov [rax], rcx
  leave
  ret
