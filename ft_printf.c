/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:01:08 by emgumus           #+#    #+#             */
/*   Updated: 2024/11/27 18:01:08 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_format(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_uint(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF", 0));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789abcdef", 0));
	else if (c == 'p')
		return (ft_puthex(va_arg(args, unsigned long), "0123456789abcdef", 1));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_logic(va_list args, const char *format)
{
	int	i;
	int	c;

	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			c = ft_format(args, *format);
			if (c == -1)
				return (-1);
			i += c;
		}
		else if (*format != '%')
		{
			if (ft_putchar(*format) == -1)
				return (-1);
			i++;
		}
		format++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	va_start(args, format);
	i = ft_logic(args, format);
	va_end(args);
	return (i);
}
