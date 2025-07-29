#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_H 400
# define IMG_W 400
# define TILE_SIZE 32
# include "libft/libft.h"
# include "mlx.h"
# include <X11/keysym.h>



typedef struct s_tiles {
	void	*top_left;
	void	*top_mid;
	void	*top_right;
	void	*mid_left;
	void	*center;
	void	*mid_right;
	void	*bot_left;
	void	*bot_mid;
	void	*bot_right;
}	t_tiles;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	bpp;
	t_tiles bg;
	int	line_len;
	int	endian;
}			t_mlx_data;


typedef struct s_map
{
	char	**line;
	int		num_line;
	int		num_col;
	int		width;
	int		height;
	int		player;
	int		num_exits;
	int		num_collectibles;
	int		num_player;
	int		row;
	int		col;
}			t_map;


void		init_map(t_map *map);
int	width_cal(char **line);
int			initialize_mlx(t_mlx_data **ptr);
int			handle_input(int keysym, t_mlx_data *ptr);
int			ft_error(const char *msg);
void		free_whole_line(char **line);



//to check valid path
int	fill(char **map, int row, int col, int max_rows);
char	**clone_map(char **src, int height);
int	check_path(t_map *map);


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
int			check_map(char *filename);


//loading backgroud
void	load_background_tiles(t_mlx_data *mlx);
void	draw_background_tile(t_mlx_data *mlx, int x, int y,int max_x, int max_y);
void	render_background(t_mlx_data *mlx, t_map *map);

#endif
