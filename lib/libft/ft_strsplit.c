/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 23:07:32 by asirenko          #+#    #+#             */
/*   Updated: 2018/11/29 18:39:02 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int i;
	int count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_word(char const *s, char c, int i)
{
	int		k;
	char	*word;
	int		n;

	n = i;
	k = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
	{
		k++;
		i++;
	}
	word = (char *)malloc(sizeof(char) * (k + 1));
	if (!word)
		return (NULL);
	k = 0;
	while (s[n] != '\0' && s[n] != c)
	{
		word[k] = s[n];
		k++;
		n++;
	}
	word[k] = '\0';
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**mas;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (!s)
		return (NULL);
	mas = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!mas)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
		{
			mas[x] = ft_word(s, c, i);
			x++;
		}
		i++;
	}
	mas[x] = 0;
	return (mas);
}
