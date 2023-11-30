/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:28:59 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/29 23:17:15 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int		draw_sprite(t_game *game)
{
	if(!game->spr->enemy)
		printf("as\n");
	else
	{
		mlx_put_image_to_window(game->mlx, game->window, game->spr->enemy, 64, 64);
		mlx_put_image_to_window(game->mlx, game->window, game->spr->exit, 192, 64);
		mlx_put_image_to_window(game->mlx, game->window, game->spr->fenix[0], 600, 500);
	}
	return (0);
}*/

int	input(int num, t_game *game)
{
	if (num == 53)
	{
		mlx_destroy_window(game->mlx, game->window);
		exit(0);
	}
	if (num == 0)
		move_left(game);
	if (num == 1)
		move_down(game);
	if (num == 2)
		move_right(game);
	if (num == 13)
		move_up(game);
	if (num == 123)
		move_left(game);
	if (num == 125)
		move_down(game);
	if (num == 124)
		move_right(game);
	if (num == 126)
		move_up(game);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.map = NULL;
	get_map(&game);
	game.spr = (t_sprites *) malloc (sizeof(t_sprites));
	if (!game.spr)
		return (0);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		perror("error opening file");
		exit (1);
	}
	game.window = mlx_new_window(game.mlx, 128 * game.colums, 128 * game.rows, "un juego pero muyyy guaaapo");
	if (!game.window)
	{
		perror("unable to create window");
		exit (1);
	}
	inizialite_sprites(&game, 42);
	//mlx_loop_hook(game.window, draw_map, &game);
	mlx_hook(game.window, 2, 0, input, &game);
	mlx_loop_hook(game.mlx, draw_map, &game);
	mlx_loop(game.mlx);
}
