/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 21:53:50 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:53:51 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_rval(size_t d_l, const char *src, size_t dstsize)
{
	size_t s_l;

	s_l = ft_strlen(src);
	if (dstsize <= d_l)
		return (s_l + dstsize);
	return (d_l + s_l);
}

size_t					ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t x;
	size_t i;
	size_t str_l;

	str_l = ft_strlen(src);
	x = 0;
	i = 0;
	if (dstsize == 0)
		return (str_l);
	str_l = ft_strlen(dst);
	while (dst[x] != '\0' && x < dstsize)
		x++;
	while (x < dstsize - 1 && src[i] != 0)
	{
		dst[x] = src[i];
		x++;
		i++;
	}
	if (i != 0)
		dst[x] = 0;
	return (ft_rval(str_l, src, dstsize));
}
