#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


void    ftStrlenTest( void ) {

	printf("\t========== ft_strlen tests ===========\n\n");

	printf(
        "\t  ft_strlen(\"123456789l\")\t=>\t '%zu' (return value)\n",
        ft_strlen("123456789l")
    );
	printf(
        "\t  strlen(\"123456789l\")\t\t=>\t '%zu' (return value)\n\n",
        strlen("123456789l")
    );

	printf("\t  ft_strlen(\"\")\t\t\t=>\t '%zu' (return value)\n", ft_strlen(""));
	printf("\t  strlen(\"\")\t\t\t=>\t '%zu' (return value)\n\n", strlen(""));

	printf(
        "\t  ft_strlen(\"\\xff\\xff\\xff\\xff\")\t=>\t '%zu' (return value)\n",
        ft_strlen("\xff\xff\xff\xff")
    );
	printf(
        "\t  strlen(\"\\xff\\xff\\xff\\xff\")\t=>\t '%zu' (return value)\n\n",
        strlen("\xff\xff\xff\xff")
    );

	printf("\n\n");
}


void    ftStrcpyTest( void ) {

	printf("\t========== ft_strcpy tests ===========\n\n");

	char dst[20] = {0};

	printf(
        "\t  ft_strcpy(dst, \"123456789l\")\t=>\t '%s' (return value) / '%s' (dst value)\n",
        ft_strcpy(dst, "123456789l"),
        dst
    );
	bzero(dst, 20);

	printf(
        "\t  strcpy(dst, \"123456789l\")\t=>\t '%s' (return value) / '%s' (dst value)\n\n",
        strcpy(dst, "123456789l"),
        dst
    );
	bzero(dst, 20);

	printf(
        "\t  ft_strcpy(dst, \"\")\t\t=>\t '%s' (return value) / '%s' (dst value)\n",
        ft_strcpy(dst, ""),
        dst
    );
	bzero(dst, 20);

	printf(
        "\t  strcpy(dst, \"\")\t\t=>\t '%s' (return value) / '%s' (dst value)\n\n", 
        ft_strcpy(dst, ""),
        dst
    );
	bzero(dst, 20);

	printf(
        "\t  ft_strcpy(dst, \"\\xff\")\t=>\t '%#x' (return value) / '%#x' (dst value)\n",
        ft_strcpy(dst, "\xff")[0]
        ,dst[0]
    );
	bzero(dst, 20);

	printf(
        "\t  strcpy(dst, \"\\xff\")\t\t=>\t '%#x' (return value) / '%#x' (dst value)\n\n",
        strcpy(dst, "\xff")[0],
        dst[0]
    );
	bzero(dst, 20);

	printf("\n\n");

}


void    ftStrcmpTest( void ) {

	printf("\t========== ft_strcmp tests ===========\n\n");

	printf("\t  ft_strcmp(\"\", \"\")\t=>\t '%d' (return value)\n", ft_strcmp("", ""));
	printf("\t  strcmp(\"\", \"\")\t=>\t '%d' (return value)\n\n", strcmp("", ""));

	printf(
        "\t  ft_strcmp(\"asdklfjasdfj////asdf'''asdf3##\", \"\")\t=>\t '%d' (return value)\n",
        ft_strcmp("asdklfjasdfj////asdf'''asdf3##", "")
    );
	printf(
        "\t  strcmp(\"asdklfjasdfj////asdf'''asdf3##\", \"\")\t\t=>\t '%d' (return value)\n\n",
        strcmp("asdklfjasdfj////asdf'''asdf3##", "")
    );

	printf(
        "\t  ft_strcmp(\"\", \"asdklfjasdfj////asdf'''asdf3##\")\t=>\t '%d' (return value)\n",
        ft_strcmp("", "asdklfjasdfj////asdf'''asdf3##")
    );
	printf(
        "\t  strcmp(\"\", \"asdklfjasdfj////asdf'''asdf3##\")\t\t=>\t '%d' (return value)\n\n",
        strcmp("", "asdklfjasdfj////asdf'''asdf3##")
    );

	printf(
        "\t  ft_strcmp(\"Hello World\", \"Hello WOrld\")\t=>\t '%d' (return value)\n",
        ft_strcmp("Hello World", "Hello WOrld")
    );
	printf(
        "\t  strcmp(\"Hello World\", \"Hello WOrld\")\t\t=>\t '%d' (return value)\n\n",
        strcmp("Hello World", "Hello WOrld")
    );

	printf(
        "\t  ft_strcmp(\"Hello WOrld\", \"Hello World\")\t=>\t '%d' (return value)\n",
        ft_strcmp("Hello WOrld", "Hello World")
    );
	printf(
        "\t  strcmp(\"Hello WOrld\", \"Hello World\")\t\t=>\t '%d' (return value)\n\n",
        strcmp("Hello WOrld", "Hello World")
    );

	printf(
        "\t  ft_strcmp(\"Hello World\", \"Hello World\")\t=>\t '%d' (return value)\n",
        ft_strcmp("Hello World", "Hello World")
    );
	printf(
        "\t  strcmp(\"Hello World\", \"Hello World\")\t\t=>\t '%d' (return value)\n\n",
        strcmp("Hello World", "Hello World")
    );

}


