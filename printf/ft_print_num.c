/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_num.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 06:16:58 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:05:35 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_num(const char *c, void *val)
{
	if (c[0] == 'd' || c[0] == 'i')
		return (ft_itoa((int)val));
	else if (c[0] == 'u' || c[0] == 'U')
		return (ft_utoa((unsigned int)val));
	else if (c[0] == 'x')
		return (ft_gethex((unsigned int)val, 1));
	else if (c[0] == 'X')
		return (ft_gethex((unsigned int)val, 0));
	return (0);
}

int		ft_calculate_size(int prc, int size, char *str)
{
	int rval;
	int is_n;

	is_n = 0;
	rval = 0;
	if (str[0] == '-')
		is_n = 1;
	if (prc < (int)ft_strlen(str))
		rval = size - ft_strlen(str);
	else
		rval = size - prc - is_n;
	return (rval);
}

int		ft_print_margin_n(char flag, int presize, int prc)
{
	if (flag != '-' && flag != '0')
		return (ft_print_xchar(' ', presize));
	if (flag == '0' && prc != 0)
		return (ft_print_xchar(' ', presize));
	return (0);
}

int		ft_print_padding(char flag, int presize, int prc1, char *str)
{
	if (flag == '0' && prc1 == 0)
		return (ft_print_xchar('0', presize));
	if (prc1 != 0)
		return (ft_print_xchar('0', prc1 - ft_strlen(str)));
	return (0);
}

int		ft_print_num(char *str, int prc, char flag, int size)
{
	int rval;
	int presize;
	int prc1;

	prc1 = prc == -1 ? 0 : prc;
	if (prc == -1)
		size++;
	presize = ft_calculate_size(prc1, size, str);
	rval = 0 + ft_print_margin_n(flag, presize, prc);
	if (str[0] == '-')
	{
		rval += ft_putchar('-');
		str++;
	}
	rval += ft_print_padding(flag, presize, prc1, str);
	if (prc != -1 || ft_atoi(str) != 0)
		rval += ft_putstr(str);
	if (flag == '-')
		rval += ft_print_xchar(' ', presize);
	return (rval);
}
