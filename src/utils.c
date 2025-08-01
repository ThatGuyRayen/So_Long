#include "so_long.h"

void	init_map(t_map *map)
{
	map->num_col = 0;
	map->num_player = 0;
	map->num_exits = 0;
	map->num_collectibles = 0;
	map->line = NULL;
	map->num_line = 0;
	map->width = 0;
	map->height = 0;
	map->col = 0;
	map->row = 0;
}

void	init_player(t_player *player, t_map *map)
{
	player->idle = NULL;
	player->x = map->col;
	player->y = map->row;
}

int	ft_error(const char *msg)
{
	ft_printf(msg);
	exit(1);
}

void	free_whole_line(char **line)
{
	int	i;

	if (!line)
		return ;
	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}
