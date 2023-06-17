#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>


void    ftStrlenTest( void ) {

	printf("\t========== ft_strcpy tests ===========\n\n");

	printf("\t  ft_strlen(\"123456789l\")\t=>\t '%zu' (return value)\n", ft_strlen("123456789l"));
	printf("\t  strlen(\"123456789l\")\t\t=>\t '%zu' (return value)\n\n", strlen("123456789l"));

	printf("\t  ft_strlen(\"\")\t\t\t=>\t '%zu' (return value)\n", ft_strlen(""));
	printf("\t  strlen(\"\")\t\t\t=>\t '%zu' (return value)\n\n", strlen(""));

	printf("\t  ft_strlen(\"\\xff\\xff\\xff\\xff\")\t=>\t '%zu' (return value)\n", ft_strlen("\xff\xff\xff\xff"));
	printf("\t  strlen(\"\\xff\\xff\\xff\\xff\")\t=>\t '%zu' (return value)\n\n", strlen("\xff\xff\xff\xff"));

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
        "\t  ft_strcpy(dst, \"xff\")\t\t=>\t '%#x' (return value) / '%#x' (dst value)\n",
        ft_strcpy(dst, "\xff")[0]
        ,dst[0]
    );
	bzero(dst, 20);

	printf(
        "\t  strcpy(dst, \"xff\")\t\t=>\t '%#x' (return value) / '%#x' (dst value)\n\n",
        strcpy(dst, "\xff")[0],
        dst[0]
    );
	bzero(dst, 20);

	printf("\n\n");

}


void    ftStrcmpTest( void ) {

	printf("\t========== ft_strcpy tests ===========\n\n");

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

	ftStrlenTest();
	ftStrcpyTest();
	ftStrcmpTest();
//	ftWriteTest();
//	ftReadTest();
	ftStrdupTest();
  return 0;

}
