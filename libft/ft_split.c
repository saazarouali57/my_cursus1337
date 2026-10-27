/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazaroua <sazaroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:18:32 by username          #+#    #+#             */
/*   Updated: 2026/10/27 17:31:51 by sazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_world(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	ft_free(char **res, int j)
{
	while (j > 0)
	{
		j--;
		free(res[j]);
	}
	free(res);
}

static int	ft_len(char const *s, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

// char	**ft_split(char const *s, char c)
// {
// 	char	**res;
// 	int		count_w;
// 	int		j;
// 	int		i;
// 	int		k;

// 	if (!s)
// 		return (NULL);
// 	count_w = ft_count_world(s, c);
// 	res = malloc(sizeof(char *) * (count_w + 1));
// 	if (!res)
// 		return (NULL);
// 	j = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		while (s[i] && s[i] == c)
// 			i++;
// 		if (!s[i])
// 			break ;
// 		k = 0;
// 		res[j] = malloc(sizeof(char) * (ft_len(&s[i], c) + 1));
// 		if (!res[j])
// 		{
// 			ft_free(res, j);
// 			return (NULL);
// 		}
// 		while (s[i] && s[i] != c)
// 			res[j][k++] = s[i++];
// 		res[j][k] = '\0';
// 		j++;
// 	}
// 	res[j] = NULL;
// 	return (res);
// }
static int	ft_fill_split(char **res, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		res[j] = ft_substr(s, i, ft_len(&s[i], c));
		if (!res[j])
			return (ft_free(res, j), 0);
		i += ft_len(&s[i], c);
		j++;
	}
	res[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_count_world(s, c) + 1));
	if (!res)
		return (NULL);
	if (!ft_fill_split(res, s, c))
		return (NULL);
	return (res);
}
