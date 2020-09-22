/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/22 21:50:24 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/22 21:58:48 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static const char	*ft_skip_wh_space(const char *str)
{
	if (!((*str == '\0') || (*str >= '0' && *str <= '9')))
	{
		while (*str == ' ' || *str == '\t' || *str == '\n' || \
		*str == '\v' || *str == '\f' || *str == '\r')
			str++;
	}
	return (str);
}

long long			ft_atol(const char *str)
{
	int					sign;
	unsigned long long	res;

	sign = 1;
	res = 0;
	str = ft_skip_wh_space(str);
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if (res > INT_MAX && sign == -1)
			return (-1);
		if (res > INT_MAX && sign == 1)
			return (-1);
		str++;
	}
	return ((int)res * sign);
}
