/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:48:36 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/28 16:41:58 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	inizialite_corners(t_game *game, int t)
{
	game->spr->ULcorner[0] = mlx_xpm_file_to_image(game->mlx, ULC1, &t, &t);
	game->spr->ULcorner[1] = mlx_xpm_file_to_image(game->mlx, ULC2, &t, &t);
	game->spr->URcorner[0] = mlx_xpm_file_to_image(game->mlx, URC1, &t, &t);
	game->spr->URcorner[1] = mlx_xpm_file_to_image(game->mlx, URC2, &t, &t);
	game->spr->DLcorner[0] = mlx_xpm_file_to_image(game->mlx, DLC1, &t, &t);
	game->spr->DLcorner[1] = mlx_xpm_file_to_image(game->mlx, DLC2, &t, &t);
	game->spr->DRcorner[0] = mlx_xpm_file_to_image(game->mlx, DRC1, &t, &t);
	game->spr->DRcorner[1] = mlx_xpm_file_to_image(game->mlx, DRC2, &t, &t);
}

void	inizialite_sprites(t_game *game, int t)
{
	game->spr->fenix[0] = mlx_xpm_file_to_image(game->mlx, FENIX_DER, &t, &t);
	game->spr->fenix[1] = mlx_xpm_file_to_image(game->mlx, FENIX_IZQ, &t, &t);
	game->spr->koi[0] = mlx_xpm_file_to_image(game->mlx, KOI_DER, &t, &t);
	game->spr->koi[1] = mlx_xpm_file_to_image(game->mlx, KOI_IZQ, &t, &t);
	game->spr->enemy = mlx_xpm_file_to_image(game->mlx, ENEMY, &t, &t);
	game->spr->low_wall[0] = mlx_xpm_file_to_image(game->mlx, D_W1, &t, &t);
	game->spr->low_wall[1] = mlx_xpm_file_to_image(game->mlx, D_W2, &t, &t);
	game->spr->right_wall[0] = mlx_xpm_file_to_image(game->mlx, R_W1, &t, &t);
	game->spr->right_wall[1] = mlx_xpm_file_to_image(game->mlx, R_W2, &t, &t);
	game->spr->left_wall[0] = mlx_xpm_file_to_image(game->mlx, L_W1, &t, &t);
	game->spr->left_wall[1] = mlx_xpm_file_to_image(game->mlx, L_W2, &t, &t);
	game->spr->up_wall[0] = mlx_xpm_file_to_image(game->mlx, U_W1, &t, &t);
	game->spr->up_wall[1] = mlx_xpm_file_to_image(game->mlx, U_W2, &t, &t);
	game->spr->inside_wall[0] = mlx_xpm_file_to_image(game->mlx, I_W1, &t, &t);
	game->spr->inside_wall[1] = mlx_xpm_file_to_image(game->mlx, I_W2, &t, &t);
	game->spr->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &t, &t);
	game->spr->floor[0] = mlx_xpm_file_to_image(game->mlx, FLOOR1, &t, &t);
	game->spr->floor[1] = mlx_xpm_file_to_image(game->mlx, FLOOR2, &t, &t);
	inizialite_corners(game, t);
}

int	draw_map(t_game *game)
{
	int		i;
	int		j;
	static	int anim;

	i = 0;
	j = 0;
	anim++;
	if (anim == 149)
		anim = 0;
	//print_map(game->map);
	while (i < game->rows)
	{
		j = 0;
		while (j < game->colums)
		{
			if (i == 0 && j == 0)
				mlx_put_image_to_window(game->mlx, game->window, game->spr->ULcorner[anim/75], 128 * j, 128 * i);
			else if (i == game->rows - 1 && j == 0)
				mlx_put_image_to_window(game->mlx, game->window, game->spr->DLcorner[anim/75],128 * j, 128 * i);
			else if (i == 0 && j == game->colums - 1)
				mlx_put_image_to_window(game->mlx, game->window, game->spr->URcorner[anim/75], 128 * j, 128 * i);
			else if (i == game->rows - 1 && j == game->colums - 1)
				mlx_put_image_to_window(game->mlx, game->window, game->spr->DRcorner[anim/75], 128 * j, 128 * i);
			else if (i == 0)
				mlx_put_image_to_window(game->mlx, game->window, game->spr->up_wall[anim/75], 128 * j, 128 * i);
			else if (j == 0)
				mlx_put_image_to_window(game->mlx, game->window, game->spr->left_wall[anim/75], 128 * j, 128 * i);
			else if (j == game->colums - 1)
				mlx_put_image_to_window(game->mlx, game->window, game->spr->right_wall[anim/75], 128 * j, 128 * i);
			else if (i == game->rows - 1)
				mlx_put_image_to_window(game->mlx, game->window, game->spr->low_wall[anim/75], 128 * j, 128 * i);
			else 
			{
				mlx_put_image_to_window(game->mlx, game->window, game->spr->floor[anim/75], 128 * j, 128 * i);
				if (game->map[i][j] == '1')
					mlx_put_image_to_window(game->mlx, game->window, game->spr->inside_wall[anim/75], 128 * j, 128 * i);
				else if (game->map[i][j] == 'C')
					mlx_put_image_to_window(game->mlx, game->window, game->spr->koi[anim/75], 128 * j, 128 * i);
				else if (game->map[i][j] == 'P')
					mlx_put_image_to_window(game->mlx, game->window, game->spr->fenix[game->dir_p], 128 * j, 128 * i);
				else if (game->map[i][j] == 'E')
					mlx_put_image_to_window(game->mlx, game->window, game->spr->exit, 128 * j, 128 * i);
			}
			j++;
		}
		i++;
	}
	return (1);
}