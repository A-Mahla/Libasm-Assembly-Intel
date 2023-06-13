
#include "libasm.h"
#include <stdio.h>
#include <unistd.h>


void    ftAtoiBaseTest( void ) {

  char *str = "-23Salut";
  char *base = "23";
  char *test = NULL;
  int ret;

  ret = ft_atoi_base(str, base);
  printf("%d\n", ret);
//  ret = ft_atoi_base(test, base);
  ret = ft_atoi_base(str, test);

}


int     main(void) {

  ftAtoiBaseTest();
  return 0;

}
// "\t\n\v\f\r +-
