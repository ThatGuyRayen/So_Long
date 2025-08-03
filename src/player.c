#include "so_long.h"

void	load_player_sprites(t_mlx_data *ptr, t_player *player)
{
	int	w;
	int	h;
	if (!ptr || !player)
		ft_error("Mlx data or player is empty");
	if (ptr->mlx_ptr == NULL)
		ft_error("Mlx pointer is NULL");

	player->idle = mlx_xpm_file_to_image(ptr->mlx_ptr, "textures/8.xpm", &w, &h);
	if (!player->idle)
		ft_error("Failed to load player idle sprite");
}

void	render_player(t_mlx_data *mlx, t_player *player)
{
	if (!mlx || !player)
		ft_error("Mlx data or player is empty");

	ft_printf("mlx_ptr: %p, win_ptr: %p, player->idle: %p\n", mlx->mlx_ptr, mlx->win_ptr, player->idle);
	ft_printf("Rendering player at (%d, %d)\n", player->x, player->y);

	if (!player->idle)
		ft_error("player->idle is NULL before rendering!");

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, player->idle, player->x, player->y);
}

