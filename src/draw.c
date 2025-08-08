
#include "../includes/so_long.h"

void	draw_img(t_game *game, void *img, int x, int y)
{
	x *= SIZE;
	y *= SIZE;
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_rows)
	{
		x = 0;
		while (x < game->map_cols)
		{
			if (game->map[y][x] == 'P')
				draw_img(game, game->img_player, x, y);
			else if (game->map[y][x] == 'E')
				draw_img(game, game->img_exit, x, y);
			else if (game->map[y][x] == 'C')
				draw_img(game, game->img_collect, x, y);
			else if (game->map[y][x] == '1')
				draw_img(game, game->img_wall, x, y);
			x++;
		}
		y++;
	}
}
