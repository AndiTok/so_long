/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_vars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:24:36 by atok              #+#    #+#             */
/*   Updated: 2023/02/27 18:37:51 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize_vars(t_game *game)
{
	game->spawn.p = 0;
	game->spawn.e = 0;
	game->spawn.c = 0;
	game->map.valid_exit = 0;
	game->map.accessable_coin = 0;
	game->k = 0;
	game->z = 0;
	game->move = 0;
	game->l = 0;
	game->fps = 0;
}
