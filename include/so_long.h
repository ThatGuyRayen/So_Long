#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_H 400
# define IMG_W 400

# include "libft/libft.h"
# include "mlx.h"
# include <X11/keysym.h>

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	bpp;
	int	line_len;
	int	endian;
}			t_mlx_data;

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

#endif
