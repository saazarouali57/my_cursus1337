/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazaroua <sazaroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 00:03:29 by sazaroua          #+#    #+#             */
/*   Updated: 2026/10/27 14:39:35 by sazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_len(int nb)
{
	long	num;
	int		count;

	num = nb;
	count = 0;
	if (num < 0)
	{
		count = 1;
		num = -num;
	}
	while (num > 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}

static char	*saad(char *str)
{
	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	long	num;

	str = NULL;
	num = n;
	count = ft_nbr_len(n);
	if (num == 0)
		return (saad(str));
	str = malloc(sizeof(char) * count + 1);
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	str[count] = '\0';
	while (num > 0)
	{
		str[--count] = num % 10 + 48;
		num /= 10;
	}
	return (str);
}
