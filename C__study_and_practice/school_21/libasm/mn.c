#include <stdio.h>
#include <unistd.h>
#include <string.h>

ssize_t		ft_write(int fd, const char *buf, size_t count);

int			main(void)
{
	ssize_t		r;

	char *str = "hello jon\n";
	char *pnt = NULL;
	r = ft_write(1, str, strlen(str));
	printf("r[%lu]\n", r);
	r = ft_write(1, pnt, 10);
	printf("r[%lu]\n", r);
	r = write(1, pnt, 10);
	printf("r[%lu]\n", r);
	return (0);
}
