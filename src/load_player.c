#include "so_long.h"

void	load_player(t_mlx_data *ptr, t_player *player)
{
	int w;
	int h;

	player->img = mlx_xpm_file_to_image(ptr->mlx_ptr, "textures/8.xpm", &w, &h);
	if (!player->img)
		ft_error("failed to load player");
	player->x = 0;
	player->y = 0;
}

void	render_player(t_mlx_data *ptr, t_player *player)
{
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, player->img, player->x, player->y);
}

void	load_wall(t_mlx_data *ptr, t_map *map)
{
	int w = 32;
	int h = 32;
	map->wall = mlx_xpm_file_to_image(ptr->mlx_ptr, "textures/middle.xpm", &w, &h);
	if (!map->wall)
		ft_error("Failed to load wall sprite");
}

void	render_walls(t_mlx_data *ptr, t_map *map)
{
	int	x;
	int	y = 0;

	while (y < map->num_line)
	{
		x= 0;
		while (map->line[y][x] != '\0')
		{
			if (map->line[y][x] == 1)
			{
				mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, map->wall, x * WALL_SIZE, y * WALL_SIZE);
			}
			x++;
		}
		y++;
	}
}
