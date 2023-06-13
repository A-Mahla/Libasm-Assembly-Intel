
#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>


void    ftStrlenTest( void ) {

  char *str1 = "Salut";
  printf("%ld\n", ft_strlen(str1));

  char *str2 = "";
  printf("%ld\n", ft_strlen(str2));
}


void    ftStrcpyTest( void ) {

  char dest[20];
  char *src = "Hi, what's new !";
  printf("%s\n", ft_strcpy(dest, src));
  printf("%s\n", dest);
  printf("%s\n", src);

}


void    ftStrcmpTest( void ) {

  char  *str1 = "Helloo";
  char  *str2 = "Hellooo";
  printf("%d\n", ft_strcmp(str1, str2));
  printf("%d\n", strcmp(str1, str2));

}


void    ftWriteTest( void ) {

  ft_write(-1, "Salut\n", 6);
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

  ftStrlenTest();
  ftStrcpyTest();
  ftStrcmpTest();
  ftWriteTest();
  ftReadTest();
  ftStrdupTest();
  return 0;

}
