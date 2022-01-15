#include "get_next_line.h"
#include <stdio.h>
#include <sys/file.h>
//#include <fcntl.h>

int main(void)
{
    int fd;
    fd = open("../test.txt", O_RDONLY);
	//fd = 0;
	char *p;

	p = get_next_line(fd);
	while (p)
	{
		printf("%s", p);
		free(p);
		p = get_next_line(fd);
	}

//    printf("%s", get_next_line(fd));
//    printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
    return (0);
}
