#include "so_long.h"

int	main(int ac, char *av[])
{
	t_mlx_data	*ptr;
	t_map		*map;

	if (ac != 2)
		ft_error("Invalid Number of Arguments\n");
	map = NULL;
	map = check_map(av[1]);
	if (!map)
		ft_error("Not a good map");
	ptr = NULL;
	if (initialize_mlx(&ptr) != 0)
		return (1);
	mlx_key_hook(ptr->win_ptr, handle_input, (void *)ptr);
	mlx_loop(ptr->mlx_ptr);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	mlx_destroy_display(ptr->mlx_ptr);
	free(ptr->mlx_ptr);
	free(ptr);
	return (0);
}