void    ftStrdupTest( void ) {

    printf("\t========== ft_strdup tests ===========\n\n");

	char *dst;

	printf(
        "\t  ft_strdup(\"123456789l\")\t=>\t '%s' (return value)\n",
        (dst = ft_strdup("123456789l"))
    );
	free(dst);
	printf(
        "\t  strdup(\"123456789l\")\t\t=>\t '%s' (return value)\n\n",
        (dst = strdup("123456789l"))
    );
	free(dst);

	printf(
        "\t  ft_strdup(\"\")\t\t\t=>\t '%s' (return value)\n",
        (dst = ft_strdup(""))
    );
	free(dst);
	printf(
        "\t  strdup(\"\")\t\t\t=>\t '%s' (return value)\n\n",
        (dst = strdup(""))
    );
	free(dst);

	printf(
        "\t  ft_strdup(\"\\xff\")\t\t=>\t '%#x' (return value)\n",
        (dst = ft_strdup("\xff"))[0]
    );
	free(dst);
	printf(
        "\t  strdup(\"\\xff\")\t\t=>\t '%#x' (return value)\n\n",
        (dst = strdup("\xff"))[0]
    );
	free(dst);

	printf("\n\n");

}


void    ftWriteTest( void ) {


	printf("\t========== ft_write tests ===========\n\n");

    write(1, "\t  \"", 4);
	printf(
        "\"\t=> ft_write(1, \"Salut  \", 7)\t/  '%ld' (return value)\t/  ERRNO = %d\n",
        ft_write(1, "Salut  ",7),
        errno
    );
    write(1, "\t  \"", 4);
	printf(
        "\"\t=> write(1, \"Salut  \", 7)\t/  '%ld' (return value)\t/  ERRNO = %d\n\n",
        write(1, "Salut  ",7),
        errno
    );

    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> ft_write(2, \"Salut  \", 3)\t/  '%ld' (return value)\t/  ERRNO = %d\n",
        ft_write(2, "Salut  ", 3),
        errno
    );
    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> write(2, \"Salut  \", 3)\t/  '%ld' (return value)\t/  ERRNO = %d\n\n",
        write(2, "Salut  ", 3),
        errno
    );

    write(1, "\t  \"", 4);
	printf(
        "\"\t=> ft_write(2, \"Salut  \", 8)\t/  '%ld' (return value)\t/  ERRNO = %d\n",
        ft_write(2, "Salut  ", 8),
        errno
    );
    write(1, "\t  \"", 4);
	printf(
        "\"\t=> write(2, \"Salut  \", 8)\t/  '%ld' (return value)\t/  ERRNO = %d\n\n",
        write(2, "Salut  ", 8),
        errno
    );

    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> ft_write(2, \"Salut  \", 0)\t/  '%ld' (return value)\t/  ERRNO = %d\n",
        ft_write(2, "Salut  ", 0),
        errno
    );
    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> write(2, \"Salut  \", 0)\t/  '%ld' (return value)\t/  ERRNO = %d\n\n",
        write(2, "Salut  ", 0),
        errno
    );

    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> ft_write(1, \"Salut  \", -1)\t/  '%ld' (return value)\t/  ERRNO = %d\n",
        ft_write(1, "Salut  ", -1),
        errno
    );
    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> write(1, \"Salut  \", -1)\t/  '%ld' (return value)\t/  ERRNO = %d\n\n",
        write(1, "Salut  ", -1),
        errno
    );

    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> ft_write(-1, \"Salut  \", 7)\t/  '%ld' (return value)\t/  ERRNO = %d\n",
        ft_write(-1, "Salut  ",7),
        errno
    );
    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> write(-1, \"Salut  \", 7)\t/  '%ld' (return value)\t/  ERRNO = %d\n\n",
        write(-1, "Salut  ",7),
        errno
    );

    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> ft_write(2, NULL, 7)\t/  '%ld' (return value)\t/  ERRNO = %d\n",
        ft_write(2, NULL,7),
        errno
    );
    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> write(2, NULL, 7)\t/  '%ld' (return value)\t/  ERRNO = %d\n\n",
        write(2, NULL,7),
        errno
    );

}


