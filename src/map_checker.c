

#include "../includes/so_long.h"

void	check_map_struct(t_game *game)
{
	if (map_is_rectangular(game->map) == 0)
	{
		free_map(game->map, game);
		exit(1);
	}
	if (map_wall_is_valid(game->map) == 0)
	{
		ft_printf("Leaks in Wallssss\n");
		free_map(game->map, game);
		exit(1);
	}
	if (map_is_correct(game->map) == 0)
	{
		free_map(game->map, game);
		exit(1);
	}
	if (map_is_functional(game) == 0)
	{
		ft_printf("Give Something To Consumeee");
		ft_printf("Error\n");
		free_map(game->map, game);
		exit(1);
	}
}

void	check_map_path(char *av, t_game *game)
{
	init_temp_map(av, game);
	player_position(game);
	if (flood_fill(game, game->temp_map, game->pos_x, game->pos_y) == 0)
	{
		ft_printf("No valid path found\n");
		free_map(game->temp_map, game);
		free_map(game->map, game);
		exit (1);
	}
}

void	full_map_checker(char *av, t_game *game)
{
	game->map_rows = count_lines(av);
	init_map(av, game);
	game->map_cols = count_cols(game->map[0]);
	check_map_struct(game);
	check_map_path(av, game);
}
