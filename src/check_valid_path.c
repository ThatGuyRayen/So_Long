#include "so_long.h"

int	fill(char **map, int row, int col, int max_rows)
{
	if (row < 0 || col < 0 || row >= max_rows || map[row][col] == '\0')
		return (0);
	if (map[row][col] == '1' || map[row][col] == 'V')
		return (0);
	if (map[row][col] == 'E')
		return (1);
	map[row][col] = 'V';
	if (fill(map, row + 1, col, max_rows))
		return (1);
	if (fill(map, row - 1, col, max_rows))
		return (1);
	if (fill(map, row, col + 1, max_rows))
		return (1);
	if (fill(map, row, col - 1, max_rows))
		return (1);
	return (0);
}

char	**clone_map(char **src, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(src[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	check_path(t_map *map)
{
	char	**copy;

	copy = clone_map(map->line, map->num_line);
	if (!copy)
		ft_error("Memory Error\n");
	if (!fill(copy, map->row, map->col, map->num_line))
	{
		free_whole_line(copy);
		return (-1);
	}
	free_whole_line(copy);
	return (0);
}
