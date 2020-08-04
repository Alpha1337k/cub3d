/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/06 19:34:21 by okruitho      #+#    #+#                 */
/*   Updated: 2020/08/04 18:14:45 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

unsigned char	*ft_get_info(t_meta *md)
{
	unsigned char *rval;

	rval = malloc(sizeof(char) * 40);
	if (rval == 0)
		return (0);
	ft_bzero(rval, 40);
	rval[0] = 40;
	rval[4] = md->res.x;
	rval[5] = md->res.x >> 8;
	rval[6] = md->res.x >> 16;
	rval[7] = md->res.x >> 24;
	rval[8] = md->res.y;
	rval[9] = md->res.y >> 8;
	rval[10] = md->res.y >> 16;
	rval[11] = md->res.y >> 24;
	rval[12] = 1;
	rval[14] = 32;
	return (rval);
}

unsigned char	*ft_get_header(t_meta *md, int padding)
{
	unsigned char	*rval;
	int				size;

	rval = malloc(sizeof(char) * 14);
	if (rval == 0)
		return (0);
	ft_bzero(rval, 14);
	size = 54 + (4 * md->res.x + padding) * md->res.y;
	rval[0] = 'B';
	rval[1] = 'M';
	rval[2] = size;
	rval[3] = size >> 8;
	rval[4] = size >> 16;
	rval[5] = size >> 24;
	rval[10] = 54;
	return (rval);
}

void			ft_write_bmp(t_img *img, int fd, t_meta *md, int padding_size)
{
	int		y;
	int		x;
	char	padding[3];

	ft_bzero(padding, 3);
	y = md->res.y - 1;
	while (y > 0)
	{
		x = 0;
		while (x < md->res.x)
		{
			write(fd, img->addr + (y * img->line_length + x * \
				img->bits_per_pixel / 8), sizeof(int));
			x++;
		}
		write(fd, padding, padding_size);
		y--;
	}
}

void			ft_generate_bmp(t_img *img, t_meta *md)
{
	unsigned char	*bmp_header;
	unsigned char	*bmp_info;
	int				padding_size;
	int				fd;

	padding_size = (4 - (md->res.x * 4) % 4) % 4;
	bmp_header = ft_get_header(md, padding_size);
	bmp_info = ft_get_info(md);
	if (!bmp_header || !bmp_info)
		ft_throw_error("malloc fail!", md);
	fd = open("save.bmp", O_CREAT | O_TRUNC | O_RDWR, 0644);
	write(fd, bmp_header, 14);
	write(fd, bmp_info, 40);
	ft_write_bmp(img, fd, md, padding_size);
	close(fd);
	free(bmp_header);
	free(bmp_info);
}

void			ft_save_bmp(t_img *img, t_meta *md)
{
	ft_generate_bmp(img, md);
}
