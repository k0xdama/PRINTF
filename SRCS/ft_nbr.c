#include <unistd.h>
#include <stddef.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nbl;

	nbl = nb;
	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl *= -1;
	}
	if (nbl >= 0 && nbl <= 9)
		ft_putchar(nbl + 48);
	if (nbl > 9)
	{
		ft_putnbr(nbl / 10);
		ft_putnbr(nbl % 10);
	}
}
#include <limits.h>
int	main(void)
{
	int nb = INT_MAX;
	ft_putnbr(nb);
}
