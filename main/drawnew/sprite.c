/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 23:24:10 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/22 07:45:04 by alpha_1337    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void		ft_bubble_sort_sprites(int amount_sprites, t_sprite *sprite)
{
	t_sprite	swap;
	int			i;
	int			j;

	i = 0;
	while (i < amount_sprites - 1)
	{
		j = 0;
		while (j < amount_sprites - i - 1)
		{
			if (sprite[j].dist < sprite[j + 1].dist)
			{
				swap = sprite[j];
				sprite[j] = sprite[j + 1];
				sprite[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}

void		ft_sprite_setup(t_meta *md, t_dda_sprite *sp)
{
	sp->mappos.x = (int)md->pos.x;
	sp->mappos.y = (int)md->pos.y;
	sp->spriteorder = malloc(sizeof(int) * md->spritecount);
	sp->spritedist = malloc(sizeof(double) * md->spritecount);
}

void		ft_calc_sprite(t_meta *md, t_dda_sprite *sp, int x, t_vec3 *cd)
{
	sp->spritexy.x = md->sprite[sp->spriteorder[x]].pos.x - md->pos.x + 0.5;
	sp->spritexy.y = md->sprite[sp->spriteorder[x]].pos.y - md->pos.y + 0.5;
	sp->invdet = 1.0 / (md->plane.x * md->dir.y - md->dir.x * md->plane.y);
	sp->transform.x = sp->invdet * (md->dir.y * sp->spritexy.x - md->dir.x * \
		sp->spritexy.y);
	sp->transform.y = sp->invdet * (-md->plane.y * sp->spritexy.x + \
		md->plane.x * sp->spritexy.y);
	sp->spritescreen.x = (int)((md->res.x / 2) * \
		(1 + sp->transform.x / sp->transform.y));
	sp->spritescreen.y = abs((int)(md->res.y / (sp->transform.y))) / 1;
	sp->movescreen = (int)(0 / sp->transform.y);
	cd->y = -sp->spritescreen.y / 2 + md->res.y / 2 + sp->movescreen;
	cd->z = sp->spritescreen.y / 2 + md->res.y / 2 + sp->movescreen;
}

void		ft_draw_sprite(t_meta *md, t_dda_sprite *sp, t_img *img, t_vec3 *c)
{
	t_cast	cst;
	t_vec2	drawparam;
	int		sprite_w;

	sprite_w = abs((int)(md->res.y / (sp->transform.y))) / 1;
	drawparam.x = -sprite_w / 2 + sp->spritescreen.x;
	if (drawparam.x < 0)
		drawparam.x = 0;
	drawparam.y = sprite_w / 2 + sp->spritescreen.x;
	if (drawparam.y >= md->res.x)
		drawparam.y = md->res.x - 1;
	c->x = drawparam.x;
	while (c->x < drawparam.y)
	{
		sp->tex_x = (int)(256 * (c->x -  \
		(-sprite_w / 2 + sp->spritescreen.x)) * md->tx[SP].p.x / sprite_w) / 256;
		if (sp->transform.y > 0 && c->x > 0 && c->x <  \
		md->res.x && sp->transform.y < md->z_buf[c->x])
		{
			cst.dir = SP;
			cst.x_of = sp->tex_x;
			ft_draw_wall_part(*c, cst, img, md);
		}
		c->x++;
	}
}

void		ft_dda_sprites(t_meta *md, t_img *img)
{
	t_dda_sprite	sp;
	t_vec3			coords;
	int				x;

	ft_sprite_setup(md, &sp);
	x = 0;
	while (x < md->spritecount)
	{
		sp.spriteorder[x] = x;
		md->sprite[x].dist = ((md->pos.x - md->sprite[x].pos.x) * \
			(md->pos.x - md->sprite[x].pos.x) + \
			(md->pos.y - md->sprite[x].pos.y) * \
			(md->pos.y - md->sprite[x].pos.y));
		x++;
	}
	ft_bubble_sort_sprites(md->spritecount, md->sprite);
	x = 0;
	while (x < md->spritecount)
	{
		ft_calc_sprite(md, &sp, x, &coords);
		ft_draw_sprite(md, &sp, img, &coords);
		x++;
	}
	free(sp.spriteorder);
	free(sp.spritedist);
}
