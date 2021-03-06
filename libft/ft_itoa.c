/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 21:56:20 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:56:07 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_setarr(int len, int n, int is_n)
{
	char	*rval;
	int		max;

	len = len + is_n;
	max = len;
	rval = (char *)malloc(sizeof(char) * len + 1);
	if (rval == 0)
		return (0);
	len -= 1;
	while (n != 0)
	{
		if (is_n == 1)
		{
			rval[0] = '-';
			is_n = 0;
		}
		rval[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	rval[max] = 0;
	return (rval);
}

char			*ft_itoa(int n)
{
	int		x;
	int		len;
	int		is_n;
	char	*rval;

	len = 0;
	is_n = 0;
	x = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		is_n = 1;
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		n *= -1;
	}
	while (x != 0)
	{
		x /= 10;
		len++;
	}
	rval = ft_setarr(len, n, is_n);
	return (rval);
}
