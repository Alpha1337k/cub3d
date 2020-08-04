/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 17:11:44 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:55:21 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	s_len;

	if (src == 0)
		return (0);
	x = 0;
	s_len = ft_strlen(src);
	if (dstsize == 0)
		return (s_len);
	while (x < dstsize && src[x] != 0)
	{
		dst[x] = src[x];
		x++;
	}
	if (s_len >= dstsize)
		dst[x - 1] = '\0';
	else
		dst[x] = '\0';
	return (s_len);
}
