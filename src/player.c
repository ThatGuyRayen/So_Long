#include "so_long.h"

void	load_player_sprites(t_mlx_data *ptr, t_player *player)
{
	int	w;
	int	h;

	player->idle = mlx_xpm_file_to_image(ptr->mlx_ptr, "textures/8.xpm", &w, &h);
	if (!player->idle)
		return ;
}

void	render_player(t_mlx_data *mlx, t_player *player)
{
	load_player_sprites(mlx, player);
	void	*sprite;
	sprite = player->idle;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, sprite, player->x * TILE_SIZE, player->y * TILE_SIZE);
}
