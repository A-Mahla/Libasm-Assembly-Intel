#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


void    ftStrlenTest( void ) {

	printf("\t========== ft_strlen tests ===========\n\n");

	printf(
        "\t  ft_strlen(\"123456789l\")\t=>\t '%zu' (return value)\n",
        ft_strlen("123456789l")
    );
	printf(
        "\t  strlen(\"123456789l\")\t\t=>\t '%zu' (return value)\n\n",
        strlen("123456789l")
    );

	printf("\t  ft_strlen(\"\")\t\t\t=>\t '%zu' (return value)\n", ft_strlen(""));
	printf("\t  strlen(\"\")\t\t\t=>\t '%zu' (return value)\n\n", strlen(""));

	printf(
        "\t  ft_strlen(\"\\xff\\xff\\xff\\xff\")\t=>\t '%zu' (return value)\n",
        ft_strlen("\xff\xff\xff\xff")
    );
	printf(
        "\t  strlen(\"\\xff\\xff\\xff\\xff\")\t=>\t '%zu' (return value)\n\n",
        strlen("\xff\xff\xff\xff")
    );

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
        "\t  ft_strcpy(dst, \"\\xff\")\t\t=>\t '%#x' (return value) / '%#x' (dst value)\n",
        ft_strcpy(dst, "\xff")[0]
        ,dst[0]
    );
	bzero(dst, 20);

	printf(
        "\t  strcpy(dst, \"\\xff\")\t\t=>\t '%#x' (return value) / '%#x' (dst value)\n\n",
        strcpy(dst, "\xff")[0],
        dst[0]
    );
	bzero(dst, 20);

	printf("\n\n");

}


void    ftStrcmpTest( void ) {

	printf("\t========== ft_strcmp tests ===========\n\n");

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


void    ftStrdupTest( void ) {

    printf("\t========== ft_strdup tests ===========\n\n");

	char *dst;

	printf(
        "\t  ft_strdup(\"123456789l\")\t=>\t '%s' (return value)\n",
        (dst = ft_strdup("123456789l"))
    );
	free(dst);
	printf(
        "\t  strdup(\"123456789l\")\t\t=>\t '%s' (return value)\n\n",
        (dst = strdup("123456789l"))
    );
	free(dst);

	printf(
        "\t  ft_strdup(\"\")\t\t\t=>\t '%s' (return value)\n",
        (dst = ft_strdup(""))
    );
	free(dst);
	printf(
        "\t  strdup(\"\")\t\t\t=>\t '%s' (return value)\n\n",
        (dst = strdup(""))
    );
	free(dst);

	printf(
        "\t  ft_strdup(\"\\xff\")\t\t=>\t '%#x' (return value)\n",
        (dst = ft_strdup("\xff"))[0]
    );
	free(dst);
	printf(
        "\t  strdup(\"\\xff\")\t\t=>\t '%#x' (return value)\n\n",
        (dst = strdup("\xff"))[0]
    );
	free(dst);

	printf("\n\n");

}


void    ftWriteTest( void ) {


	printf("\t========== ft_write tests ===========\n\n");

    write(1, "\t  \"", 4);
	printf(
        "\"\t=> ft_write(1, \"Salut  \", 7)\t/  '%ld' (return value)\t/  ERRNO = %d\n",
        ft_write(1, "Salut  ",7),
        errno
    );
    write(1, "\t  \"", 4);
	printf(
        "\"\t=> write(1, \"Salut  \", 7)\t/  '%ld' (return value)\t/  ERRNO = %d\n\n",
        write(1, "Salut  ",7),
        errno
    );

    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> ft_write(2, \"Salut  \", 3)\t/  '%ld' (return value)\t/  ERRNO = %d\n",
        ft_write(2, "Salut  ", 3),
        errno
    );
    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> write(2, \"Salut  \", 3)\t/  '%ld' (return value)\t/  ERRNO = %d\n\n",
        write(2, "Salut  ", 3),
        errno
    );

    write(1, "\t  \"", 4);
	printf(
        "\"\t=> ft_write(2, \"Salut  \", 8)\t/  '%ld' (return value)\t/  ERRNO = %d\n",
        ft_write(2, "Salut  ", 8),
        errno
    );
    write(1, "\t  \"", 4);
	printf(
        "\"\t=> write(2, \"Salut  \", 8)\t/  '%ld' (return value)\t/  ERRNO = %d\n\n",
        write(2, "Salut  ", 8),
        errno
    );

    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> ft_write(2, \"Salut  \", 0)\t/  '%ld' (return value)\t/  ERRNO = %d\n",
        ft_write(2, "Salut  ", 0),
        errno
    );
    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> write(2, \"Salut  \", 0)\t/  '%ld' (return value)\t/  ERRNO = %d\n\n",
        write(2, "Salut  ", 0),
        errno
    );

    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> ft_write(1, \"Salut  \", -1)\t/  '%ld' (return value)\t/  ERRNO = %d\n",
        ft_write(1, "Salut  ", -1),
        errno
    );
    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> write(1, \"Salut  \", -1)\t/  '%ld' (return value)\t/  ERRNO = %d\n\n",
        write(1, "Salut  ", -1),
        errno
    );

    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> ft_write(-1, \"Salut  \", 7)\t/  '%ld' (return value)\t/  ERRNO = %d\n",
        ft_write(-1, "Salut  ",7),
        errno
    );
    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> write(-1, \"Salut  \", 7)\t/  '%ld' (return value)\t/  ERRNO = %d\n\n",
        write(-1, "Salut  ",7),
        errno
    );

    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> ft_write(2, NULL, 7)\t/  '%ld' (return value)\t/  ERRNO = %d\n",
        ft_write(2, NULL,7),
        errno
    );
    write(1, "\t  \"", 4);
	printf(
        "\"\t\t=> write(2, NULL, 7)\t/  '%ld' (return value)\t/  ERRNO = %d\n\n",
        write(2, NULL,7),
        errno
    );

}


