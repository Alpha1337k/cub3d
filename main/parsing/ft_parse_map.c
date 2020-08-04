/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 20:51:35 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/24 14:00:39 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

char		*ft_appendnl(char *str)
{
	char	*rval;
	int		x;

	x = 0;
	rval = malloc(sizeof(char) * ft_strlen(str) + 2);
	if (rval == 0)
		return (0);
	while (str[x] != 0)
	{
		rval[x] = str[x];
		x++;
	}
	rval[x] = '\n';
	rval[x + 1] = '\0';
	return (rval);
}

char		*ft_free_unparsed(char *a, char *b, char *c)
{
	if (a)
		free(a);
	if (b)
		free(b);
	if (c)
		free(c);
	return (0);
}

char		*ft_get_unparsed(char *line, int fd, int *x, int *y)
{
	char	*rval;
	char	*tmp;
	char	*j;
	int		ret;

	ret = 1;
	tmp = ft_appendnl(line);
	free(line);
	rval = ft_strnjoin("", tmp, ft_strlen(tmp));
	free(tmp);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		tmp = ft_appendnl(line);
		if (tmp == 0)
			return (ft_free_unparsed(tmp, 0, line));
		*x = ((int)ft_strlen(tmp) > *x) ? ft_strlen(tmp) : *x;
		j = ft_strnjoin(rval, tmp, ft_strlen(tmp));
		if (j == 0)
			return (ft_free_unparsed(tmp, j, line));
		ft_free_unparsed(rval, tmp, line);
		rval = j;
		*y += 1;
	}
	return (rval);
}

t_map		ft_get_map(char *line, int fd)
{
	t_map	rval;
	int		x;
	int		y;

	x = 0;
	y = 0;
	rval.unp = ft_get_unparsed(line, fd, &x, &y);
	if (rval.unp == 0 || y == 0)
		return (rval);
	rval.val = ft_split(rval.unp, '\n');
	if (rval.val == 0)
		return (rval);
	rval.height = y;
	rval.width = x;
	rval.status = 1;
	return (rval);
}
