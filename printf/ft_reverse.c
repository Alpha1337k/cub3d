/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_reverse.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 22:00:02 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 22:00:03 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_reverse(char *str)
{
	char	*rval;
	int		x;
	int		i;

	i = 0;
	x = ft_strlen(str);
	rval = malloc(sizeof(char) * x + 1);
	if (rval == 0)
		return (0);
	x--;
	while (x != -1)
	{
		rval[i] = str[x];
		x--;
		i++;
	}
	rval[i] = 0;
	return (rval);
}
