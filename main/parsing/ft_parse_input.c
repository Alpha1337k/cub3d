/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 22:46:26 by okruitho      #+#    #+#                 */
/*   Updated: 2020/10/02 11:48:56 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int			ft_check_extention(char *line)
{
	int x;

	x = ft_strlen(line);
	if (x < 4)
		return (-1);
	x -= 4;
	if (ft_strncmp(&line[x], ".cub", 5) == 0)
		return (0);
	return (-1);
}

t_vec2		ft_get_res(t_meta *md, char *line)
{
	t_vec2 rval;
	t_vec2 tempval;

	rval.x = ft_atol(line + 2);
	while (ft_isnum(*line) == 0)
		line++;
	while (ft_isnum(*line) && *line)
		line++;
	rval.y = ft_atol(line);
	line++;
	while (ft_isnum(*line) && *line)
		line++;
	if (*line != 0)
		ft_throw_error("more arguments than needed used for res", md);
	if (!LINUX)
	{
		mlx_get_screen_size(md, &tempval.x, &tempval.y);
		if (rval.x < 1 || rval.y < 1)
			ft_throw_error("Invalid res!", md);
		if ((unsigned int)rval.x > (unsigned int)tempval.x && !md->arg)
			rval.x = tempval.x;
		if ((unsigned int)rval.y > (unsigned int)tempval.y && !md->arg)
			rval.y = tempval.y;
	}
	return (rval);
}

void		ft_check_double(char *line, t_meta *md)
{
	if (*line == 0 || !line)
		return ;
	if (ft_strnstr(line, "R ", 2) && md->res.x && md->res.y)
		ft_throw_error("double inclusion of R.", md);
	else if (ft_strnstr(line, "F ", 2) && md->fc[0])
		ft_throw_error("double inclusion of F.", md);
	else if (ft_strnstr(line, "C ", 2) && md->fc[1])
		ft_throw_error("double inclusion of C.", md);
	else if (ft_strnstr(line, "NO ", 3) && md->tx[NO].i.addr)
		ft_throw_error("double inclusion of NO.", md);
	else if (ft_strnstr(line, "SO ", 3) && md->tx[SO].i.addr)
		ft_throw_error("double inclusion of SO.", md);
	else if (ft_strnstr(line, "WE ", 3) && md->tx[WE].i.addr)
		ft_throw_error("double inclusion of WE.", md);
	else if (ft_strnstr(line, "EA ", 3) && md->tx[EA].i.addr)
		ft_throw_error("double inclusion of EA.", md);
	else if (ft_strnstr(line, "S ", 3) && md->tx[SP].i.addr)
		ft_throw_error("double inclusion of S.", md);
}

void		ft_parse_switch(char *line, t_meta *data, int fd)
{
	if (*line == 0 || !line)
		return ;
	if (ft_strnstr(line, "R ", 2))
		data->res = ft_get_res(data, line);
	else if (ft_strnstr(line, "F ", 2))
		data->fc[0] = ft_rtoi(line + 2);
	else if (ft_strnstr(line, "C ", 2))
		data->fc[1] = ft_rtoi(line + 2);
	else if (ft_strnstr(line, "NO ", 3))
		data->tx[NO] = ft_load_img(data, line + 3);
	else if (ft_strnstr(line, "SO ", 3))
		data->tx[SO] = ft_load_img(data, line + 3);
	else if (ft_strnstr(line, "WE ", 3))
		data->tx[WE] = ft_load_img(data, line + 3);
	else if (ft_strnstr(line, "EA ", 3))
		data->tx[EA] = ft_load_img(data, line + 3);
	else if (ft_strnstr(line, "S ", 3))
		data->tx[SP] = ft_load_img(data, line + 2);
	else if (ft_strnstr(line, "111", ft_strlen(line)))
		data->map = ft_get_map(line, fd);
	else
		ft_throw_error("Unknown item in file", data);
}

t_meta		ft_parse_data(char *path, t_meta md)
{
	int			fd;
	char		*line;
	int			ret;

	ret = 1;
	if (ft_check_extention(path) != 0)
		ft_throw_error("Bad file extention :|", &md);
	fd = open(path, O_RDONLY);
	if (fd == -1 || read(fd, 0, 0) == -1)
		ft_throw_error("Initalization failed. See if file is OK", &md);
	while (ret > 0 && md.map.status != 1)
	{
		ret = get_next_line(fd, &line);
		ft_check_double(line, &md);
		ft_parse_switch(line, &md, fd);
		if (md.map.status != 1)
			free(line);
	}
	if (md.map.status)
	{
		ft_get_spritepos(&md);
		md.z_buf = malloc(sizeof(double) * md.res.x);
		ft_set_pos(&md);
	}
	return (md);
}
