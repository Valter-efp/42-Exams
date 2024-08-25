#include <unistd.h>
#include <stdarg.h>

void put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len = *len + write(1, str++, 1);
}

void put_digit(long long int nbr, int base, int *len)
{
	if (nbr < 0)
	{
		nbr = nbr * - 1;
		*len = *len + write(1, "-", 1);
	}
	if (nbr >= base)
		put_digit((nbr / base), base, len);
	*len = *len + write(1, &("0123456789abcdef"[nbr % base]), 1);
}
int ft_printf(const char *format, ... )
{
	int len = 0;

	va_list pointer;
	va_start(pointer, format);

	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(pointer, char *), &len);
			else if (*format == 'd')
				put_digit((long long int)va_arg(pointer,int), 10, &len);
			else if (*format == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), 16, &len);
		}
		else
			len = len + write(1, format, 1);
		format++;
	}
	return(va_end(pointer), len);
}