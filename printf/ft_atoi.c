/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 22:01:26 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 22:01:27 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_strncmpaddon(unsigned char *s1)
{
	size_t	rval;
	int		flag;
	int		count;

	flag = 1;
	rval = 0;
	count = 0;
	if (s1[0] == '\0')
		return (0);
	if (s1[0] == '-')
	{
		flag = -1;
		s1++;
	}
	while ((s1[0] >= '0' && s1[0] <= '9'))
	{
		rval = rval * 10 + s1[0] - '0';
		s1++;
		count++;
	}
	if (count > 18 && flag == 1)
		return (-1);
	if (count > 18 && flag == -1)
		return (0);
	return ((int)rval * flag);
}

static int		ft_get_val(unsigned char *s)
{
	int tried;

	if (s[0] == '+' && s[1] == '-')
		return (0);
	if (s[0] == '+')
		s++;
	tried = ft_strncmpaddon(s);
	return (tried);
}

int				ft_atoi(const char *str)
{
	int				rval;
	unsigned char	*s;

	s = (unsigned char *)str;
	rval = 0;
	while (s[0] == 32 || (s[0] >= 9 && s[0] <= 13) ||
		s[0] == 133 || s[0] == 160)
		s++;
	rval = ft_get_val(s);
	return (rval);
}
