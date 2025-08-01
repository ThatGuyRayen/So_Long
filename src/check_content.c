#include "so_long.h"

t_map	*get_no_of_entities(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->line[i])
	{
		j = 0;
		while (map->line[i][j])
		{
			if (map->line[i][j] == 'P')
			{
				map->num_player++;
				map->row = i;
				map->col = j;
			}
			else if (map->line[i][j] == 'C')
				map->num_collectibles++;
			else if (map->line[i][j] == 'E')
				map->num_exits++;
			j++;
		}
		i++;
	}
	return (map);
}

int	content_checker(t_map *map)
{
	get_no_of_entities(map);
	if (!map)
		return (-1);
	if (map->num_exits != 1)
		return (-1);
	if (map->num_player != 1)
		return (-1);
	if (map->num_collectibles < 1)
		return (-1);
	return (0);
}
