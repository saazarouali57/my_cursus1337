/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazaroua <sazaroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:26:39 by sazaroua          #+#    #+#             */
/*   Updated: 2026/10/27 11:53:24 by sazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			i;
	long		num;
	char		arr[12];

	i = 0;
	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num == 0)
	{
		ft_putchar_fd('0', fd);
	}
	while (num > 0)
	{
		arr[i++] = num % 10 + 48;
		num /= 10;
	}
	while (i > 0)
		ft_putchar_fd(arr[--i], fd);
}
