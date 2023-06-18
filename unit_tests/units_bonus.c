
#include "libasm.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void    ftAtoiBaseTest( void ) {

  	printf("\t========== ft_atoi_base tests ===========\n\n");

//	printf(
//        "\t  ft_atoi_base(\"\", \"\")\t=>\t '%d' (return value)\n",
//        ft_atoi_base("", "")
//    );
//
//	printf(
//        "\t  ft_atoi_base(\"123\", \"0123456789\")\t=>\t '%d' (return value)\n",
//        ft_atoi_base("123", "0123456789")
//    );
//
//	printf(
//        "\t  ft_atoi_base(\"ffe0\", \"0123456789abcdef\")\t=>\t '%d' (return value)\n",
//        ft_atoi_base("ffe0", "0123456789abcdef")
//    );
//
//	printf(
//        "\t  ft_atoi_base(\"\\t\\n\\r\\v\\f\\r 4\", \"01234\")\t=>\t '%d' (return value)\n",
//        ft_atoi_base("\t\n\r\v\f\r 4", "01234")
//    );
//
	printf(
        "\t  ft_atoi_base(\"-+\\r++-+--ff\xff\", \"0123456789abcdef\")\t=>\t '%d' (return value)\n",
        ft_atoi_base("-+\r++-+--ff\xff", "0123456789abcdef")
    );

//	printf(
//        "\t  ft_atoi_base(\"7fffffff\", \"0123456789abcdef\")\t=>\t '%d' (return value)\n",
//        ft_atoi_base("7fffffff", "0123456789abcdef")
//    );

    char *str = "\t\n\r\v\f\r 4";
    char *base = "01234";
    int ret;

    ret = ft_atoi_base(str, base);
    printf("%d\n", ret);


}

t_list    *ftListPushFrontTest( void ) {

  t_list    *begin = NULL;
  char      *str[20] = {NULL};
  char      tmp[50];

  for ( size_t i = 0; i < 20; i++ ) {

    str[i] = malloc(50);
    if ( !str[i] ) {
      for ( size_t y = 0; str[y]; y++ )
        free(str[y]);
      return NULL;
    }
    sprintf(tmp, "Hi from %ld element to be entered in the list !", i + 1);
    memmove(str[i], tmp, ft_strlen(tmp) + 1);

  }

  for ( size_t i = 0; i < 20; i++ ) {
    ft_list_push_front(&begin, str[i]);
  }

  return begin;

}

void    printList( t_list *begin ) {


  printf("\n");
  while (begin) {
    printf("%s\n", (char *)begin->data);
    begin = begin->next;
  }
  printf("\n");

}

void    ftListSizeTest(t_list *begin) {

  printf("%d\n", ft_list_size(begin));
  printf("%d\n", ft_list_size(NULL));

}

void    ftListSortTest( t_list **begin ) {

  ft_list_sort(begin, &ft_strcmp);

}

void    ftListRemoveTest( t_list **begin ) {

	ft_list_remove_if(begin, "Hi from 1 element to be entered in the list !", &ft_strcmp, &free);
	ft_list_remove_if(begin, "Hi from 10 element to be entered in the list !", &ft_strcmp, &free);
	ft_list_remove_if(begin, "Hi from 20 element to be entered in the list !", &ft_strcmp, &free);
	ft_list_remove_if(begin, "Hi from 9 element to be entered in the list !", &ft_strcmp, &free);

}

void	freeList(t_list **begin) {

	t_list *tmp;

	while (*begin) {
		tmp = *begin;
		*begin = (*begin)->next;
		free(tmp->data);
		free(tmp);
	}

}


int     main(void) {

//  t_list    *begin = NULL;

  ftAtoiBaseTest();
//  begin = ftListPushFrontTest();
//  printList(begin);
//  ftListSizeTest(begin);
//  ftListSortTest(&begin);
//  printList(begin);
//  ftListRemoveTest(&begin);
//  printList(begin);
//  freeList(&begin);
  return 0;

}
// "\t\n\v\f\r +-
