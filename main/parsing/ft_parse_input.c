/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 22:46:26 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/18 22:41:23 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int			ft_check_extention(char *line, char seperator)
{
	while (*line)
	{
		if (*line == seperator)
			break ;
		line++;
	}
	if (*line)
		return (ft_strncmp(line, ".cub", 5));
	return (-1);
}

t_vec2		ft_get_res(t_meta *md, char *line)
{
	t_vec2 rval;
	t_vec2 tempval;

	rval.x = ft_atoi(line + 2);
	while (ft_isnum(*line) == 0)
		line++;
	while (ft_isnum(*line) && *line)
		line++;
	rval.y = ft_atoi(line);
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

void		ft_parse_switch(char *line, t_meta *data, int fd)
{
	if (ft_strnstr(line, "R ", 2))
		data->res = ft_get_res(data, line);
	else if (ft_strnstr(line, "F ", 2))
		data->fc[0] = ft_rtoi(line + 2);
	else if (ft_strnstr(line, "C ", 2))
		data->fc[1] = ft_rtoi(line + 2);
	else if (ft_strnstr(line, "1", ft_strlen(line)))
		data->map = ft_get_map(line, fd);
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
}

t_meta		ft_parse_data(char *path, t_meta md)
{
	int			fd;
	char		*line;
	int			ret;

	ret = 1;
	md.init = FALSE;
	if (ft_check_extention(path, '.') != 0)
		ft_throw_error("Bad file extention :|", &md);
	fd = open(path, O_RDONLY);
	if (fd == -1 || read(fd, 0, 0) == -1)
		ft_throw_error("Initalization failed. See if file is OK", &md);
	while (ret > 0 && md.map.status != 1)
	{
		ret = get_next_line(fd, &line);
		ft_parse_switch(line, &md, fd);
		if (md.map.status != 1)
			free(line);
	}
	ft_get_spritepos(&md);
	md.z_buf = malloc(sizeof(double) * md.res.x);
	ft_printf("All data has been read!\n");
	if (md.map.status == 1)
		ft_set_pos(&md);
	md.init = TRUE;
	return (md);
}
