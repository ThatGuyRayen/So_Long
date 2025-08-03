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

int	handle_input(int keysym, t_mlx_data *ptr, t_map *map, t_player *player)
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
	if (keysym == 119 && map->line[player->y - 1][player->x] != '1' && player->y > 0)
		player->y--;

	// Move down (S)
	else if (keysym == 115 && map->line[player->y + 1][player->x] != '1' && player->y < map->num_line - 1)
		player->y++;

	// Move left (A)
	else if (keysym == 97 && map->line[player->y][player->x - 1] != '1' && player->x > 0)
		player->x--;

	// Move right (D)
	else if (keysym == 100 && map->line[player->y][player->x + 1] != '1' && player->x < map->num_col - 1)
		player->x++;

	// After movement, redraw the game (map + player)
	render_game(ptr, player);
	return (0);
}
