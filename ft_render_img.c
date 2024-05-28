/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:46:45 by atok              #+#    #+#             */
/*   Updated: 2023/02/28 21:21:40 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_move_counter(t_game *game)
{	
	char	*move;
	char	*str;

	move = ft_itoa(game->move);
	str = ft_strjoin("Steps =>", move);
	mlx_string_put(game->mlx, game->win, 24, 34, 44, str);
}

void	place_img(t_game *game, int i, int j)
{
	if (game->map.xymap[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin[game->l],
			j * BIT_SIZE, i * BIT_SIZE);
	if (game->map.xymap[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit[game->z],
			j * BIT_SIZE, i * BIT_SIZE);
	if (game->map.xymap[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			j * BIT_SIZE, i * BIT_SIZE);
	if (game->map.xymap[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->p1[game->k],
			j * BIT_SIZE, i * BIT_SIZE);
	if (game->map.xymap[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			j * BIT_SIZE, i * BIT_SIZE);
}

void	ft_render_img(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.xymap[i] != 0x00)
	{
		j = 0;
		while (game->map.xymap[i][j] != 0x00)
		{
			if (game->map.xymap[i][j] != 0x00)
				place_img(game, i, j);
			j++;
		}
		i++;
	}
	display_move_counter(game);
}
// void	move_counter(t_game *game)
// {	
// 	char	*move;
// 	char	*str;

// 	move = ft_itoa(game->move);
// 	str = ft_strjoin("Steps =>", move);
// 	mlx_string_put(game->mlx, game->win, 8, 18, 4, str);
// 	ft_putstr(str);
// 	write (1, "\n", 1);
// }
	// move_counter(game);
		//printf("%s\n",game->map.xymap[i]);
/* refresh - render sprites again, render step counter
render as in refresh and update the coordinate */