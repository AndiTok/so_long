/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:15:51 by atok              #+#    #+#             */
/*   Updated: 2023/07/30 07:34:48 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_input(int c, char **v)
{
	int	point_at_dot_ber;

	if (c != 2)
		ft_exit_error("Error\nCheck number of input/param\n");
	point_at_dot_ber = ft_strlen(v[1]) - 4;
	if (!ft_strnstr ((v[1] + point_at_dot_ber), ".ber", 4))
		ft_exit_error("Error\nCheck map file extention is correct\n");
}
	//printf("padb - %d\n", point_at_dot_ber); - 4 mustbe outside
//*.ber - 4 from strlen it will point at the "."
//ft_strnstr takes in the string v[1] + pointing at the "."
//so it will only cheack the ".ber"
//before the "." the map file name cab be any lenght