/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazaroua <sazaroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:15:28 by sazaroua          #+#    #+#             */
/*   Updated: 2026/11/06 16:00:52 by sazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nb, char format)
{
	int		i;
	int		count;
	char	*s;
	char	arr[10];

	count = 0;
	if (format == 'x')
		s = "0123456789abcdef";
	else
		s = "0123456789ABCDEF";
	if (nb == 0)
		return (ft_print_char('0'));
	i = 0;
	while (nb > 0)
	{
		arr[i] = s[nb % 16];
		nb /= 16;
		i++;
	}
	while (i > 0)
	{
		ft_print_char(arr[--i]);
		count++;
	}
	return (count);
}
