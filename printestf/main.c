#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	FILE * fPtr;
	FILE * fPtr2;
	fPtr = fopen("myresults.txt", "w");
	fPtr2 = fopen("rlresults.txt", "w");
	if (fPtr == NULL)
	{
		printf("Unable to create file.\n");
		exit(EXIT_FAILURE);
	}
	if (fPtr2 == NULL)
	{
		printf("Unable to create file.\n");
		exit(EXIT_FAILURE);
	}
	if (ac != 2)
	{
		printf("Error, please provide desired specifier letter as av[1]\n");
	}
	else
	{
		if (strchr(av[1], 'd') != NULL)
		{
			printf("--------------------------------------\n");

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%-10d % d %+d %010d %hhd\n", 3, 3, 3, 1, 0));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%-10d % d %+d %010d %hhd\n", 3, 3, 3, 1, 0));
			
			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%llda\n", 18446744065119617025LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%llda\n", 18446744065119617025LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%10.8lld\n", 100LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%10.8lld\n", 100LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%#25.22llda\n", -1LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%#25.22llda\n", -1LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%#-+ 08.5llda\n", 100LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%#-+ 08.5llda\n", 100LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("% .40d\n", 1));
			fprintf(fPtr2, "[[[%d]]]\n", printf("% .40d\n", 1));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("% 10.40d\n", 10));
			fprintf(fPtr2, "[[[%d]]]\n", printf("% 10.40d\n", 10));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("% 10.40d\n", -10));
			fprintf(fPtr2, "[[[%d]]]\n", printf("% 10.40d\n", -10));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%+010.d\n", 10));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%+010.d\n", 10));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%10.0d\n", -10));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%10.0d\n", -10));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%+010.d\n", -10));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%+010.d\n", -10));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%10.0d\n", 10));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%10.0d\n", 10));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%+ 010.d\n", 10));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%+ 010.d\n", 10));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("% 10.0d\n", -10));
			fprintf(fPtr2, "[[[%d]]]\n", printf("% 10.0d\n", -10));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%+ 010.d\n", -10));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%+ 010.d\n", -10));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("% 10.0d\n", 10));
			fprintf(fPtr2, "[[[%d]]]\n", printf("% 10.0d\n", 10));


			fprintf(fPtr, "[[[%d]]]\n", ft_printf("% 10.40d\n", 0));
			fprintf(fPtr2, "[[[%d]]]\n", printf("% 10.40d\n", 0));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("% 10.40d\n", -0));
			fprintf(fPtr2, "[[[%d]]]\n", printf("% 10.40d\n", -0));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%+010.d\n", 0));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%+010.d\n", 0));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%10.0d\n", -0));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%10.0d\n", -0));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%+010.d\n", -0));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%+010.d\n", -0));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%10.0d\n", 0));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%10.0d\n", 0));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%+ 010.d\n", 0));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%+ 010.d\n", 0));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("% 10.0d\n", -0));
			fprintf(fPtr2, "[[[%d]]]\n", printf("% 10.0d\n", -0));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%+ 010.d\n", -0));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%+ 010.d\n", -0));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("% 10.0d\n", 0));
			fprintf(fPtr2, "[[[%d]]]\n", printf("% 10.0d\n", 0));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%4.5d\n", 42));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%4.5d\n", 42));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%5.4d\n", 42));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%5.4d\n", 42));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%4.5d\n", 42LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%4.5d\n", 42LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%5.4d\n", 42LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%5.4d\n", 42LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%4.5d\n", -42U));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%4.5d\n", -42U));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%5.4d\n", -42U));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%5.4d\n", -42U));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%5.4d\n", 42U));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%5.4d\n", 42U));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%54d\n", 42LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%54d\n", 42LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%54.d\n", 42LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%54.d\n", 42LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("% 0-54.2d\n", 42LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("% 0-54.2d\n", 42LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("% 054d\n", 42LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("% 054d\n", 42LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%- 0.2d\n", 42LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%- 0.2d\n", 42LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%2.2d\n", 42LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%2.2d\n", 42LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%2.3d\n", 42LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%2.3d\n", 42LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%2.1d\n", 42LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%2.1d\n", 42LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%5.1d\n", 42LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%5.1d\n", 42LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%5.2d\n", 42LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%5.2d\n", 42LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%5.3d\n", 42LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%5.3d\n", 42LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%5.3d\n", 4242LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%5.3d\n", 4242LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%5.3d\n", 424LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%5.3d\n", 424LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%5.3d\n", 424LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%5.3d\n", 424LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%-+5.3d\n", 424LL));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%-+5.3d\n", 424LL));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%d %d %d %d %d %d %d %d\n", 0, 1, 9, 10, 11, 9999, 10000, 100001));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%d %d %d %d %d %d %d %d\n", 0, 1, 9, 10, 11, 9999, 10000, 100001));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%d\n", -258733));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%d\n", -258733));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%d hello %d\n", 2147483647, -2147483648));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%d hello %d\n", 2147483647, -2147483648));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("-%.4d-%.4d-%.d-%.0d-\n", 7, 12345, 1, 9));
			fprintf(fPtr2, "[[[%d]]]\n", printf("-%.4d-%.4d-%.d-%.0d-\n", 7, 12345, 1, 9));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%d %hd %d\n", 123456, 123456, 123456));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%d %hd %d\n", 123456, 123456, 123456));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%d %ld %d\n", 123456, 123456, 123456));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%d %ld %d\n", 123456, 123456, 123456));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("-%d-%.0d-%.8d-%8.0d-%8.8d-\n", 0, 0, 0, 0, 0));
			fprintf(fPtr2, "[[[%d]]]\n", printf("-%d-%.0d-%.8d-%8.0d-%8.8d-\n", 0, 0, 0, 0, 0));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("%d %d %+d %+d % d % d %+ d %+ d % +d % +d\n", 7, -7, 7, -7, 7, -7, 7, -7, 7, -7));
			fprintf(fPtr2, "[[[%d]]]\n", printf("%d %d %+d %+d % d % d %+ d %+ d % +d % +d\n", 7, -7, 7, -7, 7, -7, 7, -7, 7, -7));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("'%-d'\n", 5));
			fprintf(fPtr2, "[[[%d]]]\n", printf("'%-d'\n", 5));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("'%-+d'\n", 5));
			fprintf(fPtr2, "[[[%d]]]\n", printf("'%-+d'\n", 5));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("'%+-d'\n", 5));
			fprintf(fPtr2, "[[[%d]]]\n", printf("'%+-d'\n", 5));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("'%+d'\n", -5));
			fprintf(fPtr2, "[[[%d]]]\n", printf("'%+d'\n", -5));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("'% d'\n", -5));
			fprintf(fPtr2, "[[[%d]]]\n", printf("'% d'\n", -5));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("'% d'\n", 5));
			fprintf(fPtr2, "[[[%d]]]\n", printf("'% d'\n", 5));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("'% .0d'\n", 0));
			fprintf(fPtr2, "[[[%d]]]\n", printf("'% .0d'\n", 0));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("'% +d'\n", 5));
			fprintf(fPtr2, "[[[%d]]]\n", printf("'% +d'\n", 5));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("'%03d'\n", 5));
			fprintf(fPtr2, "[[[%d]]]\n", printf("'%03d'\n", 5));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("'%-03d'\n", -5));
			fprintf(fPtr2, "[[[%d]]]\n", printf("'%-03d'\n", -5));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("'%03d'\n", -5));
			fprintf(fPtr2, "[[[%d]]]\n", printf("'%03d'\n", -5));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("'%-+0003d'\n", -5));
			fprintf(fPtr2, "[[[%d]]]\n", printf("'%-+0003d'\n", -5));

			fprintf(fPtr, "[[[%d]]]\n", ft_printf("'%0+ 3d'\n", -5U));
			fprintf(fPtr2, "[[[%d]]]\n", printf("'%0+ 3d'\n", -5U));
		}
		else if (strchr(av[1], 'c') != NULL)
			printf("\%c not yet implemented\n");
		else if (strchr(av[1], 's') != NULL)
			printf("\%s not yet implemented\n");
		else if (strchr(av[1], 'p') != NULL)
			printf("\%p not yet implemented\n");
		else if (strchr(av[1], 'i') != NULL)
			printf("\%p not yet implemented\n");
		else if (strchr(av[1], 'o') != NULL)
			printf("\%p not yet implemented\n");
		else if (strchr(av[1], 'u') != NULL)
			printf("\%p not yet implemented\n");
		else if (strchr(av[1], 'x') != NULL)
			printf("\%p not yet implemented\n");
		else if (strchr(av[1], 'X') != NULL)
			printf("\%p not yet implemented\n");
		else
		{
			printf("INVALID SPECIFIER\n");
			return (-1);
		}
		return (0);
	}
}
