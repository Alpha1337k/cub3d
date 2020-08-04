/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_istype.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:34:28 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 22:01:00 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isalpha(int c)
{
	if (c >= 65 && c <= 122)
	{
		if (c >= 91 && c <= 96)
			return (0);
		else
			return (1);
	}
	else
		return (0);
}

int		ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_isflag(int c)
{
	if (c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	return (0);
}
