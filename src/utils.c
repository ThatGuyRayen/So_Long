#include "so_long.h"

int ft_error(const char *msg)
{
	ft_printf(msg);
	exit(1);
}

void free_whole_line(char **line)
{
	int i;

	if (!line)
		return;
	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}
