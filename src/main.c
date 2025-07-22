#include "so_long.h"

int	main(int ac, char *av[])
{
	t_mlx_data	*ptr;

	if (ac != 2)
		ft_error("Invalid Number of Arguments\n");
	if (check_map(av[1]) != 0)
		ft_error("Invalid Map\n");
	ptr = NULL;
	if (initialize_mlx(&ptr) != 0)
		return (1);
	mlx_key_hook(ptr->win_ptr, handle_input, ptr);
	mlx_loop(ptr->mlx_ptr);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	mlx_destroy_display(ptr->mlx_ptr);
	free(ptr->mlx_ptr);
	free(ptr);
	return (0);
}
