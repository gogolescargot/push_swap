/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:53:45 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 14:48:31 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	freearray(char **array, size_t size)
{
	size_t	i;

	i = 1;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	*strndup(char const *src, size_t n)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			return (words);
		while (s[i] && s[i] != c)
			i++;
		words++;
	}
	return (words);
}

char	**split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**split_str;

	i = 0;
	j = 0;
	k = 1;
	split_str = malloc(sizeof(char *) * (count_words(s, c) + 2));
	if (!split_str || !s)
		return (NULL);
	while (i < ft_strlen(s))
	{
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j != 0)
		{
			split_str[k] = strndup(&s[i], j);
			if (!split_str[k++])
				return (freearray(split_str, k - 1), NULL);
		}
		i += j + 1;
		j = 0;
	}
	return (split_str[k] = 0, split_str[0] = "", split_str);
}
