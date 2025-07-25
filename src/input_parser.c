#include "so_long.h"

int	check_extension(char *filename)
{
	int	len;

	if (!filename)
		ft_error("Filename is Invalid\n");
	len = ft_strlen(filename);
	if (len < 4)
		return (-1);
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		return (-1);
	return (0);
}

t_map	*read_file(int fd)
{
	t_map	*map;
	int		i;
	char	*temp;

	if (fd < 0)
		ft_error("Error opening file\n");
	i = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("Memory allocation failed\n");
	init_map(map);
	map->line = malloc(sizeof(char *) * 200);
	if (!map->line)
	{
		free(map);
		ft_error("Memory allocation failed\n");
	}
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		map->line[i] = ft_strtrim(temp, "\n");
		free(temp);
		map->num_line++;
		i++;
	}
	map->line[i] = NULL;
	if (map->num_line <= 2)
	{
		free_whole_line(map->line);
		free(map);
		ft_error("Map is too small\n");
	}
	return (map);
}

int	check_rectangle(t_map *map)
{
	int		i;
	size_t	line_length;

	i = 0;
	if (!map || !map->line)
		return (-1);
	line_length = ft_strlen(map->line[0]);
	while (map->line[i])
	{
		if (ft_strlen(map->line[i]) != line_length)
			return (-1);
		i++;
	}
	return (0);
}

int	check_line_content(t_map *map)
{
	int	i;
	int	j;

	if (!map || !map->line)
		return (-1);
	i = 0;
	while (map->line[i])
	{
		j = 0;
		while (map->line[i][j])
		{
			if (map->line[i][j] != '0' && map->line[i][j] != '1'
				&& map->line[i][j] != 'C' && map->line[i][j] != 'E'
				&& map->line[i][j] != 'P')
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map(char *filename)
{
	int		fd;
	t_map	*map;

	if (check_extension(filename) != 0)
		ft_error("Invalid File Extension\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error opening file\n");
	map = read_file(fd);
	if (!map || check_rectangle(map) != 0 || check_line_content(map) != 0)
	{
		free_whole_line(map->line);
		free(map);
		ft_error("Invalid Map Format\n");
	}
	if (check_border(map) != 0)
	{
		free_whole_line(map->line);
		free(map);
		ft_error("Walls are not good");
	}
	if (content_checker(map) != 0)
	{
		free_whole_line(map->line);
		free(map);
		ft_error("Content is Corrupeted");
	}
	close(fd);
	return (0);
}
