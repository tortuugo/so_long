/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:32:34 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/29 19:07:12 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)	
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	check_map(t_game *game)
{
	int	i;
	int j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->colums)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'E' && game->map[i][j] != 'P')
			{
				printf("%c\n", game->map[i][j]);
				exit (0);
			}
			if (game->map[i][j] == 'P')
			{
				game->col_p = j;
				game->row_p = i;
			}
			j++;
		}
		i++;
	}
	game->dir_p = 0;
	return (1);
}