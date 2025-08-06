#include "so_long.h"

void	init_imgs(t_mlx_data *ptr, t_map *map, t_img *img)
{
	int	*w;
	int	*h;

	w = &map->img_width;
	h = &map->img_height;

	img->player_img = mlx_xpm_file_to_image(ptr->mlx_ptr, PLAYER, w, h);
	img->collect_img = mlx_xpm_file_to_image(ptr->mlx_ptr, COLLECT, w, h);
	img->bg_img = mlx_xpm_file_to_image(ptr->mlx_ptr, BG, w, h);
	img->exit_img[0] = mlx_xpm_file_to_image(ptr->mlx_ptr, EXIT_0, w, h);
	img->exit_img[1] = mlx_xpm_file_to_image(ptr->mlx_ptr, EXIT_1, w, h);
}
