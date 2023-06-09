# Libasm - Libc implemented in Assembly Language
![mybadge](https://badgen.net/badge/SKILLS/%20ASSEMBLY,%20C,%20LINKED%20LISTS%20/red?scale=1.2)

#### This project is all about getting the basics of x86 assembly programming, by reimplementing a few libc and linked lists functions.


🔧 System Requirements:
   - Operating System: Linux 64_X86 Distribution
   - Software: [nasm](https://nasm.us/), [make](https://www.gnu.org/software/make/)

## Usage
 
To run the command, open your terminal and follow these steps:

  - To create ```libasm.a```:
  
      ```shell
      cd /path/to/project/directory && make
      ```
      
   - To run Units Tests:

      ```shell
      cd /path/to/project/directory && make units && ./units
      ```


## Functions

- [ft_strlen](libasm/src/ft_strlen.s) - *man 3 strlen*
- [ft_strcpy](libasm/src/ft_strcpy.s) - *man 3 strcpy*
- [ft_strcmp](libasm/src/ft_strcmp.s) - *man 3 strcmp*
- [ft_write](libasm/src/ft_write.s) - *man 2 write*
- [ft_read](libasm/src/ft_read.s) - *man 2 read*
- [ft_strdup](libasm/src/ft_strdup.s) - *man 3 strdup*
- [ft_atoi_base](libasm/src/ft_atoi_base_bonus.s) - ```int ft_atoi_base(char *str, char *base);```
- [ft_list_push_front](libasm/src/ft_list_push_front_bonus.s) - ```void ft_list_push_front(t_list **, void \data);```
- [ft_list_size](libasm/src/ft_list_size_bonus.s) - ```int ft_list_size(t_list *);```
- [ft_list_sort](libasm/src/ft_list_sort_bonus.s) - ```void ft_list_sort(t_list **, int (*cmp)());```
- [ft_list_remove_if](libasm/src/ft_list_remove_if_bonus.s) - ```void ft_list_remove_if(t_list **, void *data_ref, int (*cmp)(void *,void *), void (*free_fn)(void *));```
