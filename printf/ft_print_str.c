/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 06:15:29 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:04:54 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_str(const char *c, void *val)
{
	if (c[0] == '%')
		return (ft_tostr('%'));
	if (c[0] == 's' || c[0] == 'S')
		if ((char *)val == 0)
			return (ft_strdup("(null)"));
		else
			return (ft_strdup((char *)val));
	else if (c[0] == 'c' || c[0] == 'C')
		return (ft_tostr((char)val));
	else if (c[0] == 'p' || c[0] == 'P')
	{
		if ((char *)val == 0)
			return (ft_strdup("0"));
		else
			return (ft_getptr((unsigned long)val));
	}
	return (0);
}

int		ft_print_margin_s(int strlen, int prc, char flag, int size)
{
	int rval;
	int prc1;

	prc1 = prc == -1 ? 0 : prc;
	rval = 0;
	if (size != 0 && flag == '0')
		rval += ft_print_xchar('0', (size - strlen));
	if (size != 0 && flag == 0 && prc1 < strlen && prc != 0)
		rval += ft_print_xchar(' ', (size - prc1));
	else if (size != 0 && flag == 0 && prc1 == 0)
		rval += ft_print_xchar(' ', size - strlen - prc1);
	else if (size != 0 && flag == 0 && prc1 != 0)
		rval += ft_print_xchar(' ', (size - strlen));
	return (rval);
}

int		ft_print_str(char *str, int prc, char flag, int size)
{
	int rval;
	int strlen;
	int prc1;

	prc1 = prc == -1 ? 0 : prc;
	strlen = ft_strlen(str);
	rval = 0 + ft_print_margin_s(strlen, prc, flag, size);
	if (prc != 0 && str[0] != '0' && str[1] != 'x')
		rval += ft_putstrl(str, prc);
	else
		rval += ft_putstr(str);
	if (flag == '-' && prc == -1)
		rval += ft_print_xchar(' ', size);
	else if (flag == '-' && prc1 == 0)
		rval += ft_print_xchar(' ', size - strlen);
	else if (flag == '-' && prc1 != 0)
		rval += ft_print_xchar(' ', size - rval);
	return (rval);
}

int		ft_print_c(char *str, int prc, char flag, int size)
{
	int rval;
	int strlen;
	int prc1;

	prc1 = prc == -1 ? 0 : prc;
	strlen = ft_strlen(str);
	if (*str == 0)
		strlen = ft_strlen(str) + 1;
	rval = 0 + ft_print_margin_s(strlen, prc, flag, size);
	rval += ft_putchar(*str);
	if (flag == '-' && prc == -1)
		rval += ft_print_xchar(' ', size);
	else if (flag == '-' && prc1 == 0)
		rval += ft_print_xchar(' ', size - strlen);
	else if (flag == '-' && prc1 != 0)
		rval += ft_print_xchar(' ', size - rval);
	return (rval);
}

int		ft_print_p(char *str, int prc, char flag, int size)
{
	int rval;
	int strlen;
	int prc1;

	prc1 = prc == -1 ? 0 : prc;
	strlen = prc == -1 ? 2 : ft_strlen(str) + 2;
	rval = 0;
	if (size != 0 && flag == '0')
		rval += ft_print_xchar('0', (size - strlen));
	if (size != 0 && flag == 0 && prc1 != 0)
		rval += ft_print_xchar(' ', (size - strlen));
	else if (size != 0 && flag == 0 && prc1 < strlen && prc1 != 0)
		rval += ft_print_xchar(' ', (size - prc1));
	else if (size != 0 && flag == 0 && prc1 == 0)
		rval += ft_print_xchar(' ', size - strlen - prc1);
	rval += ft_putstr("0x");
	strlen -= 2;
	if (prc1 != 0)
		rval += ft_print_xchar('0', prc1 - strlen);
	if (prc != -1)
		rval += ft_putstr(str);
	if (flag == '-')
		rval += ft_print_xchar(' ', size - rval);
	return (rval);
}
