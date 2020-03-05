/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 20:05:38 by asirenko          #+#    #+#             */
/*   Updated: 2018/11/03 17:24:32 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*b;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	j = 0;
	i = start;
	b = (char *)malloc(sizeof(char) * (len + 1));
	if (!b)
		return (NULL);
	while (s[i] && j < len)
	{
		b[j] = s[i];
		i++;
		j++;
	}
	b[j] = '\0';
	return (b);
}
