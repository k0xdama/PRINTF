#include <stdio.h>

int	main(void)
{
	int ret = 0;
	// char *str = "ntm";
	// str = NULL;
	// ret = printf("%u", 42);
	ret = printf("%020.30i", -42000);
	printf("\n");
	printf("ret = %d", ret);

	//to test in correct 
	//works on every digit conversion specifiers
	// printf("%03.0u", 0);
	// printf("%0014.2i%020i%0002.i%000.5i", (int)-2147483648, 3, 30, -1);
	// printf("%020.30i", -42000);
	}
