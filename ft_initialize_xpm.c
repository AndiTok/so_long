/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_xpm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:46:19 by atok              #+#    #+#             */
/*   Updated: 2023/02/27 16:52:10 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize_xpm(t_game *game)
{
	void	*mlx;
	int		i;
	int		j;

	mlx = game->mlx;
	game->coin[0] = mlx_xpm_file_to_image(mlx, C, &i, &j);
	game->coin[1] = mlx_xpm_file_to_image(mlx, C2, &i, &j);
	game->exit[0] = mlx_xpm_file_to_image(mlx, E, &i, &j);
	game->exit[1] = mlx_xpm_file_to_image(mlx, E2, &i, &j);
	game->floor = mlx_xpm_file_to_image(mlx, F, &i, &j);
	game->p1[0] = mlx_xpm_file_to_image(mlx, P, &i, &j);
	game->p1[1] = mlx_xpm_file_to_image(mlx, P2, &i, &j);
	game->wall = mlx_xpm_file_to_image(mlx, W, &i, &j);
}
	//write (1, "xmp initialized\n", 17);
	// i & j are not evne initialized
	//they will be over written by the mlx funtion