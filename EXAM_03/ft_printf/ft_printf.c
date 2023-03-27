#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putstr(char *str)
{
    int i = 0;
	if (str)
	{
		while (str[i])
			write (1, &str[i++], 1);
		return (i);
	}
	return ft_putstr("(null)");
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(long int nb)
{
    int count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
		count += ft_putchar(nb + 48);
	return count;
}

int	ft_puthex(unsigned long nbr, char caps)
{
	int	count = 0;
	if (nbr >= 16)
	{
		count += ft_puthex((nbr / 16), caps);
		count += ft_puthex((nbr % 16), caps);
	}
	else
	{
		if (nbr < 10)
			count += ft_putnbr(nbr);
		else
			count += ft_putchar(nbr - 10 + 'a' + caps - 'x');
	}
	return count;
}

int	ft_putptr(unsigned long ptr)
{
	int	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex(ptr, 'x');
	return count;
}

int	ft_convert(const char letter, va_list args)
{
	int	count = 0;

	if (letter == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (letter == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (letter == 'p')
		count += ft_putptr(va_arg(args, unsigned long));
	else if (letter == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (letter == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (letter == 'u')
		count += ft_putnbr(va_arg(args, unsigned int));
	else if (letter == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 'x');
	else if (letter == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 'X');
	else if (letter == '%')
		count += ft_putchar(letter);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int			i = 0;
	int			count = 0;
	va_list		args;

	va_start (args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_convert(format[i + 1], args);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
