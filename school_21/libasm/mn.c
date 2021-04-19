#include <stdio.h>
#include <string.h>

void		ft_write(int fd, const char *buf, size_t count);

int			main(void)
{
	char *str = "hello jon\n";
	ft_write(1, str, strlen(str));
	return (0);
}
