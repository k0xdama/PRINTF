#include <unistd.h>
#include <stddef.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	size_t len;

	len = ft_strlen(str);
	write(1, str, len);
}

int	main(void)
{
	char *str = "putmoiça";
	ft_putstr(str);
	return (0);
}

