#include "so_long.h"

void	load_background_tiles(t_mlx_data *mlx)
{
	int	w;
	int	h;

	w = TILE_SIZE;
	h = TILE_SIZE;

	mlx->bg.top_left = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/top_left.xpm", &w, &h);
	mlx->bg.top_mid = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/top_mid.xpm", &w, &h);
	mlx->bg.top_right = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/top_right.xpm", &w, &h);
	mlx->bg.mid_left = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/mid_left.xpm", &w, &h);
	mlx->bg.center = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/center.xpm", &w, &h);
	mlx->bg.mid_right = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/mid_right.xpm", &w, &h);
	mlx->bg.bot_left = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/bot_left.xpm", &w, &h);
	mlx->bg.bot_mid = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/bot_mid.xpm", &w, &h);
	mlx->bg.bot_right = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/bot_right.xpm", &w, &h);
}

void	draw_background_tile(t_mlx_data *mlx, int x, int y, int max_x, int max_y)
{
	void	*img;

	if (y == 0 && x == 0)
		img = mlx->bg->top_left;
	else if (y == 0 && x == max_x)
		img = mlx->bg->top_right;
	else if (y == 0)
		img = mlx->bg->top_mid;
	else if (y == max_y && x == 0)
		img = mlx->bg->bot_left;
	else if (y == max_y && x == max_x)
		img = mlx->bg->bot_right;
	else if (y == max_y)
		img = mlx->bg->bot_mid;
	else if (x == 0)
		img = mlx->bg->mid_left;
	else if (x == max_x)
		img = mlx->bg->mid_right;
	else
		img = mlx->bg->center;

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	render_background(t_mlx_data *mlx, t_map *map)
{
	int	x;
	int	y;
	int	max_x = map->num_col - 1;
	int	max_y = map->num_line - 1;

	for (y = 0; y < map->num_line; y++)
	{
		for (x = 0; x < map->num_col; x++)
		{
			draw_background_tile(mlx, x, y, max_x, max_y);
		}
	}
}

