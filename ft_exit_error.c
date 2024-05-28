/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:05:45 by atok              #+#    #+#             */
/*   Updated: 2023/02/25 18:05:58 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//static to make it run exclusively on this file
void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != 0x00)
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_exit_error(char *str)
{
	ft_putstr(str);
	exit(1);
}
//exit(1) stdlib.h