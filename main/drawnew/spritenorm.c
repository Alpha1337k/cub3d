/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spritenorm.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 23:24:10 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/19 00:51:09 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	ft_bubble_sort_sprites(int amount_sprites, t_sprite *sprite)
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

void    ft_sprite_setup(t_meta *md, t_dda_sprite *sp)
{
    sp->mappos.x = (int)md->pos.x;
    sp->mappos.y = (int)md->pos.y;
    sp->spriteorder = malloc(sizeof(int) * md->spritecount);
    sp->spritedist = malloc(sizeof(double) * md->spritecount);
}

void    ft_calculate_sprite(t_meta *md, t_dda_sprite *sp, int x, t_vec3 *coords)
{
    sp->spritexy.x = md->sprite[sp->spriteorder[x]].pos.x - md->pos.x;
    sp->spritexy.y = md->sprite[sp->spriteorder[x]].pos.y - md->pos.y;
    sp->invdet = 1.0 / (md->plane.x * md->dir.y - md->dir.x * md->plane.y); //required for correct matrix multiplication
    sp->transform.x = sp->invdet * (md->dir.y * sp->spritexy.x  - md->dir.x * sp->spritexy.y);
    sp->transform.y = sp->invdet * (-md->plane.y * sp->spritexy.x  + md->plane.x * sp->spritexy.y); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])
    sp->spritescreen.x = (int)((md->res.x / 2) * (1 + sp->transform.x / sp->transform.y));
    sp->spritescreen.y = abs((int)(md->res.y / (sp->transform.y))) / 1;
    sp->movescreen = (int)(0 / sp->transform.y);
    coords->y = -sp->spritescreen.y / 2 + md->res.y / 2 + sp->movescreen;
    coords->z = sp->spritescreen.y / 2 + md->res.y / 2 + sp->movescreen;
}

void    ft_draw_sprite(t_meta *md, t_dda_sprite *sp, t_img *img, t_vec3 *coords)
{
	t_cast cst;

    int spriteWidth = abs((int)(md->res.y / (sp->transform.y))) / 1;
    int drawStartX = -spriteWidth / 2 + sp->spritescreen.x;
    if(drawStartX < 0)
        drawStartX = 0;
    int drawEndX = spriteWidth / 2 + sp->spritescreen.x;
    if(drawEndX >= md->res.x)
        drawEndX = md->res.x - 1;
    for(int stripe = drawStartX; stripe < drawEndX; stripe++)
    {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + sp->spritescreen.x)) * 64 / spriteWidth) / 256;
        if(sp->transform.y > 0 && stripe > 0 && stripe < md->res.x && sp->transform.y < md->z_buf[stripe])
        {
			cst.dir = SP;
			cst.x_of = texX;
            coords->x = stripe;
            // printf("drawing at [%d][%d][%d]\n", coords->x, coords->y ,coords->z);
		  ft_draw_wall_part(*coords, cst, img, md);
        }
    }
}

void    ft_dda_sprites(t_meta *md, t_img *img)
{
    t_dda_sprite   sp;
    t_vec3         coords;

    ft_sprite_setup(md, &sp);
	for(int i = 0; i < md->spritecount; i++)
	{
		sp.spriteorder[i] = i;
		md->sprite[i].dist = ((md->pos.x - md->sprite[i].pos.x) * (md->pos.x  - md->sprite[i].pos.x) + (md->pos.y - md->sprite[i].pos.y) * (md->pos.y - md->sprite[i].pos.y)); //sqrt not taken, unneeded
    }
	ft_bubble_sort_sprites(md->spritecount, md->sprite);
    for(int i = 0; i < md->spritecount; i++)
    {
        ft_calculate_sprite(md, &sp, i, &coords);
        ft_draw_sprite(md, &sp, img, &coords);
    }
}