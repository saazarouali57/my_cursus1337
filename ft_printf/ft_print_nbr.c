/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazaroua <sazaroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:56:14 by sazaroua          #+#    #+#             */
/*   Updated: 2026/11/06 15:56:15 by sazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_len(long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static int	print(char *arr, long num, int len)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count += ft_print_char('-');
		num = -num;
	}
	arr[len] = '\0';
	while (len > 0)
	{
		arr[--len] = num % 10 + '0';
		num /= 10;
	}
	count += ft_print_str(arr);
	free(arr);
	return (count);
}

int	ft_print_nbr(int n)
{
	int		len;
	long	num;
	char	*str;

	num = n;
	len = nbr_len(num);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	return (print(str, num, len));
}
