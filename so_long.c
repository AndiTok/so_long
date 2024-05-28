/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:23:24 by atok              #+#    #+#             */
/*   Updated: 2023/03/04 22:22:34 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minilibx/minilibx_opengl_20191021/mlx.h"
//#include <stdlib.h>
//#include <unistd.h>
//#include <mlx.h>
#include "so_long.h"

/* // int	closing(void)
// {
// 	exit(1);
// }

 int key_press(int keycode)
{
	if (keycode == 12) // Q
		//closing();
		exit(1);
	return (0);
}

void ft_run (t_game *game)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, game->map.n_row * BIT_SIZE, \
	game->map.n_col * BIT_SIZE, "new window");
//	win = mlx_new_window(mlx, \
//        map->n_col * map->bitsize, map->n_row * bitsize, "new window");
	mlx_hook(win,2,0,key_press,game); //2 == on press
	mlx_loop(mlx);
	// {
	// 	exit(1);
	// 	//mlx_destroy_window(mlx,win);
	// }
} */
	//ft_run(&game);
int	main(int c, char **v)
{
	t_game	game;

	if (c > 1)
	{
		ft_check_input(c, v);
		ft_load_map_file(&game, v);
		ft_initialize_vars(&game);
		ft_check_map(&game);
		ft_check_path(&game);
		ft_initialize_mlx(&game);
		ft_initialize_xpm(&game);
		ft_render_img(&game);
		ft_keypress(&game);
		mlx_loop(game.mlx);
	}
	return (0);
}
//run XLaunch
// in terminal type "export DISPLAY=[ur ipv4 ip]:0.0"
//gcc *.c -L minilibx/minilibx-linux/ -lmlx -lXext -lX11 && ./a.out maps/map.ber
		//printf("%d\n", getpid());
// check that argument only has .out & .ber
// check file extention is .ber
// import/read the map, store it in char *map/**map
// check map is not a suqare and is a rectangle
// check map is surrounded by walls/1 
// check map to have at least 
//1 spawn/player/P 
//1 Exit/E & 
//atleast 1 collectable/C
// check if P can reach E and not blocked path by walls (flood fill ignore C)
// run the game/open window
