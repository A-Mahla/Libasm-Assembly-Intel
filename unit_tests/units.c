
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

  char  *str1 = "Helloooo";
  char  *str2 = "Helloo";
  printf("%d\n", ft_strcmp(str1, str2));

}


int     main(void) {

//  ftStrlenTest();
//  ftStrcpyTest();
  ftStrcmpTest();
  return 0;

}
