
#include "libasm.h"
#include <stdio.h>
#include <unistd.h>


void    ftAtoiBaseTest( void ) {

  char *str = "Salut";
  char *base = "1324";
  int ret;

  ret = ft_atoi_base(str, base);
  printf("%d\n", ret);

}


int     main(void) {

  ftAtoiBaseTest();
  return 0;

}
