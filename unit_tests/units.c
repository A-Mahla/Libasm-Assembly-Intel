
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
  ft_strcpy(dest, src);
  printf("%s\n", dest);
  printf("%s\n", src);

}

int     main(void) {

//  ftStrlenTest();
  ftStrcpyTest();
  return 0;

}
