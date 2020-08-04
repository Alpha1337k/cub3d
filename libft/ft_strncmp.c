/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 21:52:03 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:52:05 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			x;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)s1;
	d = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (s[0] == '\0' && d[0] == '\0')
		return (0);
	x = 0;
	while (x < n)
	{
		if (s[x] != 0 && d[x] == 0)
			return (1);
		if (s[x] == 0 && d[x] != 0)
			return (-1);
		if (s[x] != d[x])
			return ((int)(s[x] - d[x]));
		if (s[x] == 0 && d[x] == 0)
			return (0);
		x++;
	}
	return (0);
}
