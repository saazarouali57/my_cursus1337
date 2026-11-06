/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazaroua <sazaroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:17:20 by username          #+#    #+#             */
/*   Updated: 2026/11/06 20:34:09 by sazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(va_list args, char z)
{
	int	count;

	count = 0;
	if (z == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (z == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (z == 'd' || z == 'i')
		count += ft_print_nbr(va_arg(args, int));
	else if (z == 'u')
		count += ft_print_unsigned_nbr(va_arg(args, unsigned int));
	else if (z == 'x' || z == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), z);
	else if (z == 'p')
		count += ft_print_adrees(va_arg(args, unsigned long long));
	else if (z == '%')
		count += ft_print_char('%');
	else if (z == 'a')
		count += ft_print_str(va_arg(args, char *));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, s);
	if (!s)
		return (-1);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			count += ft_check(args, s[i + 1]);
			i++;
		}
		else if (s[i] != '%')
			count += ft_print_char(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
