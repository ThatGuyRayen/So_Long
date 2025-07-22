#include "so_long.h"

int	check_extension(char *filename)
{
	int	len;
	if (!filename)
		ft_error("No file\n");
	len = ft_strlen(filename);
	if (len > 4 && ft_strncmp(filename + len - 4, ".ber", 4))
		return (0);
}

 
