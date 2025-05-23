#include <stdio.h>
#include <fcntl.h>
#include "./get_next_line.h"

int main(void)
{
	int fd = open("res.txt", O_RDONLY);
	char *res = get_next_line(fd);
	if (!res)
		return (1);
	printf("%s", res);
	free(res);
	res = get_next_line(fd);
	if (!res)
		return (1);
	printf("%s", res);
	free(res);
	res = get_next_line(fd);
	if (!res)
		return (1);
	printf("%s", res);
	free(res);
	return 0;
}
