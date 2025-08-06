#include "so_long.h"

int	initialize_mlx(t_mlx_data **ptr, t_map *map)
{
	int	rows;
	int	cols;
	rows = map->num_line * SIZE;
	cols = map->num_col * SIZE;
	*ptr = malloc(sizeof(t_mlx_data));
	if (!*ptr)
		return (1);
	(*ptr)->mlx_ptr = mlx_init();
	if ((*ptr)->mlx_ptr == NULL)
	{
		free(*ptr);
		return (1);
	}
	(*ptr)->win_ptr = mlx_new_window((*ptr)->mlx_ptr,
			cols, rows, "Game");
	if ((*ptr)->win_ptr == NULL)
	{
		mlx_destroy_display((*ptr)->mlx_ptr);
		free((*ptr)->mlx_ptr);
		free(*ptr);
		return (1);
	}
	return (0);
}


void	exit_game(t_mlx_data *ptr, t_img *img, t_map *map)
{
	free_whole_line(map->line);
	mlx_destroy_image(ptr->mlx_ptr, img->player_img);
	mlx_destroy_image(ptr->mlx_ptr, img->exit_img[0]);
	mlx_destroy_image(ptr->mlx_ptr, img->exit_img[1]);
	mlx_destroy_image(ptr->mlx_ptr, img->collect_img);
	mlx_destroy_image(ptr->mlx_ptr, img->bg_img);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	mlx_destroy_display(ptr->mlx_ptr);
	free(ptr->mlx_ptr);
	exit (0);
}
