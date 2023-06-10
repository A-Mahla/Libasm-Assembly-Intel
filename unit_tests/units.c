
#include "libasm.h"
#include <stdio.h>
#include <string.h>


void    ftStrlenTest( void ) {

  char *str1 = "Salut";
  printf("%ld\n", ft_strlen(str1));

}


void    ftStrcpyTest( void ) {

  char dest[20];
  char *src = "Hi, what's new !";
  printf("%s\n", ft_strcpy(dest, src));
  printf("%s\n", dest);
  printf("%s\n", src);

}


void    ftStrcmpTest( void ) {

  char  *str1 = "Hellooo";
  char  *str2 = "Helloooo";
  printf("%d\n", ft_strcmp(str1, str2));
  printf("%d\n", strcmp(str1, str2));

}


void    ftWriteTest( void ) {

  ft_write(1, "Salut\n", 6);

}


int     main(void) {

//  ftStrlenTest();
//  ftStrcpyTest();
//  ftStrcmpTest();
  ftWriteTest();
  return 0;

}
