#include "../includes/cube3d.h"

// static void	ft_bubble_sort_sprites(int amount_sprites, t_sprite *sprite)
// {
// 	t_sprite	swap;
// 	int			i;
// 	int			j;

// 	i = 0;
// 	while (i < amount_sprites - 1)
// 	{
// 		j = 0;
// 		while (j < amount_sprites - i - 1)
// 		{
// 			if (sprite[j].dist < sprite[j + 1].dist)
// 			{
// 				swap = sprite[j];
// 				sprite[j] = sprite[j + 1];
// 				sprite[j + 1] = swap;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }


// void	ft_draw_walls(t_meta *md, t_img *img)
// {
// 	double posX = md->pos.x, posY = md->pos.y;  //x and y start position
// //   double dirX = -1, dirY = 0; //initial direction vector
// //   double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
// 	// int spriteOrder[1];
// 	// double spriteDistance[1];
// 		for(int x = 0; x < md->res.x; x++)
// 		{
// 			//calculate ray position and direction
// 			double cameraX = 2 * x / (double)md->res.x - 1; //x-coordinate in camera space
// 			double rayDirX = md->dir.x + md->plane.x * cameraX;
// 			double rayDirY = md->dir.y + md->plane.y * cameraX;
// 			//which box of the map we're in
// 			int mapX = (int)posX;
// 			int mapY = (int)posY;

// 			//length of ray from current position to next x or y-side
// 			double sideDistX;
// 			double sideDistY;

// 			 //length of ray from one x or y-side to next x or y-side
// 			double deltaDistX = fabs(1 / rayDirX);
// 			double deltaDistY = fabs(1 / rayDirY);
// 			double perpWallDist;

// 			//what direction to step in x or y-direction (either +1 or -1)
// 			int stepX;
// 			int stepY;

// 			int hit = 0; //was there a wall hit?
// 			int side; //was a NS or a EW wall hit?
// 			//calculate step and initial sideDist
// 			if(rayDirX < 0)
// 			{
// 				stepX = -1;
// 				sideDistX = (posX - mapX) * deltaDistX;
// 			}
// 			else
// 			{
// 				stepX = 1;
// 				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
// 			}
// 			if(rayDirY < 0)
// 			{
// 				stepY = -1;
// 				sideDistY = (posY - mapY) * deltaDistY;
// 			}
// 			else
// 			{
// 				stepY = 1;
// 				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
// 			}
// 			//perform DDA
// 			while (hit == 0)
// 			{
// 				//jump to next map square, OR in x-direction, OR in y-direction
// 				if(sideDistX < sideDistY)
// 				{
// 					sideDistX += deltaDistX;
// 					mapX += stepX;
// 					side = 0;
// 				}
// 				else
// 				{
// 					sideDistY += deltaDistY;
// 					mapY += stepY;
// 					side = 1;
// 				}
// 				//Check if ray has hit a wall
// 				if(md->map.val[mapY][mapX] == '1') hit = 1;
// 			}
// 			//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
// 			if(side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
// 			else          perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

// 		// printf("wall distance: %f\n", perpWallDist);
// 			//Calculate height of line to draw on screen
// 			int lineHeight = (int)(md->res.y / perpWallDist);

// 			//calculate lowest and highest pixel to fill in current stripe
// 			int drawStart = -lineHeight / 2 + md->res.y / 2;
// 		//   if(drawStart < 0)drawStart = 0;
// 			int drawEnd = lineHeight / 2 + md->res.y / 2;
// 		//   if(drawEnd >= md->res.y)drawEnd = md->res.y - 1;

	
// 			int texWidth = 64;
// 			int texHeight = 64;
// 			//calculate value of wallX
// 			double wallX; //where exactly the wall was hit
// 			if(side == 0) wallX = posY + perpWallDist * rayDirY;
// 			else          wallX = posX + perpWallDist * rayDirX;
// 			wallX -= floor((wallX));
// 			//x coordinate on the texture
// 			int texX = (int)(wallX * (double)(texWidth));
// 			if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
// 			if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;
// 			// TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
// 			// How much to increase the texture coordinate per screen pixel
// 			double step = 1.0 * texHeight / lineHeight;
// 			// Starting texture coordinate
// 			double texPos = (drawStart - md->res.y / 2 + lineHeight / 2) * step;
// 			(void)texPos;

// 			t_cast cst;
// 			if (mapY < posY && side == 1)
// 				cst.dir = NO;
// 			else if (mapY > posY && side == 1)
// 				cst.dir = SO;
// 			else if (mapX > posX && side == 0)
// 				cst.dir = WE;
// 			else if (mapX < posX && side == 0)
// 				cst.dir = EA;

