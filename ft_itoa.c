/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:51:59 by atok              #+#    #+#             */
/*   Updated: 2023/02/25 18:06:22 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*strdup(const char *src)
{
	char	*dup;
	int		i;
	int		len;

	len = 0;
	while (src[len])
		len++;
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (dup == (NULL))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = 0x00;
	return (dup);
}

int	int_len(int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ascii;
	int		i;

	if (n == -2147483648)
		return (strdup("-2147483648"));
	if (n == 0)
		return (strdup("0"));
	i = int_len(n);
	ascii = (char *) malloc(sizeof(char) * (i + 1));
	if (ascii == NULL)
		return (NULL);
	ascii[i] = 0x00;
	i--;
	if (n < 0)
	{
		ascii[0] = '-';
		n = n * -1;
	}
	while (n != 0)
	{
		ascii[i] = '0' + (n % 10);
		i--;
		n = n / 10;
	}
	return (ascii);
}
