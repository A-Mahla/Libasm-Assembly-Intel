
#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>


void    ftStrcpyTest( void ) {

  char dest[20] = {0};
  char *src = "123";
  printf("%s\n", ft_strcpy(dest, src));
  printf("%s\n", dest);
  printf("%s\n", src);

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
//	ftStrcpyTest();
//	ftStrcmpTest();
//	ftWriteTest();
//	ftReadTest();
	ftStrdupTest();
  return 0;

}
