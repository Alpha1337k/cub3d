/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 23:26:37 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:06:21 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_filter(char *buf, int *error)
{
	int		x;
	char	*rval;

	x = 0;
	while (buf[x] != '\n' && buf[x] != '\0')
		x++;
	if (buf[x] == '\n' && *error != -1)
	{
		x++;
		rval = ft_strdup(buf + x);
		if (rval == NULL)
			*error = -1;
		return (rval);
	}
	else
	{
		return (NULL);
	}
}

char	*ft_appendl(char *buf, int *nl)
{
	int		x;
	char	*rval;

	rval = 0;
	x = 0;
	while (buf[x] != 0 && buf[x] != '\n')
		x++;
	rval = ft_cut(buf, x);
	if (rval == NULL)
		*nl = -1;
	if (buf[x] == '\n')
		*nl = 1;
	else
		*nl = 0;
	return (rval);
}

char	*get_read(int *ret, int fd, char *buf)
{
	char		*tmp;
	char		*j;

	j = NULL;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (tmp == 0)
		return (0);
	while ((*ret != 0 && ft_contains(buf, "\n", ft_strlen(buf)) == 0)
		|| buf == NULL)
	{
		*ret = read(fd, tmp, BUFFER_SIZE);
		if (*ret == -1)
			return (0);
		tmp[*ret] = '\0';
		if (buf == NULL)
			buf = ft_strdup(tmp);
		else
		{
			j = ft_strnjoin(buf, tmp, ft_strlen(tmp));
			free(buf);
			buf = j;
		}
	}
	free(tmp);
	return (buf);
}

int		get_next_line(int fd, char **line)
{
	static char *buf = NULL;
	char		*j;
	int			ret;
	int			nl;

	nl = 0;
	ret = 1;
	if (!ft_contains(buf, "\n", ft_strlen(buf)) || buf == NULL)
		buf = get_read(&ret, fd, buf);
	if (buf == 0 || fd < 0 || !line)
		return (-1);
	if (*buf != 0)
	{
		*line = ft_appendl(buf, &nl);
		j = ft_filter(buf, &nl);
		free(buf);
		buf = j;
	}
	else
		*line = ft_strdup("");
	if (*line == NULL || nl == -1)
		return (-1);
	if (ret >= 1 || nl == 1 || ft_strlen(buf))
		return (1);
	return (ret);
}
