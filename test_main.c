#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

int	main(void)
{
	char buffer[100] = "ABCDEFGHIJKL";
	int length1 = 5;
	ft_memmove(buffer, buffer + length1, 100);
	printf("%s", buffer);
	return (0);
}