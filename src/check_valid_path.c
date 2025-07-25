#include "so_long.h"

int	fill(t_map *map, int row, int col)
{
	if (map->row < 0 || map->col < 0)
		return (-1);
	if (map->line[row][col] == 'E')
		return (0);
	fill(map, row -1, col);
	fill(map, row +1, col);
	fill(map, row, col -1);
	fill(map, row, col + 1);
}



int	check_path(t_map *map)
{
	fill(map, map->row, map->col);
} 
