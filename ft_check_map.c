/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:59:02 by atok              #+#    #+#             */
/*   Updated: 2023/02/25 17:49:50 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	//printf("len0 : %d\n", len0);
		// if (game->map.xymap[i][0] == '\n')
		// 	ft_error("Error\nMap missing row\n");
#include "so_long.h"

void	check_shape(t_game *game)
{
	int	i;
	int	j;
	int	len0;

	i = 0;
	len0 = ft_strlen(game->map.xymap[0]);
	while (game->map.xymap[i] != 0x00)
	{
		j = 0;
		while (game->map.xymap[i][j] != 0x00)
			j++;
		if (len0 != j)
			ft_exit_error("Error\nMap row not even\n");
		i++;
	}
	if (i == j)
		ft_exit_error("Error\nMap is not rectangle\n");
	if ((i < 3 || j < 5) && (i < 5 || j < 3))
		ft_exit_error("Error\nMap too small\n");
	game->map.n_row = i;
	game->map.n_col = j;
}

void	check_surround_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.xymap[i] != 0x00)
	{
		j = 0;
		while (game->map.xymap[i][j] != 0x00)
		{
			if (game->map.xymap[0][j] != '1'
				|| game->map.xymap[game->map.n_row - 1][j] != '1')
				ft_exit_error("Error\nMissing wall UD\n");
			j++;
		}
		if (game->map.xymap[i][0] != '1'
			|| game->map.xymap[i][game->map.n_col - 1] != '1')
			ft_exit_error("Error\nMissing LR\n");
		i++;
	}
}

void	check_spawn(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i] != 0x00)
	{
		if (game->map.map[i] == 'P')
			game->spawn.p += 1;
		if (game->map.map[i] == 'E')
			game->spawn.e += 1;
		if (game->map.map[i] == 'C')
			game->spawn.c += 1;
		i++;
	}
	if (game->spawn.p != 1)
		ft_exit_error("Error\n Player spawn point != 1");
	if (game->spawn.e != 1)
		ft_exit_error("Error\n Exit point != 1");
	if (game->spawn.c < 1)
		ft_exit_error("Error\n no Collectables found");
}

void	ft_check_map(t_game *game)
{
	check_shape(game);
	check_surround_wall(game);
	check_spawn(game);
}
	// printf("%d\n", game->spawn.p);
	// printf("%d\n", game->spawn.e);
	// printf("%d\n", game->spawn.c);

	//printf("n_row: %d\n", i);
	//printf("n_col: %d\n", j);

	// i = 0;
	// while (game->map.xymap[i] != 0x00)
	// {
	// 	j = 0;
	// 	while (game->map.xymap[i][j] != 0x00)
	// 		write (1, &game->map.xymap[i][j++], 1);
	// 	write (1, "\n", 1);
	// 	i++;
	// }
	// check all rows are equal in legth (solves blank row as well)
	// 1st row and last row must be all 1
	// all other line must have 1 in the beginning and 1 at the end
	// must have 1 P & 1 E
	// C at least must have 1
	// check i/x != j/y (cannot be square)