/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 21:53:09 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:53:10 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	x;
	size_t	i;
	char	*rval;
	size_t	s_l;

	if (s == 0)
		return (0);
	s_l = ft_strlen(s);
	if (s_l < start)
		return (ft_strdup(""));
	rval = (char *)malloc((sizeof(char) * len) + 1);
	if (rval == 0)
		return (0);
	x = start;
	i = 0;
	while (i < len && s[x] != '\0')
	{
		rval[i] = s[x];
		i++;
		x++;
	}
	rval[i] = '\0';
	return (rval);
}
