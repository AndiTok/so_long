/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:15:21 by atok              #+#    #+#             */
/*   Updated: 2023/02/28 21:17:42 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_end(t_game *game)
{
	if (game->spawn.c != 0)
	{
		ft_putstr("aww.. Try again?\n");
		exit(1);
	}
	else
	{
		ft_putstr("YOU WON!\nWith >");
		ft_putstr(ft_itoa(game->move));
		ft_putstr("< Moves!\n");
		exit(1);
	}
}
