/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazaroua <sazaroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 16:30:29 by sazaroua          #+#    #+#             */
/*   Updated: 2026/10/27 11:55:27 by sazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*res;
	int		i;

	len = ft_strlen(s);
	res = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!res)
	{
		return (NULL);
	}
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