void    ftReadTest( void ) {

    char buf[10];
    int fd = open("Makefile", O_RDONLY);
    read(fd, buf, 2);
    errno = 0;

    printf("\t========== ft_read tests ===========\n\n");


    buf[7] = '\0';
	printf(
        "\t  ft_read(fd, buf, 7)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n",
        ft_read(fd, buf,7),
        buf,
        errno
    );
	printf(
        "\t  read(fd, buf, 7)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n\n",
        read(fd, buf,7),
        buf,
        errno
    );

    buf[3] = '\0';
	printf(
        "\t  ft_read(fd, buf, 3)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n",
        ft_read(fd, buf, 3),
        buf,
        errno
    );
	printf(
        "\t  read(fd, buf, 3)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n\n",
        read(fd, buf, 3),
        buf,
        errno
    );

    buf[8] = '\0';
	printf(
        "\t  ft_read(fd, buf, 8)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n",
        ft_read(fd, buf, 8),
        buf,
        errno
    );
	printf(
        "\t  read(fd, buf, 8)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n\n",
        read(fd, buf, 8),
        buf,
        errno
    );

    buf[0] = '\0';
	printf(
        "\t  ft_read(fd, buf, 0)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n",
        ft_read(fd, buf, 0),
        buf,
        errno
    );
	printf(
        "\t  read(fd, buf, 0)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n\n",
        read(fd, buf, 0),
        buf,
        errno
    );

	printf(
        "\t  ft_read(fd, buf, -1)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n",
        ft_read(fd, buf, -1),
        buf,
        errno
    );
	printf(
        "\t  read(fd, buf, -1)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n\n",
        read(fd, buf, -1),
        buf,
        errno
    );

	printf(
        "\t  ft_read(-1, buf, 7)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n",
        ft_read(-1, buf,7),
        buf,
        errno
    );
	printf(
        "\t  read(-1, buf, 7)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n\n",
        read(-1, buf,7),
        buf,
        errno
    );

	printf(
        "\t  ft_read(fd, NULL, 7)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n",
        ft_read(fd, NULL,7),
        buf,
        errno
    );
	printf(
        "\t  read(fd, NULL, 7)\t/  '%ld' (return value)\t/  '%s' (buf value)\t/  ERRNO = %d\n\n",
        read(fd, NULL,7),
        buf,
        errno
    );

}


int     main(void) {

    printf("\n");

	ftStrlenTest();
	ftStrcpyTest();
	ftStrcmpTest();
	ftStrdupTest();
	ftWriteTest();
	ftReadTest();
  return 0;

}
