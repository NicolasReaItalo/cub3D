/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:43 by nrea              #+#    #+#             */
/*   Updated: 2023/12/13 11:51:08 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_parsearg(char d, va_list a_l)
{
	if (d == 'c')
		return (ft_put_char(va_arg(a_l, int)));
	else if (d == 's')
		return (ft_put_str(va_arg(a_l, char *)));
	else if (d == 'd' || d == 'i')
		return (ft_put_int(va_arg(a_l, int)));
	else if (d == 'u')
		return (ft_put_uint(va_arg(a_l, unsigned int)));
	else if (d == 'p')
		return (ft_put_ptr(va_arg(a_l, void *)));
	else if (d == 'x')
		return (ft_put_hex(va_arg(a_l, unsigned int), "0123456789abcdef"));
	else if (d == 'X')
		return (ft_put_hex(va_arg(a_l, unsigned int), "0123456789ABCDEF"));
	else if (d == '%')
		return (ft_put_char('%'));
	else if (d == '\0')
		return (-1);
	return (ft_put_char('%') + ft_put_char(d));
}

static int	ft_return_err(va_list a_l)
{
	va_end(a_l);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		char_count;
	int		ret_parse;
	va_list	a_l;

	if (!format)
		return (-1);
	va_start(a_l, format);
	char_count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ret_parse = ft_parsearg(*format, a_l);
			if (ret_parse == -1)
				return (ft_return_err(a_l));
			char_count += ret_parse;
		}
		else
			char_count += ft_put_char(*format);
		format++;
	}
	va_end(a_l);
	return (char_count);
}
