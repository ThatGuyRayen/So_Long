#include "so_long.h"

void	init_map(t_map *map)
{
	map->num_col = 0;
	map->num_player = 0;
	map->num_exits = 0;
	map->num_collectibles = 0;
	map->line = NULL;
	map->num_line = 0;
	map->height = 0;
	map->col = 0;
	map->row = 0;
}

int	ft_error(const char *msg)
{
	ft_printf(msg);
	exit(1);
}

void	free_whole_line(char **line)
{
	int	i;

	if (!line)
		return ;
	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}

int	handle_input(int keycode, void *param)
{
	t_mlx_data *mlx = (t_mlx_data *)param;

	if (keycode == 65307) // ESC key
	{
		ft_printf("ESC pressed. Exiting game.\n");
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}

	ft_printf("Keycode pressed: %d\n", keycode);
	return (0);
}
