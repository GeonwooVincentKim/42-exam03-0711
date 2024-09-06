#include	<unistd.h>
#include	<stdarg.h>

void	put_str(char *s, int *len)
{
	if (!s)
		s = "(null)";
	while (*s)
		*len += write(1, s++, 1);
}

void	put_dec(long long int n, int base, int *len)
{
	char	*hex = "0123456789abcdef";

	if (n < 0)
	{
		n *= -1;
		*len += write(1, "-", 1);
	}
	if (n >= base)
		put_dec((n / base), base, len);
	*len += write(1, &hex[n % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int	length = 0;
	va_list pointer;
	va_start(pointer, format);

	while (pointer)
	{
		if ((*format == '%') || ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(pointer, char *), &length);
			else if (*format == 'd')
				put_str((long long int)va_arg(pointer, int), 10, &length);
			else if (*format == 'x')
				put_str((long long int)va_arg(pointer, unsigned int), 16, &length);
		}
		else
			length += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), length);
}