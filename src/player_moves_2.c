

#include "../includes/so_long.h"

void	player_move(t_game *game, int new_x, int new_y)
{
	int	x;
	int	y;

	x = game->pos_x * SIZE;
	y = game->pos_y * SIZE;
	new_x *= SIZE;
	new_y *= SIZE;

	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player, new_x, new_y);
	game->moves++;
	ft_printf("%s%d\n", "Moves: ", game->moves);
}

