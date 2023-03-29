#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_putchar(char c)
{
    write(1,&c,1);
    return 1;
}

int ft_putstr(char *str)
{
    int i = 0;
    if (str)
    {
        while (str[i])
            write(1,&str[i++],1);
        return i;
    }
    return (ft_putstr("(null)"));
}

int ft_putnbr(long int nb)
{
    int count = 0;
    if (nb < 0)
    {
        count += ft_putchar('-');
        nb *= -1;
    }
    if (nb >= 10)
    {
        count += ft_putnbr(nb/10);
        count += ft_putnbr(nb%10);
    }
    else
        count += ft_putchar(nb + 48);
    return count;
}

int ft_puthex(unsigned long nb, char caps)
{
    int count = 0;
    if (nb >= 16)
    {
        count += ft_puthex(nb/16, caps);
        count += ft_puthex(nb%16, caps);
    }
    else
    {
        if (nb < 10)
            count += ft_putnbr(nb);
        else
            count += ft_putchar(nb - 10 + 'a' + caps - 'x');
    }
    return count;
}

int ft_putptr(unsigned long ptr)
{
    int count = 0;
    if (!ptr)
        return (ft_putstr("(nil)"));
    count += ft_putstr("0x");
    count += ft_puthex(ptr, 'x');
    return count;
}

//cspdiuxX%
int convert(const char c, va_list arg)
{
    int count = 0;
    if (c == 'c')
        count += ft_putchar(va_arg(arg, int));
    else if (c == 's')
        count += ft_putstr(va_arg(arg, char *));
    else if (c == 'p')
        count += ft_putptr(va_arg(arg, unsigned long));
    else if (c == 'd')
        count += ft_putnbr(va_arg(arg, int));
    else if (c == 'i')
        count += ft_putnbr(va_arg(arg, int));
    else if (c == 'u')
        count += ft_putnbr(va_arg(arg, unsigned int));
    else if (c == 'x')
        count += ft_puthex(va_arg(arg, unsigned int), 'x');
    else if (c == 'X')
        count += ft_puthex(va_arg(arg, unsigned int), 'X');
    else if (c == '%')
        count += ft_putchar(c);
    return count;
}

int	ft_printf(const char *format, ...)
{
    int i = 0;
    int count = 0;
    va_list arg;

	va_start (arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += convert(format[i + 1], arg);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return count;
}