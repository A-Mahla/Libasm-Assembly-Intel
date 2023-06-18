# Libasm - Libc implemented in Assembly Language
![mybadge](https://badgen.net/badge/SKILLS/%20ASSEMBLY,%20C,%20LINKED%20LISTS%20/red?scale=1.2)

#### This project is all about getting the basics of x86 assembly programming, by reimplementing a few libc and linked lists functions.


🔧 System Requirements:
   - Operating System: Linux 64_X86 Distribution
   - Software: [nasm](https://nasm.us/), [make](https://www.gnu.org/software/make/), [clang](https://clang.llvm.org/), 

## Usage
 
To run the command, open your terminal and follow these steps:

  - To create ```libasm.a```:
  
      ```shell
      cd /path/to/project/directory && make
      ```

  - To compile with ```libasm.a```:
  
      ```shell
      clang -o a.out *.o -I /path/to/project/directory/include -L /path/to/project/directory/include -lasm
      ```
      
   - To run Units Tests:

      ```shell
      cd /path/to/project/directory && make units && ./units
      ```


## Functions

- [ft_strlen](src/ft_strlen.s) - *man 3 strlen*
- [ft_strcpy](src/ft_strcpy.s) - *man 3 strcpy*
- [ft_strcmp](src/ft_strcmp.s) - *man 3 strcmp*
- [ft_write](src/ft_write.s) - *man 2 write*
- [ft_read](src/ft_read.s) - *man 2 read*
- [ft_strdup](src/ft_strdup.s) - *man 3 strdup*
- [ft_atoi_base](src/ft_atoi_base.s) - ```int ft_atoi_base(char *str, char *base);```
- [ft_list_push_front](src/ft_list_push_front.s) - ```void ft_list_push_front(t_list **begin, void data);```
- [ft_list_size](src/ft_list_size.s) - ```int ft_list_size(t_list *begin);```
- [ft_list_sort](src/ft_list_sort.s) - ```void ft_list_sort(t_list **begin, int (*cmp)());```
- [ft_list_remove_if](src/ft_list_remove_if.s) - ```void ft_list_remove_if(t_list **begin, void *data_ref, int (*cmp)(), void (*free_fct)(void *));```
