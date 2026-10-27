/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazaroua <sazaroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:17:20 by sazaroua          #+#    #+#             */
/*   Updated: 2026/10/27 12:27:57 by sazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_l;
	size_t	s_l;

	i = 0;
	if (!dst && size == 0)
		return (ft_strlen(src));
	d_l = ft_strlen(dst);
	s_l = ft_strlen(src);
	if (size <= d_l)
		return (size + s_l);
	while (src[i] && (d_l + i) < (size - 1))
	{
		dst[d_l + i] = src[i];
		i++;
	}
	dst[d_l + i] = '\0';
	return (d_l + s_l);
}
