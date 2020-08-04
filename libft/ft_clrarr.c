/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_clrarr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 00:53:05 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:54:51 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_clrarr(char **ar)
{
	int x;

	x = 0;
	while (ar[x])
	{
		free(ar[x]);
		x++;
	}
	free(ar);
	return (0);
}
