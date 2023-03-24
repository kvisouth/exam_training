#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Faire 5 Fonctions "utils"
// ft_putstr, ft_putchar, ft_putnbr, ft_puthex, ft_putptr
// Puis faire printf.

// Faire une fonction putstr
// putstr normal mais qui compte le nombre de caractères qu'il a écrit et le renvoie.
int	ft_putstr(char *s)
{
    int i = 0;
	if (s)
	{
		while (s[i])
		{
			write (1, &s[i], 1);
			i++;
		}
		return (i);
	}
	return (ft_putstr("(null)"));
}

// Faire une function putchar
// putchar normal mais renvoie 1 (car il a ecrit 1 caractère)
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

// Faire une fonction putnbr
// Pareil, il renvoie le nombre de caractères qu'il a écrit.
int	ft_putnbr(long int nb)
{
    int len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
		len += ft_putchar(nb + 48);
	return (len);
}

// Faire une fonction puthex
int	ft_puthex(unsigned long nbr, char caps)
{
	int	len = 0;
	if (nbr >= 16)
	{
		len += ft_puthex((nbr / 16), caps);
		len += ft_puthex((nbr % 16), caps);
	}
	else
	{
		if (nbr < 10)
			len += ft_putnbr(nbr);
		else
			len += ft_putchar(nbr - 10 + 'a' + caps - 'x');
	}
	return (len);
}

// Faire une fonction putptr
int	ft_putptr(unsigned long ptr)
{
	int	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex(ptr, 'x');
	return (count);
}

// C --> putchar
// S --> putstr
// P --> putptr
// D --> putnbr
// I --> putnbr
// U --> putnbr
// X --> puthex
// x --> puthex
// % --> putchar

static int	ft_convert(const char letter, va_list args)
{
	int	count = 0;
	if (letter == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (letter == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (letter == 'p')
		count += ft_putptr(va_arg(args, unsigned long));
	else if (letter == 'd' || letter == 'i')
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
	int			index = 0;
	int			count = 0;
	va_list		args;
	va_start (args, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			count += ft_convert(format[index + 1], args);
			index++;
		}
		else
			count += ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	return (count);
}
