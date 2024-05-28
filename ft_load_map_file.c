/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:17:12 by atok              #+#    #+#             */
/*   Updated: 2023/02/25 17:47:41 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_map_file(t_game *game, char **v)
{
	static int	fd;
	char		*map;
	char		*tmpmap;

	fd = open(v[1], O_RDONLY);
	if (fd == -1)
		ft_exit_error("Error\nFile empty");
	map = ft_strdup("");
	while (fd != -1)
	{
		tmpmap = get_next_line(fd);
		if (tmpmap == 0x00)
			break ;
		map = ft_joinfree(map, tmpmap);
	}
	close(fd);
	game->map.map = map;
	game->map.xymap = ft_split(map, '\n');
}
	// int i = 0;
	// while (game->map.xymap[i] != 0x00)
	// {
	// int j = 0;
	// 	while (game->map.xymap[i][j] != 0x00)
	// 		write (1, &mapdata->xymap[i][j++], 1);
	// 	write (1, "\n", 1);
	// 	i++;
	// }
