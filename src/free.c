

#include "../includes/so_long.h"

void	free_map(char **map, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	exit_game(t_game *game)
{
	free_map(game->map, game);
	free_map(game->temp_map, game);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_background);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
}
