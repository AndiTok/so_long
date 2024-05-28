/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:13:00 by atok              #+#    #+#             */
/*   Updated: 2023/02/27 17:59:40 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_fps(t_game *game)
{
	game->fps++;
	if (game->fps == 4444)
	{
		game->l++;
		game->l = game->l % 2;
		ft_render_img(game);
		game->fps = 0;
	}
	return (0);
}
