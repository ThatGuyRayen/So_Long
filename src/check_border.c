#include "so_long.h"

int	check_line_one(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_line_two(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] != '1' || line[0] != '1')
		return (-1);
	return (0);
}

int	check_border(t_map *map)
{
	int	i;
	int	len;

	if (!map || !map->line)
		ft_error("Map Data is Missing");
	i = 0;
	len = 0;
	while (map->line[i])
	{
		if (check_line_one(map->line[0]) != 0 || check_line_one(map->line[map->num_line - 1]) != 0)
			ft_error("Walls are not looking Good");
		if (check_line_two(map->line[i]) != 0)
			ft_error("walls in Middle are not looking Good");
		i++;	
	}
	return (0);
}
