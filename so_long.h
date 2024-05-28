/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:23:04 by atok              #+#    #+#             */
/*   Updated: 2023/02/28 20:58:19 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include <stdio.h>
#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "minilibx/minilibx-linux/mlx.h"

# ifndef BIT_SIZE
#  define BIT_SIZE 64
# endif

# define C	"assets/collectable.xpm"
# define C2	"assets/collectable2.xpm"
# define E	"assets/exit.xpm"
# define E2	"assets/exit2.xpm"
# define F	"assets/floor.xpm"
# define P	"assets/player.xpm"
# define P2	"assets/player2.xpm"
# define W	"assets/wall.xpm"

typedef struct s_player
{
	int		x;
	int		y;

}t_player;

typedef struct s_spawn
{
	int		p;
	int		e;
	int		c;

}t_spawn;

typedef struct s_map
{
	char	**ffmap;
	char	**xymap;
	char	*map;
	int		n_row;
	int		n_col;
	int		accessable_coin;
	int		valid_exit;

}t_map;

typedef struct s_game
{
	void		*coin[2];
	void		*exit[2];
	void		*floor;
	void		*p1[2];
	void		*wall;
	void		*mlx;
	void		*win;
	int			k;
	int			z;
	int			move;
	int			l;
	int			fps;
	t_map		map;
	t_spawn		spawn;
	t_player	player;
}t_game;

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_check_input(int c, char **v);
void	ft_load_map_file(t_game *game, char **v);
char	*ft_joinfree(char *str, char *tmpstr);
char	**ft_split(char const *s, char c);
void	ft_initialize_vars(t_game *game);
void	ft_check_map(t_game *game);
void	ft_check_path(t_game *game);
void	ft_initialize_mlx(t_game *game);
void	ft_initialize_xpm(t_game *game);
void	ft_render_img(t_game *game);
char	*ft_itoa(int n);
void	ft_keypress(t_game *game);
int		ft_fps(t_game *game);
int		ft_end(t_game *game);

void	ft_putstr(char *s);
void	ft_exit_error(char *str);

//GNL + utils
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);

#endif