/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:32:00 by tpandya           #+#    #+#             */
/*   Updated: 2025/08/08 17:32:03 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_struct(t_game *game)
{
	game->mlx = 0;
	game->win = 0;
	game->img_player = 0;
	game->img_exit = 0;
	game->img_collect = 0;
	game->img_wall = 0;
	game->map = 0;
	game->temp_map = 0;
	game->img_width = 32;
	game->img_height = 32;
	game->map_rows = 0;
	game->map_cols = 0;
	game->player = 0;
	game->pos_x = 0;
	game->pos_y = 0;
	game->exit = 0;
	game->collect = 0;
	game->collected = 0;
	game->wall = 0;
	game->background = 0;
	game->moves = 0;
}

void	init_map(char *av, t_game *game)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	line = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->map_rows + 1));
	fd = open(av, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		game->map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	game->map[i] = 0;
	close(fd);
}

void	init_temp_map(char *av, t_game *game)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	line = 0;
	game->temp_map = (char **)malloc(sizeof(char *) * (game->map_rows + 1));
	fd = open(av, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		game->temp_map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	game->temp_map[i] = 0;
	close(fd);
}

void	init_imgs(t_game *game)
{
	int	*w;
	int	*h;

	w = &game->img_width;
	h = &game->img_height;
	game->img_player = mlx_xpm_file_to_image(game->mlx, PLAYER, w, h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, EXIT_IMG, w, h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, COLLECT_IMG, w, h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, WALL_IMG, w, h);
	game->img_bg = mlx_xpm_file_to_image(game->mlx, BG_IMG, w, h);
}
