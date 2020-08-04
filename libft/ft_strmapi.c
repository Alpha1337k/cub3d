/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 21:53:28 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:53:29 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rval;
	size_t	x;
	size_t	s_len;

	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	x = 0;
	rval = malloc(sizeof(char) * s_len + 1);
	if (rval == 0)
		return (0);
	while (x < s_len)
	{
		rval[x] = f(x, s[x]);
		x++;
	}
	rval[x] = '\0';
	return (rval);
}
