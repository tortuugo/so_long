/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:14:01 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/29 19:10:05 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->col_p;
	y = game->row_p;
	if (game->map[y][x - 1] == '1')
		return ;
	if (game->map[y][x - 1] == 'E')
		input(53, game);
	else
	{
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
	}
	game->col_p = x - 1;
	game->dir_p = 1;
}
void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->col_p;
	y = game->row_p;
	if (game->map[y - 1][x] == '1')
		return ;
	if (game->map[y - 1][x] == 'E')
		input(53, game);
	else
	{
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
	}
	game->row_p = y - 1;
}
void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->col_p;
	y = game->row_p;
	if (game->map[y][x + 1] == '1')
		return ;
	if (game->map[y][x + 1] == 'E')
		input(53, game);
	else
	{
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
	}
	game->col_p = x + 1;
	game->dir_p = 0;
}
void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->col_p;
	y = game->row_p;
	if (game->map[y + 1][x] == '1')
		return ;
	if (game->map[y + 1][x] == 'E')
		input(53, game);
	else
	{
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
	}
	game->row_p = y + 1;
}