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
}			t_mlx_data;

typedef struct s_map
{
	char	**line;
	int		width;
	int		height;
	int		player;
	int		num_exits;
	int		num_collectibles;
	int		num_player;
}			t_map;

int			initialize_mlx(t_mlx_data **ptr);
int			handle_input(int keysym, t_mlx_data *ptr);
int			ft_error(const char *msg);
void		free_whole_line(char **line);
int			check_extension(char *filename);
t_map		*read_file(int fd);
int			check_rectangle(t_map *map);
int			check_line_content(t_map *map);
int			check_map(char *filename);
#endif
