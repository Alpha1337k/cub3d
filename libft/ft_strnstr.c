/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 21:53:19 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:53:20 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	i;
	int		n_f;

	x = 0;
	if (needle == haystack || needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[0] != '\0' && x < len)
	{
		i = 0;
		n_f = 0;
		while (n_f != -1 && i < len - x + 1)
		{
			if (needle[i] == 0)
				return ((char *)haystack);
			if (haystack[i] != needle[i])
				n_f = -1;
			else
				i++;
		}
		haystack++;
		x++;
	}
	return (0);
}
