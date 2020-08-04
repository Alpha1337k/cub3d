/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 21:54:22 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:54:23 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else if (c >= 65 && c <= 122)
	{
		if (c >= 91 && c <= 96)
			return (0);
		else
			return (1);
	}
	else
		return (0);
}
