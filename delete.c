#include <stdio.h>
#include <unistd.h>

#if defined(__APPLE__) && defined(__MACH__)
	# define PREFIX "0x"
	# define NIL "0x0"
	# define BASE "0123456789abcdef"
#elif defined(__linux__)
	# define PREFIX "0x"
	# define NIL "(nil)"
	# define BASE "0123456789abcdef"
#endif

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n++])
		;
	return (--n);
}

int	ft_putstr(char *s)
{
	return (write(STDOUT_FILENO, s, ft_strlen(s)));
}

int	ft_putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int	ft_puthex(unsigned long int n, char specifier) //take it as a long
{
	int		len;

	len = 0;
	if (specifier != 'p')
		n = (unsigned)n; //for x and X
	if (n > 15)
		len += ft_puthex(n / 16, specifier);
	if (specifier == 'X') //switch this to 'X'
		len += ft_putchar("0123456789ABCDEF"[n % 16]);
	else
		len += ft_putchar("0123456789abcdef"[n % 16]);
	return (len);
}

int    ft_putnbr(long n)
{
    int    count;

    count = 0;
    if (n < 0)
    {
        ft_putchar('-');
        count++;
        n = -n;
    }
    if (n > 9)
        count += ft_putnbr(n / 10);
    count += ft_putchar(n % 10 + '0');
    return (count);
}

int main()
{
	char	*x = 0;
	int		n = -2147483648;
/*
	int ret1 = ft_putptr(x);
	printf("\n");
	int ret2 = printf("%p", x);
	printf("\n");
*/
	printf("\nmine: %i || real: %i\n", ft_putnbr(n), printf("%i", n));
	return 0;
}
