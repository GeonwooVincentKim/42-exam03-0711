/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:40:33 by geonwkim          #+#    #+#             */
/*   Updated: 2024/07/11 22:46:04 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdarg.h>

void	put_string(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		*len += write(1, str[i++], 1);
}

void	put_digit(long long int n, int base, int *length)
{
	char	*hex = "0123456789abcdef";

	if (n < 0)
	{
		n = -1;
		*len += write(1, "-", 1);
	}
	if (n >= base)
		put_digit((n / base), base, length);
	*len += write(1, &hex[n % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	pointer;

	len = 0;
	va_start(pointer, format);

	while (*format)
	{
		if ((*format == '%' ) && ((*(format + 1) == 's') || \
			(*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(pointer, char *), &len);
			else if (*format == 'd')
				put_digit((long long int)va_arg(pointer, int), 10, &len);
			else if (*format == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), \
							16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), length);
}