// 			md->z_buf[x] = perpWallDist; //perpendicular distance is used
// 			// printf("perdist:%f\n", perpWallDist);
// 					//draw the pixels of the stripe as a vertical line
// 				t_vec3 c;

// 				c.x = x;
// 				c.y = drawStart;
// 				c.z = drawEnd;
// 			cst.x_of = texX;
// 			//printf("draw at: [%d][%d][%d]\n", c.x,c.y,c.z);
// 					ft_draw_wall_part(c, cst, img, md);
// 	}

// 	//SPRITE CASTING
// 	//sort sprites from far to close
// 	int spriteOrder[md->spritecount];
// 	double spriteDistance[md->spritecount];

// 	for(int i = 0; i < md->spritecount; i++)
// 	{
// 		spriteOrder[i] = i;
// 		spriteDistance[i] = ((posX - md->sprite[i].pos.x) * (posX - md->sprite[i].pos.x) + (posY - md->sprite[i].pos.y) * (posY - md->sprite[i].pos.y)); //sqrt not taken, unneeded
// 	}
// 	ft_bubble_sort_sprites(md->spritecount, md->sprite);
//     for(int i = 0; i < md->spritecount; i++)
//     {
//       //translate sprite position to relative to camera
//       double spriteX = md->sprite[spriteOrder[i]].pos.x - posX;
//       double spriteY = md->sprite[spriteOrder[i]].pos.y - posY;

//       //transform sprite with the inverse camera matrix
//       // [ planeX   dirX ] -1                                       [ dirY      -dirX ]
//       // [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
//       // [ planeY   dirY ]                                          [ -planeY  planeX ]

//       double invDet = 1.0 / (md->plane.x * md->dir.y - md->dir.x * md->plane.y); //required for correct matrix multiplication

//       double transformX = invDet * (md->dir.y * spriteX - md->dir.x * spriteY);
//       double transformY = invDet * (-md->plane.y * spriteX + md->plane.x * spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])

//       int spriteScreenX = (int)((md->res.x / 2) * (1 + transformX / transformY));

//       //parameters for scaling and moving the sprites
//       #define uDiv 1
//       #define vDiv 1
//       #define vMove 0.0
//       int vMoveScreen = (int)(vMove / transformY);

//       //calculate height of the sprite on screen
//       int spriteHeight = abs((int)(md->res.y / (transformY))) / vDiv; //using "transformY" instead of the real distance prevents fisheye

//       //calculate lowest and highest pixel to fill in current stripe
//       int drawStartY = -spriteHeight / 2 + md->res.y / 2 + vMoveScreen;
//       if(drawStartY < 0) drawStartY = 0;
//       int drawEndY = spriteHeight / 2 + md->res.y / 2 + vMoveScreen;
//       if(drawEndY >= md->res.y) drawEndY = md->res.y - 1;

//       //calculate width of the sprite
//       int spriteWidth = abs( (int) (md->res.y / (transformY))) / uDiv;
//       int drawStartX = -spriteWidth / 2 + spriteScreenX;
//       if(drawStartX < 0) drawStartX = 0;
//       int drawEndX = spriteWidth / 2 + spriteScreenX;
//       if(drawEndX >= md->res.x) drawEndX = md->res.x - 1;

//       //loop through every vertical stripe of the sprite on screen
//       for(int stripe = drawStartX; stripe < drawEndX; stripe++)
//       {
//         int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * 64 / spriteWidth) / 256;
//         //the conditions in the if are:
//         //1) it's in front of camera plane so you don't see things behind you
//         //2) it's on the screen (left)
//         //3) it's on the screen (right)
//         //4) ZBuffer, with perpendicular distance
//         if(transformY > 0 && stripe > 0 && stripe < md->res.x && transformY < md->z_buf[stripe])
//         //for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
//         {
//           //int d = (y-vMoveScreen) * 256 - md->res.y * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
//           //int texY = ((d * /*texheight */64) / spriteHeight) / 256;
// 			t_cast cst;
// 			cst.dir = SP;
// 			cst.x_of = texX;
// 			t_vec3 c;
// 			c.x = stripe;
// 			c.y = drawStartY;
// 			c.z = drawEndY;
// 		  ft_draw_wall_part(c, cst, img, md);
//         //   int color = texture[sprite[spriteOrder[i]].texture][64 * texY + texX]; //get current color from the texture
//         //   if((color & 0x00FFFFFF) != 0) buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
//         }
//       }
//     }
// }

void	ft_draw_walls(t_meta *md, t_img *img)
{
	ft_dda_walls(md, img);
	ft_dda_sprites(md, img);
}