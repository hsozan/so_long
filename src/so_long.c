/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:10:01 by hsozan            #+#    #+#             */
/*   Updated: 2022/10/25 23:12:55 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_img(t_game *g)
{
	int	x;
	int	y;

	x = 50;
	y = 50;
	g->img = malloc(sizeof(t_img));
	g->img->back = mlx_xpm_file_to_image(g->mlx, "xpm/a.xpm", &x, &y);
	g->img->door = mlx_xpm_file_to_image(g->mlx, "xpm/do.xpm", &x, &y);
	g->img->loot = mlx_xpm_file_to_image(g->mlx, "xpm/giveyouup.xpm", &x, &y);
	g->img->wall = mlx_xpm_file_to_image(g->mlx, "xpm/wall.xpm", &x, &y);
	g->img->player = mlx_xpm_file_to_image(g->mlx, "xpm/player.xpm", &x, &y);
}

void	draw_img_ul(t_game *g, int x, int y)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->window, g->img->wall,
			x * 50, y * 50);
	if (g->map[y][x] == '0')
		mlx_put_image_to_window(g->mlx, g->window, g->img->back,
			x * 50, y * 50);
	if (g->map[y][x] == 'P')
		mlx_put_image_to_window(g->mlx, g->window, g->img->player,
			x * 50, y * 50);
	if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->window, g->img->loot,
			x * 50, y * 50);
	if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->window, g->img->door,
			x * 50, y * 50);
}

void	draw_img(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->max_y)
	{
		x = 0;
		while (x < g->max_x)
		{
			draw_img_ul(g, x, y);
			x++;
		}
		y++;
	}
}

void	create_mlx(t_game *g)
{
	g->mlx = mlx_init();
	g->window = mlx_new_window(g->mlx, g->max_x * 50, g->max_y * 50, "so_long");
	put_img(g);
	draw_img(g);
	mlx_hook(g->window, 2, 0, key_func, g);
	mlx_loop_hook(g->mlx, redraw_map, g);
	mlx_hook(g->window, 17, 0, exit_hook, g);
	mlx_loop(g->mlx);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (ac != 2)
		ft_err('a', game);
	check_format(av[1], game);
	map_init(game, av[1]);
	check_map(game);
	create_mlx(game);
}
