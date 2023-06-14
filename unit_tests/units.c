#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>


void    ftStrcpyTest( void ) {

	printf("\t========== ft_strcpy tests ===========\n\n");

	char dst[20] = {0};

	printf("\t  ft_strcpy(dst, \"123456789l\")\t=>\t '%s' (dst value)\n", ft_strcpy(dst, "123456789l"));
	bzero(dst, 20);
	printf("\t  strcpy(dst, \"123456789l\")\t=>\t '%s' (dst value)\n\n", strcpy(dst, "123456789l"));
	bzero(dst, 20);

	printf("\t  ft_strcpy(dst, \"\")\t=>\t '%s' (dst value)\n", ft_strcpy(dst, ""));
	bzero(dst, 20);
	printf("\t  strcpy(dst, \"\")\t=>\t '%s' (dst value)\n\n", strcpy(dst, ""));
	bzero(dst, 20);

	printf("\t  ft_strcpy(dst, \"xff\")\t=>\t '%#x' (dst value)\n", ft_strcpy(dst, "\xff")[0]);
	bzero(dst, 20);
	printf("\t  strcpy(dst, \"xff\")\t=>\t '%#x' (dst value)\n\n", strcpy(dst, "\xff")[0]);
	bzero(dst, 20);

	printf("\n\n");

}


void    ftStrcmpTest( void ) {

  char  *str1 = "asdklfjasdfj////asdf'''asdf3##";
  char  *str2 = "";
  printf("%d\n", ft_strcmp(str1, str2));
  printf("%d\n", strcmp(str1, str2));

}


void    ftWriteTest( void ) {

  ft_write(-1, "Salut\n", 6);
  printf("%d\n", errno);
  write(-1, "Salut\n", 6);
  printf("%d\n", errno);

}


void    ftReadTest( void ) {

  char buf[10];
  ft_read(0, buf, 9);
  printf("%d\n", errno);

}


void    ftStrdupTest( void ) {

  char  *str = "Salut";

  char *ret = ft_strdup(str);
  printf("%s\n", ret);
  free(ret);

}


int     main(void) {

//	ftStrlenTest();
	ftStrcpyTest();
//	ftStrcmpTest();
//	ftWriteTest();
//	ftReadTest();
	ftStrdupTest();
  return 0;

}
