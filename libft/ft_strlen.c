/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 21:53:37 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:53:39 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *s)
{
	int x;

	x = 0;
	while (s[x] != 0)
	{
		x++;
	}
	return (x);
}
