/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/08 22:58:08 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/12 20:16:03 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_vec2_d	ft_atc(double ang)
{
	t_vec2_d	rval;

	rval.x = cos(ang * 0.0174532925);
	rval.y = sin(ang * 0.0174532925);
	return (rval);
}

t_vec2		ft_vecmrg(int x, int y)
{
	t_vec2 rval;

	rval.x = x;
	rval.y = y;
	return (rval);
}
