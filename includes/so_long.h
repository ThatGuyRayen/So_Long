/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:33:52 by tpandya           #+#    #+#             */
/*   Updated: 2025/08/08 17:33:55 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* Includes: */
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

/* Define parameters: */
# define SIZE 32
# define HEIGHT 32
# define WIDTH 32

/* Define images: */
# define PLAYER "./textures/player.xpm"
# define EXIT_IMG "./textures/exit.xpm"
# define COLLECT_IMG "./textures/collect.xpm"
# define WALL_IMG "./textures/wall.xpm"
# define BG_IMG "./textures/bg.xpm"

/* Define keys: */
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

/* Game structure: */
typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_player;

	void	*img_exit;
	void	*img_collect;
	void	*img_wall;
	void	*img_bg;
	char	**map;
	char	**temp_map;
	int		img_width;
	int		img_height;
	int		map_rows;
	int		map_cols;
	int		player;
	int		pos_x;
	int		pos_y;
	int		exit;
	int		collect;
	int		collected;
	int		wall;
	int		background;
	int		moves;
}			t_game;

/* draw.c: */
void		draw_img(t_game *game, void *img, int x, int y);
void		draw_map(t_game *game);

/* free.c: */
void		free_map(char **map, t_game *game);
void		exit_game(t_game *game);

/* game_and_events.c: */
int			handle_exit(t_game *game);
int			handle_keypress(int key, t_game *game);
void		gameplay(t_game *game);
void		start_game(t_game *game);

/* initialize.c: */
void		init_struct(t_game *game);
void		init_map(char *av, t_game *game);
void		init_temp_map(char *av, t_game *game);
void		init_imgs(t_game *game);

/* map_checker.c: */
void		check_map_struct(t_game *game);
void		check_map_empty_lines(t_game *game);
void		check_map_path(char *av, t_game *game);
void		full_map_checker(char *av, t_game *game);

/* map_checker_structs.c: */
int			map_is_rectangular(char **map);
int			map_wall_is_valid(char **map);
int			map_is_correct(char **map);
int			map_is_functional(t_game *game);

/* player_moves.c: */
int			check_next_position(t_game *game, int x, int y);
void		player_new_position(t_game *game, int x, int y);
void		move(t_game *game, char key, int x, int y);
void		player_moves(char key, t_game *game);

/*player_moves_2.c: */
void		player_move(t_game *game, int new_x, int new_y);

/* utils.c: */
int			count_lines(char *av);
int			count_cols(char *line);
void		player_position(t_game *game);
int			flood_fill(t_game *game, char **map, int x, int y);

#endif
