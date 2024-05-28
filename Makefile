# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atok <atok@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 18:44:12 by atok              #+#    #+#              #
#    Updated: 2023/02/28 15:00:58 by atok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3 -L -Imlx_linux
MLXFLAGS	= -L minilibx/minilibx-linux -lmlx -lXext -lX11 -lm -lz

INCLUDES	= so_long.h

SRCS		=	so_long.c \
				ft_check_input.c \
				ft_check_map.c \
				ft_check_path.c \
				ft_end.c \
				ft_exit_error.c \
				ft_fps.c \
				ft_initialize_mlx.c \
				ft_initialize_vars.c \
				ft_initialize_xpm.c \
				ft_itoa.c \
				ft_joinfree.c \
				ft_keypress.c \
				ft_load_map_file.c \
				ft_render_img.c \
				ft_split.c \
				ft_strnstr.c \
				get_next_line_utils.c \
				get_next_line.c

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all