/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 22:01:09 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 22:01:10 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_gethexval(int mod)
{
	if (mod > 9)
		return ('A' + mod - 10 + 32);
	else
		return (mod + '0');
}

static char		*ft_tohex(unsigned long i, int m_size)
{
	char	*rval;
	int		x;

	x = 0;
	rval = malloc(sizeof(char) * m_size + 1);
	if (rval == 0)
		return (0);
	while (i != 0)
	{
		rval[x] = ft_gethexval(i % 16);
		i /= 16;
		x++;
	}
	rval[x] = 0;
	return (rval);
}

char			*ft_getptr(unsigned long ptr)
{
	char			*t_print;
	char			*rval;
	int				m_size;
	unsigned long	n;

	m_size = 0;
	n = ptr;
	if (n == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		n /= 16;
		m_size++;
	}
	t_print = ft_tohex(ptr, m_size);
	rval = ft_reverse(t_print);
	free(t_print);
	return (rval);
}
