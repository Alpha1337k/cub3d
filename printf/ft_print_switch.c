/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_switch.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 22:00:21 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 22:00:22 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_print_manager(const char *c, void *val, int *size, int *flag)
{
	char *str;

	str = 0;
	while (ft_isalpha(c[0]) == 0 && c[0] != '%')
		c++;
	if (ft_contains(c, "diuxX", 1))
		str = ft_get_num(c, val);
	if (ft_contains(c, "csp%", 1))
		str = ft_get_str(c, val);
	if (*size < 0 && str[0] != 0)
	{
		*size *= -1;
		*flag = '-';
	}
	return (str);
}

const char	*ft_get_flag(const char *c, int *flag)
{
	if (ft_isflag(c[0]) == 1)
	{
		*flag = c[0];
		while (ft_isflag(c[0]))
		{
			if (*flag == '0' && c[0] == '-')
				*flag = c[0];
			c++;
		}
	}
	return (c);
}

const char	*ft_get_params(const char *c, int *size, int *prc, int *prcalt)
{
	if (c[0] != '.' && c[0] != '*' && *prc == -1)
	{
		*size = ft_atoi(c);
		while (ft_isnum(c[0]) == 1)
			c++;
	}
	if (c[0] == '*')
		c++;
	if (c[0] == '.' && c[1] != '*' && *prc == -1)
	{
		*prc = ft_atoi(&c[1]);
		if (*prc == 0)
			*prcalt = 1;
	}
	return (c);
}

int			ft_prc_exep(int prc, int prcalt)
{
	if (prc < 0)
		prc = 0;
	if (prcalt == 1 && prc == 0)
		prc = -1;
	if (prcalt == 0 && prc < -1)
		prc = 0;
	return (prc);
}

int			ft_print_type(const char *c, int size, int prc, void *val)
{
	int		flag;
	int		rval;
	char	*str;
	int		prcalt;

	rval = 0;
	prcalt = prc == 0 ? 1 : 0;
	flag = 0;
	c = ft_get_flag(c, &flag);
	c = ft_get_params(c, &size, &prc, &prcalt);
	while (ft_isalpha(c[0]) == 0 && c[0] != '%')
		c++;
	str = ft_print_manager(c, val, &size, &flag);
	prc = ft_prc_exep(prc, prcalt);
	if (ft_contains(c, "diuxX", 1))
		rval += ft_print_num(str, prc, flag, size);
	else if (ft_contains(c, "s%", 1))
		rval += ft_print_str(str, prc, flag, size);
	else if (ft_contains(c, "c", 1))
		rval += ft_print_c(str, prc, flag, size);
	else if (ft_contains(c, "p", 1))
		rval += ft_print_p(str, prc, flag, size);
	if (str != 0)
		free(str);
	return (rval);
}
