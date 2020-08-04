/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_gethex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 22:01:49 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 22:01:50 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_gethexval(int mod, int up)
{
	if (up == 1)
		up = 32;
	if (mod > 9)
		return ('A' + mod - 10 + up);
	else
		return (mod + '0');
}

char	*ft_tohex(unsigned int i, int m_size, int up)
{
	char	*rval;
	int		x;

	x = 0;
	rval = malloc(sizeof(char) * m_size + 1);
	if (rval == 0)
		return (0);
	while (i != 0)
	{
		rval[x] = ft_gethexval(i % 16, up);
		i /= 16;
		x++;
	}
	rval[x] = 0;
	return (rval);
}

char	*ft_gethex(unsigned int i, int up)
{
	char			*t_print;
	char			*rval;
	int				m_size;
	unsigned int	n;

	m_size = 0;
	n = i;
	if (n == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		n /= 16;
		m_size++;
	}
	t_print = ft_tohex(i, m_size, up);
	rval = ft_reverse(t_print);
	free(t_print);
	return (rval);
}
