#include <stdio.h>
#include <string.h>

ssize_t			ft_write(int fd, const char *buf, size_t count);

int				main(void);
{
	char		*str = "Hello john";
	size_t		count;

	count = strlen(str);
	ft_write(1, str, count); 
	return (0);
}
