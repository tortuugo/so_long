/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:35:28 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/29 18:07:22 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_stack(char *line, t_list **list)
{
	t_list	*nodo;
	t_list	*i;
	
	nodo = (t_list *) malloc (sizeof(t_list));
	if (!nodo)
		return ;
	nodo->content = line;
	nodo->next = NULL;
	i = *list;
	if (*list)
    {
        while (i->next)
            i = i->next;
        i->next = nodo;
    }
    else
	{
        *list = nodo;
		(*list)->cont = 0;
	}
    (*list)->cont++;
}

int	read_fd()
{
	int	fd;
	
	fd = open("map1.ber", O_RDONLY);
	if (fd < 0)
		return (0);
	return (fd);
}

void	create_map(t_game *game, t_list *list, int tam)
{
	int	i;

	i = 0;
	game->map = malloc(sizeof(char *) * (tam + 1));
	while (i < tam)
	{
		game->map[i] = list->content;
		i++;
		list = list->next;
	}
	game->colums = ft_strlen(game->map[0]) - 1;
	game->rows = tam;
	game->map[i] = NULL;
}

void	get_map(t_game *game)
{
	t_list	*list;
	char	*line;
	int		fd;
	
	fd = read_fd();
	list = NULL;
	game->map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		add_stack(line, &list);
	}
	create_map(game, list, list->cont);
	free(list);
	check_map(game);
}
