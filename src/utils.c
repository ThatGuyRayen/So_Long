#include "so_long.h"

void	init_map(t_map *map)
{
	map->num_player = 0;
	map->num_exits = 0;
	map->num_collectibles = 0;
	map->line = NULL;
	map->num_line = 0;
	map->width = 0;
	map->height = 0;
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
