/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:08:11 by bgomes-l          #+#    #+#             */
/*   Updated: 2023/10/10 17:05:01 by bgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_format( char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = ft_print_char(va_arg (ap, int));
	else if (specifier == 's')
		count = ft_print_str(va_arg (ap, char *));
	else if (specifier == 'd')
		count = ft_print_digit((long)va_arg (ap, int), 10, DEC_BASE);
	else if (specifier == 'u')
		count = ft_print_digit((long)va_arg (ap, unsigned int), 10, DEC_BASE);
	else if (specifier == 'i')
		count = ft_print_digit((long)va_arg (ap, int), 10, DEC_BASE);
	else if (specifier == 'x')
		count = ft_print_digit((long)va_arg (ap, unsigned int), 16, HEXA_LOW);
	else if (specifier == 'X')
		count = ft_print_digit((long)va_arg (ap, unsigned int), 16, HEXA_UP);
	else if (specifier == 'p')
		count = ft_print_pointer((long)va_arg (ap, unsigned long));
	else if (specifier == '%')
		count = ft_print_char(37);
	else
		count += write (1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
			count += ft_print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
