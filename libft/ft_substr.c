/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazaroua <sazaroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 17:02:21 by sazaroua          #+#    #+#             */
/*   Updated: 2026/10/27 14:35:13 by sazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*function(char *str)
{
	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	char			*str;
	unsigned int	rest;
	unsigned int	i;

	str = NULL;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		rest = 0;
	else
		rest = s_len - start;
	i = 0;
	if (len > rest)
		len = rest;
	if (len == 0)
		return (function(str));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
