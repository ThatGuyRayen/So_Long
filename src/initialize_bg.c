#include "so_long.h"

void	load_background_tiles(t_mlx_data *mlx)
{
	int	w;
	int	h;

	w = TILE_SIZE;
	h = TILE_SIZE;

	mlx->bg.center = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/middle.xpm", &w, &h);
	if (!mlx->bg.center)
		ft_error("Failed to load background");
}

void	draw_background_tile(t_mlx_data *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->bg.center,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	render_background(t_mlx_data *mlx)
{
	int	x;
	int	y;
	int	tiles_x;
	int	tiles_y;

	tiles_x = WIN_WIDTH / TILE_SIZE;
	tiles_y = WIN_HEIGHT / TILE_SIZE;
	y = 0;
	while (y < tiles_y)
	{
		x = 0;
		while (x < tiles_x)
		{
			mlx_put_image_to_window(
				mlx->mlx_ptr,
				mlx->win_ptr,
				mlx->bg.center,
				x * TILE_SIZE,
				y * TILE_SIZE
			);
			x++;
		}
		y++;
	}
}