void    ftReadTest( void ) {

    char buf[10];
    int fd = open("Makefile", O_RDONLY);
    read(fd, buf, 2);
    errno = 0;

    printf("\t========== ft_read tests ===========\n\n");


    buf[7] = '\0';
	printf(
        "\t  ft_read(fd, buf, 7)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n",
        ft_read(fd, buf,7),
        buf,
        errno
    );
	printf(
        "\t  read(fd, buf, 7)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n\n",
        read(fd, buf,7),
        buf,
        errno
    );

    buf[3] = '\0';
	printf(
        "\t  ft_read(fd, buf, 3)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n",
        ft_read(fd, buf, 3),
        buf,
        errno
    );
	printf(
        "\t  read(fd, buf, 3)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n\n",
        read(fd, buf, 3),
        buf,
        errno
    );

    buf[8] = '\0';
	printf(
        "\t  ft_read(fd, buf, 8)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n",
        ft_read(fd, buf, 8),
        buf,
        errno
    );
	printf(
        "\t  read(fd, buf, 8)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n\n",
        read(fd, buf, 8),
        buf,
        errno
    );

    buf[0] = '\0';
	printf(
        "\t  ft_read(fd, buf, 0)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n",
        ft_read(fd, buf, 0),
        buf,
        errno
    );
	printf(
        "\t  read(fd, buf, 0)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n\n",
        read(fd, buf, 0),
        buf,
        errno
    );

	printf(
        "\t  ft_read(fd, buf, -1)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n",
        ft_read(fd, buf, -1),
        buf,
        errno
    );
	printf(
        "\t  read(fd, buf, -1)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n\n",
        read(fd, buf, -1),
        buf,
        errno
    );

	printf(
        "\t  ft_read(-1, buf, 7)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n",
        ft_read(-1, buf,7),
        buf,
        errno
    );
	printf(
        "\t  read(-1, buf, 7)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n\n",
        read(-1, buf,7),
        buf,
        errno
    );

	printf(
        "\t  ft_read(fd, NULL, 7)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n",
        ft_read(fd, NULL,7),
        buf,
        errno
    );
	printf(
        "\t  read(fd, NULL, 7)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n\n",
        read(fd, NULL,7),
        buf,
        errno
    );

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
  printf("\t*** be free to use these functions with your tests !\n");
  printf("\t***  Compile usage:\n\t***    clang -o a.out *.o -L /path/to/libasm.a/ -lasm\n\n");

  freeList(begin);

}


int     main(void) {

  t_list    *begin = NULL;

  printf("\n");

  ftStrlenTest();
  ftStrcpyTest();
  ftStrcmpTest();
  ftStrdupTest();
  ftWriteTest();
  ftReadTest();
  ftAtoiBaseTest();
  begin = ftListPushFrontTest();
  ftListSizeTest(begin);
  ftListSortTest(&begin);
  ftListRemoveTest(&begin);
  return 0;

}
