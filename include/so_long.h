#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx.h"
# include <X11/keysym.h>


# define PLAYER "./textures/8.xpm"
# define COLLECT "./textures/FortuneCookie.xpm"
# define BG "./textures/middle.xpm"
# define EXIT_0 "./textures/BigTreasureChest/chest0.xpm"
# define EXIT_1 "./textures/BigTreasureChest/chest1.xpm"

# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define SIZE 32

typedef struct s_img
{
	void	*player_img;
	int		pos_x;
	int		pos_y;
	void	*collect_img;
	void	*bg_img;
	void	*exit_img[2];
}			t_img;

typedef struct s_map
{
	char	**line;
	int		num_line;
	int		num_col;
	int		num_exits;
	int		num_collectibles;
	int		num_player;
	int		row;
	int		col;
	int		img_width;
	int		img_height;
	void		*wall;
}			t_map;


typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		bpp;
	t_img	img;
	t_map map;
	int		line_len;
	int		endian;
}			t_mlx_data;

void		init_map(t_map *map);
int	initialize_mlx(t_mlx_data **ptr, t_map *map);
int	handle_input(int keycode, void *param);
int			ft_error(const char *msg);
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

// loading images
void	init_imgs(t_img *img, t_map *map);




#endif
