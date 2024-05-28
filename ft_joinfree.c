/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:27:01 by atok              #+#    #+#             */
/*   Updated: 2023/02/25 18:06:49 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_joinfree(char *str, char *tmpstr)
{
	char	*join;

	join = ft_strjoin(str, tmpstr);
	free(str);
	return (join);
}
