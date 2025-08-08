/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_and_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:31:50 by tpandya           #+#    #+#             */
/*   Updated: 2025/08/08 17:31:53 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_exit(t_game *game)
{
	exit_game(game);
	exit(0);
}

int	handle_keypress(int key, t_game *game)
{
	if (key == XK_Escape)
		exit_game(game);
	else if (key == XK_w || key == XK_Up)
		player_moves('W', game);
	else if (key == XK_a || key == XK_Left)
		player_moves('A', game);
	else if (key == XK_s || key == XK_Down)
		player_moves('S', game);
	else if (key == XK_d || key == XK_Right)
		player_moves('D', game);
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->win, DestroyNotify, ButtonPressMask, &handle_exit, game);
	mlx_loop(game->mlx);
}

void	start_game(t_game *game)
{
	int	rows;
	int	cols;

	rows = game->map_rows * SIZE;
	cols = game->map_cols * SIZE;
	game->mlx = mlx_init();
	init_imgs(game);
	game->win = mlx_new_window(game->mlx, cols, rows,
			"so_long");
	draw_map(game);
	gameplay(game);
}
