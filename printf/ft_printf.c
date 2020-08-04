/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 21:59:41 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:59:43 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		ft_printf_call_handler(const char *input, va_list v_l)
{
	int len;

	len = 0;
	if (ft_asterisk_count(input) == -1)
		len += ft_print_type(input, va_arg(v_l, int), -1, va_arg(v_l, void *));
	else if (ft_asterisk_count(input) == 1)
		len += ft_print_type(input, 0, va_arg(v_l, int), va_arg(v_l, void *));
	else if (ft_asterisk_count(input) == 2)
		len += ft_print_type(input, va_arg(v_l, int), va_arg(v_l, int), \
			va_arg(v_l, void *));
	else if (ft_asterisk_count(input) == -3)
		len += ft_print_type(input, 0, -1, (void *)0);
	else if (ft_asterisk_count(input) == -2)
	{
		(void)va_arg(v_l, void *);
		len += ft_print_type(input, va_arg(v_l, int), -1, va_arg(v_l, void *));
	}
	else
		len += ft_print_type(input, 0, -1, va_arg(v_l, void *));
	return (len);
}

int		ft_printf(const char *input, ...)
{
	int		x;
	va_list	v_l;
	int		len;

	len = 0;
	x = 0;
	va_start(v_l, input);
	while (input[x] != 0)
	{
		if (input[x] == '%')
		{
			len += ft_printf_call_handler(&input[x + 1], v_l);
			x = ft_filter_var(x + 1, (char *)&input[x + 1]);
		}
		else
			len += ft_putchar(input[x]);
		x++;
	}
	va_end(v_l);
	return (len);
}
