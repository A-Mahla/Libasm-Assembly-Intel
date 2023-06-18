
#include "libasm.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	freeList(t_list **begin) {

	t_list *tmp;

	while (*begin) {
		tmp = *begin;
		*begin = (*begin)->next;
		free(tmp->data);
		free(tmp);
	}

}

void    printList( t_list *begin ) {

  int i = 1;

  printf("\n");
  while (begin) {
    printf("\t      Element %2d  =>\t%s\n", i, (char *)begin->data);
    begin = begin->next;
    i++;
  }
  printf("\n");

}

void    ftAtoiBaseTest( void ) {

//  White Space "\t\n\v\f\r +-

  	printf("\n\t========== ft_atoi_base tests ===========\n\n");

	printf(
        "\t  ft_atoi_base(\"\", \"\")\t\t\t\t\t=>\t '%d' (return value)\n",
        ft_atoi_base("", "")
    );

	printf(
        "\t  ft_atoi_base(\"123\", \"0123456789\")\t\t\t=>\t '%d' (return value)\n",
        ft_atoi_base("123", "0123456789")
    );

	printf(
        "\t  ft_atoi_base(\"-ffe0\", \"0123456789abcdef\")\t\t=>\t '%d' (return value)\n",
        ft_atoi_base("-ffe0", "0123456789abcdef")
    );

	printf(
        "\t  ft_atoi_base(\"\\t\\n\\r\\v\\f\\r 4\", \"01234\")\t\t=>\t '%d' (return value)\n",
        ft_atoi_base("\t\n\r\v\f\r 4", "01234")
    );

	printf(
        "\t  ft_atoi_base(\"-+\\r++-+--ff\xff\", \"0123456789abcdef\")\t=>\t '%d' (return value)\n",
        ft_atoi_base("-+\r++-+--ff\xff", "0123456789abcdef")
    );

	printf(
        "\t  ft_atoi_base(\"7fffffff\", \"0123456789abcdef\")\t\t=>\t '%d' (return value)\n",
        ft_atoi_base("7fffffff", "0123456789abcdef")
    );

	printf(
        "\t  ft_atoi_base(\"80000000\", \"0123456789abcdef\")\t\t=>\t '%d' (return value)\n",
        ft_atoi_base("80000000", "0123456789abcdef")
    );


}

t_list    *ftListPushFrontTest( void ) {

  t_list    *begin = NULL;
  char      *str[20] = {NULL};
  char      tmp[50];

  printf("\n\t========== Testing Linked List Functions ===========\n\n");

  printf("\t  Setting begin list to NULL => 't_list *begin = NULL'\n");

  printf("\n\t  ========== ft_list_push_front tests ===========\n\n");

  printf("\t    List 'begin' after 20 elements pushed front :\n");

  for ( size_t i = 0; i < 20; i++ ) {

    str[i] = malloc(50);
    if ( !str[i] ) {
      for ( size_t y = 0; str[y]; y++ )
        free(str[y]);
      return NULL;
    }
    sprintf(tmp, "Hi from %2ld element to be entered in the list !", i + 1);
    memmove(str[i], tmp, ft_strlen(tmp) + 1);

  }

  for ( size_t i = 0; i < 20; i++ ) {
    ft_list_push_front(&begin, str[i]);
  }

  printList(begin);

  return begin;

}



void    ftListSizeTest(t_list *begin) {

  printf("\n\t  ========== ft_list_size tests ===========\n\n");

  printf("\t    ft_list_size(begin)\t=> %d (return value)\n", ft_list_size(begin));
  printf("\t    ft_list_size(NULL)\t=> %d (return value)\n\n", ft_list_size(NULL));

}

void    ftListSortTest( t_list **begin ) {

  printf("\n\t  ========== ft_list_sort tests ===========\n\n");
  printf("\t    Sorting 'begin' list with ft_strcmp as 'int (*cmp)()' argument ...\n");
  ft_list_sort(begin, &ft_strcmp);
  printList(*begin);

}

void    ftListRemoveTest( t_list **begin ) {

  printf("\n\t  ========== ft_list_sort tests ===========\n\n");
  printf("\t    Remove elements from list 'begin' with ft_strcmp as 'int (*cmp)()' argument and free as 'void (*free_fct) argument ...\n\n");
  printf("\t    ... removing element with 'data': \"Hi from  1 element to be entered in the list !\"\n");
  printf("\t    ... removing element with 'data': \"Hi from 10 element to be entered in the list !\"\n");
  printf("\t    ... removing element with 'data': \"Hi from 20 element to be entered in the list !\"\n");
  printf("\t    ... removing element with 'data': \"Hi from  9 element to be entered in the list !\"\n\n");

  ft_list_remove_if(begin, "Hi from  1 element to be entered in the list !", &ft_strcmp, &free);
  ft_list_remove_if(begin, "Hi from 10 element to be entered in the list !", &ft_strcmp, &free);
  ft_list_remove_if(begin, "Hi from 20 element to be entered in the list !", &ft_strcmp, &free);
  ft_list_remove_if(begin, "Hi from  9 element to be entered in the list !", &ft_strcmp, &free);
  printf("\t    Actual state of 'begin' list :\n");
  printList(*begin);

  printf("\t============ End Linked List Functions Testing =============\n\n");
  printf("\t*** be free to use these function with yours tests !\n");
  printf("\t***  Compiling usage:\n\t***    clang -o a.out *.o -L /path/to/libasm.a/ -lasm\n\n");

  freeList(begin);

}


int     main(void) {

  t_list    *begin = NULL;

  ftAtoiBaseTest();
  begin = ftListPushFrontTest();
  ftListSizeTest(begin);
  ftListSortTest(&begin);
  ftListRemoveTest(&begin);
  return 0;

}

