/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:29:11 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/29 19:06:31 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# include "fcntl.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
    char			*content;
	int				cont;
    struct s_list	*next;
}					t_list;

typedef struct s_sprites
{
		void	*fenix[2];
		void	*koi[2];
		void	*low_wall[2];
		void	*right_wall[2];
		void	*left_wall[2];
		void	*up_wall[2];
		void	*inside_wall[2];
		void	*floor[2];
		void	*ULcorner[2];
		void	*URcorner[2];
		void	*DLcorner[2];
		void	*DRcorner[2];
		void	*exit;
		void	*enemy;
}				t_sprites;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	int			colums;
	int			rows;
	int			col_p;
	int			row_p;
	int			dir_p;
	t_sprites	*spr;
}			t_game;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*free_all(char **file);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);

int	input(int num, t_game *game);

void	create_map(t_game *game, t_list * list, int tam);
void	get_map(t_game *game);
int		read_fd();
void	print_map(char **map);
int		check_map(t_game *game);

void	inizialite_sprites(t_game *game, int t);
void	inizialite_corners(t_game *game, int t);
int		draw_map(t_game *game);

void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);

# define FENIX_DER "sprites/fenix_derecha.xpm"
# define FENIX_IZQ "sprites/fenix_izq.xpm"
# define KOI_IZQ "sprites/koi_izq.xpm"
# define KOI_DER "sprites/koi_der.xpm"
# define ENEMY "sprites/losmalos.xpm"
# define D_W1 "sprites/muro_abaj1.xpm"
# define D_W2 "sprites/muro_abaj2.xpm"
# define R_W1 "sprites/muro_der1.xpm"
# define R_W2 "sprites/muro_der2.xpm"
# define L_W1 "sprites/muro_izq1.xpm"
# define L_W2 "sprites/muro_izq2.xpm"
# define U_W1 "sprites/pared_arriba1.xpm"
# define U_W2 "sprites/pared_arriba2.xpm"
# define I_W1 "sprites/perro_dentro1.xpm"
# define I_W2 "sprites/perro_dentro2.xpm"
# define EXIT "sprites/salida.xpm"
# define FLOOR1 "sprites/suelo1.xpm"
# define FLOOR2 "sprites/suelo2.xpm"
# define DRC1 "sprites/E_A_D1.xpm"
# define DRC2 "sprites/E_A_D2.xpm"
# define DLC1 "sprites/E_A_I1.xpm"
# define DLC2 "sprites/E_A_I2.xpm"
# define URC1 "sprites/E_U_D1.xpm"
# define URC2 "sprites/E_U_D2.xpm"
# define ULC1 "sprites/E_U_I1.xpm"
# define ULC2 "sprites/E_U_I2.xpm"

#endif