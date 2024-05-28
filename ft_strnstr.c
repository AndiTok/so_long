/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:24:18 by atok              #+#    #+#             */
/*   Updated: 2023/05/11 02:19:49 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*str;
	const char	*find;
	size_t		i;
	size_t		j;

	str = haystack;
	find = needle;
	if (*find == 0x00)
		return ((char *) str);
	if (len == 0)
		return (NULL);
	i = 0;
	j = 0;
	while ((str[i] != 0x00) && (len > i + j))
	{
		j = 0;
		while (str[i + j] == find[j] && len > i + j)
		{
			if (find[j + 1] == 0x00)
				return ((char *) str + i);
					j++;
		}
		i++;
	}
	return (NULL);
}

//returns a pointer to the needle/to_find string