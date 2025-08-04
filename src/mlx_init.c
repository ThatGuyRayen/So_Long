#include "so_long.h"

int	initialize_mlx(t_mlx_data **ptr)
{
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
			WIN_WIDTH, WIN_HEIGHT, "Game");
	if ((*ptr)->win_ptr == NULL)
	{
		mlx_destroy_display((*ptr)->mlx_ptr);
		free((*ptr)->mlx_ptr);
		free(*ptr);
		return (1);
	}
	return (0);
}
