/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:19:34 by atok              #+#    #+#             */
/*   Updated: 2023/02/25 17:55:17 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_location(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.xymap[i] != 0x00)
	{
		j = 0;
		while (game->map.xymap[i][j] != 0x00)
		{
			if (game->map.xymap[i][j] == 'P')
			{
				game->player.y = i;
				game->player.x = j;
			}
			j++;
		}
		i++;
	}
}

void	dup_map(t_game *game)
{
	int		i;
	char	**ffmap;

	ffmap = malloc(sizeof(char **) * game->map.n_row);
	i = 0;
	while (game->map.xymap[i] != 0x00)
	{
		ffmap[i] = ft_strdup(game->map.xymap[i]);
		i++;
	}
	game->map.ffmap = ffmap;
}

void	flood_fill(t_game *game, char **ffmap, int i, int j)
{
	if (ffmap[i][j] == 'E')
	{
		game->map.valid_exit += 1;
		return ;
	}
	if ((i < 0 || i >= game->map.n_row) || \
		(j < 0 || j >= game->map.n_col) || \
		(ffmap[i][j] != 'C' && ffmap[i][j] != '0' && ffmap[i][j] != 'P'))
		return ;
	if (ffmap[i][j] == '0' || ffmap[i][j] == 'C')
	{
		if (ffmap[i][j] == 'C')
			game->map.accessable_coin += 1;
		ffmap[i][j] = 'F';
	}
	flood_fill(game, ffmap, i, j + 1);
	flood_fill(game, ffmap, i, j - 1);
	flood_fill(game, ffmap, i + 1, j);
	flood_fill(game, ffmap, i - 1, j);
}

void	ft_check_path(t_game *game)
{	
	player_location(game);
	dup_map(game);
	flood_fill(game, game->map.ffmap, game->player.y, game->player.x);
	if (game->map.valid_exit == 0)
		ft_exit_error("Error\nCAN'T EXIT\n");
	if (game->map.accessable_coin != game->spawn.c)
		ft_exit_error("Error\nCAN'T REACH COLLECTABLES\n");
}
	// if exit is bloacked by wall...

	// int j = 0;
	// while (j < i)
	// 	printf("%s\n", ffmap[j++]);

	// int k = 0;
	// while (ffmap[k])
	// 	printf("%s\n", ffmap[k++]);

	// i = game->player.y;
	// j = game->player.x;

	// printf("%d\n", i);
	// printf("%d\n", j);
	// printf("%d\n", game->player.y);
	// printf("%d\n", game->player.x);
	// ffmap = game->map.ffmap;
	// int k = 0;
	// while (k < game->map.n_row)
	// 	printf("%s\n", game->map.ffmap[k++]);
	// printf("----------------------------------------\n");
	// 		flood fill fucntion
	// k = 0;
	// while (k < game->map.n_row)
	// 	printf("%s\n", game->map.ffmap[k++]);