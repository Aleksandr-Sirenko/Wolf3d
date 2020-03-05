/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 23:19:46 by asirenko          #+#    #+#             */
/*   Updated: 2018/10/27 23:19:50 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_rev(char *str)
{
	int		i;
	char	*n;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
		i++;
	n = (char *)malloc(sizeof(char) * (i + 1));
	while (str[j])
	{
		n[j] = str[i - 1];
		j++;
		i--;
	}
	n[j] = '\0';
	return (n);
}

char			*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = ft_rev((char *)s);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&s[ft_strlen(s) - i - 1]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	return (0);
}
