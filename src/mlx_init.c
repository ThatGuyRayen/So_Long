#include "so_long.h"

int	initialize_mlx(t_mlx_data **ptr)
{
	*ptr = malloc(sizeof(t_mlx_data));
	if (!ptr)
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

int	handle_input(int keysym, t_mlx_data *ptr)
{
	if (keysym == XK_Escape)
	{
		ft_printf("The %d key (ESC) had been pressed\n", keysym);
		mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
		mlx_destroy_display(ptr->mlx_ptr);
		free(ptr->mlx_ptr);
		free(ptr);
		exit(1);
	}
	ft_printf("The %d key has been presses\n", keysym);
	return (0);
}
