/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazaroua <sazaroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:04:39 by sazaroua          #+#    #+#             */
/*   Updated: 2026/11/06 14:18:35 by sazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_nbr(unsigned int n)
{
	int				i;
	int				count;
	unsigned long	num;
	char			arr[12];

	i = 0;
	count = 0;
	num = n;
	if (num == 0)
		return (ft_print_char('0'));
	while (num > 0)
	{
		arr[i++] = num % 10 + 48;
		num /= 10;
	}
	while (i > 0)
	{
		ft_print_char(arr[--i]);
		count++;
	}
	return (count);
}
