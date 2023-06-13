
#include "libasm.h"
#include <stdio.h>
#include <unistd.h>


void    ftAtoiBaseTest( void ) {

  char *str = "34215Salut";
  char *base = "0123456789";
  int ret;

  ret = ft_atoi_base(str, base);
  printf("%d\n", ret);

}


int     main(void) {

  ftAtoiBaseTest();
  return 0;

}
// "\t\n\v\f\r +-
