/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgb.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 00:20:26 by okruitho      #+#    #+#                 */
/*   Updated: 2020/10/02 12:24:20 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int				ft_rgb_to_int(t_rgb clr)
{
	unsigned int rval;

	rval = clr.a;
	rval = rval * 256 + clr.r;
	rval = rval * 256 + clr.g;
	rval = rval * 256 + clr.b;
	return (rval);
}

unsigned char	ft_set_nmb(char *s, unsigned char *err)
{
	int rval;

	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	if (ft_isnum(*s) == 0)
		*err = 0;
	rval = atoi(s);
	if (rval < 0 || rval > 255 || (rval == 0 && *s != '0'))
		*err = 0;
	return (rval);
}

char			*ft_move_tnmb(char *s)
{
	while (*s && *s != ',')
		s++;
	if (*s == ',')
		s++;
	return (s);
}

unsigned int	ft_rtoi(char *s)
{
	t_rgb rgb;

	rgb.a = 1;
	rgb.r = ft_set_nmb(s, &rgb.a);
	s = ft_move_tnmb(s);
	rgb.g = ft_set_nmb(s, &rgb.a);
	s = ft_move_tnmb(s);
	rgb.b = ft_set_nmb(s, &rgb.a);
	while (ft_isnum(*s))
		s++;
	if (*s != 0)
		rgb.a = 0;
	return (ft_rgb_to_int(rgb));
}

unsigned int	ft_get_color(char *line)
{
	return (*(unsigned int *)line);
}
