/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:41:25 by atok              #+#    #+#             */
/*   Updated: 2023/02/28 21:15:29 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move_counter(t_game *game)
{	
	char	*move;
	char	*str;

	move = ft_itoa(game->move);
	str = ft_strjoin("Steps =>", move);
	ft_putstr(str);
	write (1, "\n", 1);
}

void	update_xy(t_game *game, int i, int j)
{
	game->map.xymap[game->player.y][game->player.x] = '0';
	game->map.xymap[i][j] = 'P';
	game->player.y = i;
	game->player.x = j;
	game->move += 1;
}

void	playermove(t_game *game, int i, int j)
{
	if (game->map.xymap[i][j] == '0')
	{
		update_xy(game, i, j);
	}
	if (game->map.xymap[i][j] == 'C')
	{
		update_xy(game, i, j);
		game->spawn.c -= 1;
		if (game->spawn.c == 0)
			game->z += 1;
	}
	if (game->map.xymap[i][j] == 'E')
	{
		if (game->spawn.c == 0)
		{
			update_xy(game, i, j);
			ft_end(game);
		}
	}
	print_move_counter(game);
	ft_render_img(game);
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == 119)
		playermove(game, game->player.y - 1, game->player.x);
	else if (keycode == 115)
		playermove(game, game->player.y + 1, game->player.x);
	else if (keycode == 97)
		playermove(game, game->player.y, game->player.x - 1);
	else if (keycode == 100)
		playermove(game, game->player.y, game->player.x + 1);
	else if (keycode == 65307)
		exit(1);
	game->k = (game->k + 1) % 2;
	return (0);
}

void	ft_keypress(t_game *game)
{
	mlx_loop_hook(game->mlx, ft_fps, game);
	mlx_hook(game->win, (02), (1L<<0), keypress, game);
	mlx_hook(game->win, (17), (1L<<0), ft_end, game);
}
	// mlx_loop_hook()
		// mlx_clear_window(game->mlx,game->win);
	// W 13
	// S 1
	// A 0
	// D 2
	// esc 53