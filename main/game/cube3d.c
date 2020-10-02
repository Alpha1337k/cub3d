/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube3d.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 20:52:25 by okruitho      #+#    #+#                 */
/*   Updated: 2020/10/02 09:38:22 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_run_loops(t_meta *md)
{
	mlx_do_key_autorepeatoff(md->mlx);
	if (!md->arg)
	{
		mlx_hook(md->win, 17, 1L << 5, ft_exit, md);
		mlx_hook(md->win, 02, 1L << 0, ft_set_keydown, md);
		mlx_hook(md->win, 03, 1L << 1, ft_set_keyup, md);
	}
	mlx_loop_hook(md->mlx, ft_render, md);
	mlx_loop(md->mlx);
}

int		main(int argc, char **argv)
{
	t_meta	md;

	ft_reset_md(&md);
	if (argc < 2 || argc > 3)
		return (0);
	if (argc == 3)
		md.arg = argv[2];
	else
		md.arg = 0;
	if (md.arg && ft_strncmp(md.arg, "--save", 7) != 0)
		ft_throw_error("use --save as optional argument", &md);
	md.mlx = mlx_init();
	if (md.mlx == 0)
		ft_throw_error("mlx failed to initialize", &md);
	md = ft_parse_data(argv[1], md);
	if (ft_check_input(&md) == 0)
		ft_exit(&md);
	ft_init_mlx(&md);
	ft_run_loops(&md);
	return (0);
}
