/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adrees.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazaroua <sazaroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:26:17 by sazaroua          #+#    #+#             */
/*   Updated: 2026/11/06 11:24:38 by sazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_len(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_print_adrees(unsigned long long n)
{
	int		count;
	int		len;
	char	*str;
	char	*hex;

	hex = "0123456789abcdef";
	len = nbr_len(n);
	count = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n == 0)
		return (ft_print_str("(nil)"));
	str[len] = '\0';
	count += ft_print_str("0x");
	while (len > 0)
	{
		str[--len] = hex[n % 16];
		n /= 16;
	}
	count += ft_print_str(str);
	free(str);
	return (count);
}
