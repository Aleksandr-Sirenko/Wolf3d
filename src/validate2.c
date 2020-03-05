/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:56:39 by asirenko          #+#    #+#             */
/*   Updated: 2019/03/24 18:34:08 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		checkwalls2(t_mlx *a, char **m, char *line)
{
	while (m[a->r])
	{
		if (ft_strcmp(m[a->r], "1") != 0)
		{
			free(line);
			freearr(m);
			return (0);
		}
		a->r++;
	}
	return (1);
}

int		validate2(char *filename, t_mlx *a)
{
	if (checkplayer(filename) == 0)
	{
		ft_putendl("Wrong player count");
		return (0);
	}
	if (checkwalls(filename, a) == 0)
	{
		ft_putendl("Wrong walls location");
		return (0);
	}
	return (1);
}

int		validate(char *filename, t_mlx *a)
{
	a->maph = 0;
	a->mapw = 0;
	if (checkfile(filename) == 0)
	{
		ft_putendl("Incorrect file");
		return (0);
	}
	mapsize(filename, a);
	if (maplen(filename, a) == 0)
	{
		ft_putendl("Wrong map lenght|height");
		return (0);
	}
	if (checksymb(filename, a) == 0)
	{
		ft_putendl("Wrong symbols in map");
		return (0);
	}
	if (!validate2(filename, a))
		return (0);
	return (1);
}
