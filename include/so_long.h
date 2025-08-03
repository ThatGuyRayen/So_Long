#ifndef SO_LONG_H
# define SO_LONG_H

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define TILE_SIZE 64
# include "libft/libft.h"
# include "mlx.h"
# include <X11/keysym.h>

typedef struct s_tiles
{
	void	*center;
}			t_tiles;

typedef struct s_player
{
	void	*idle;
	int		x;
	int		y;
	int		frame;
}			t_player;

typedef struct s_map
{
	char	**line;
	int		num_line;
	int		num_col;
	int		width;
	int		height;
	int		player;
	int		player_x;
	int		player_y;
	int		num_exits;
	int		num_collectibles;
	int		num_player;
	int		row;
	int		col;
}			t_map;


typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		bpp;
	t_tiles	bg;
	t_player player;
	t_map map;
	int		line_len;
	int		endian;
}			t_mlx_data;

void		init_map(t_map *map);
int			initialize_mlx(t_mlx_data **ptr);
int	handle_input(int keysym, t_mlx_data *ptr, t_map *map, t_player *player);
int			ft_error(const char *msg);
void		free_whole_line(char **line);

// to check valid path
int			fill(char **map, int row, int col, int max_rows);
char		**clone_map(char **src, int height);
int			check_path(t_map *map);

// to check map's boarder
int			check_line_one(char *line);
int			check_line_two(char *line);
int			check_border(t_map *map);
t_map		*get_no_of_entities(t_map *map);
int			content_checker(t_map *map);

// to check validity of map in general
int			check_extension(char *filename);
t_map		*read_file(int fd);
int			check_rectangle(t_map *map);
int			check_line_content(t_map *map);
t_map		*check_map(char *filename);

// loading backgroud
void		load_background_tiles(t_mlx_data *mlx);
void		draw_background_tile(t_mlx_data *mlx, int x, int y);
void		render_background(t_mlx_data *mlx);


//
void	load_player_sprites(t_mlx_data *ptr, t_player *player);
void	render_player(t_mlx_data *mlx, t_player *player);
void	init_player(t_player *player, t_map *map);
void	render_game(t_mlx_data *mlx, t_player *player);

#endif
