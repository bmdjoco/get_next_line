#include <stdio.h>
#include <fcntl.h>
#include "./get_next_line.h"

int main(void)
{
	int		fd;
	char	*res;

	fd = open("res.txt", O_RDONLY);
	// fd = 0;
	if (fd == -1)
		return 1;
	while ((res = get_next_line(fd)) != NULL)
	{
		printf("%s", res);
		free(res);
	}
	close(fd);
	return 0;
}
