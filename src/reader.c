/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:52:57 by asirenko          #+#    #+#             */
/*   Updated: 2019/03/13 15:47:41 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	freearr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	mapsize(char *filename, t_mlx *a)
{
	int		fd;
	char	*line;
	int		i;
	char	**cache;
	int		j;

	j = 0;
	i = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (i == 0)
		{
			cache = ft_strsplit(line, ' ');
			while (cache[j])
				j++;
			a->mapw = j;
			freearr(cache);
		}
		a->maph++;
		i++;
		free(line);
	}
	free(line);
}

void	playerposition(char *filename, t_mlx *a, int i, int j)
{
	char	*line;
	char	**cache;

	a->fd2 = open(filename, O_RDONLY);
	while (get_next_line(a->fd2, &line))
	{
		j = 0;
		cache = ft_strsplit(line, ' ');
		while (cache[j])
		{
			if (ft_strcmp(cache[j], "P") == 0)
			{
				a->plx = i + 0.5;
				a->ply = j + 0.5;
				freearr(cache);
				free(line);
				return ;
			}
			j++;
		}
		i++;
		freearr(cache);
		free(line);
	}
	free(line);
}

void	readmap(char *filename, t_mlx *a, int i, int j)
{
	char	*line;
	char	**cache;

	a->map = malloc(sizeof(int**) * a->maph);
	a->fd = open(filename, O_RDONLY);
	while (get_next_line(a->fd, &line))
	{
		j = 0;
		a->map[i] = malloc(sizeof(int*) * a->mapw);
		cache = ft_strsplit(line, ' ');
		while (cache[j])
		{
			if (ft_strcmp(cache[j], "P") == 0)
				a->map[i][j] = 0;
			else
				a->map[i][j] = ft_atoi(cache[j]);
			j++;
		}
		i++;
		freearr(cache);
		free(line);
	}
	free(line);
}
