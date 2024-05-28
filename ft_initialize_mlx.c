/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_mlx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:29:27 by atok              #+#    #+#             */
/*   Updated: 2023/07/28 18:44:32 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.n_col * BIT_SIZE, \
	game->map.n_row * BIT_SIZE, "s0_long~ TotOr0~");
}
	//mlx_hook(game->win,2,0,ft_key_press,game); //2 == on press
	//mlx_loop(game->mlx);
