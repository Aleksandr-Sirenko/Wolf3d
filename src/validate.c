/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:18:35 by asirenko          #+#    #+#             */
/*   Updated: 2019/03/25 18:06:05 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		maplen(char *filename, t_mlx *a)
{
	char	*line;
	char	**mas;

	a->ii = 0;
	a->linelen = 0;
	a->fd3 = open(filename, O_RDONLY);
	while (get_next_line(a->fd3, &line))
	{
		a->jj = 0;
		mas = ft_strsplit(line, ' ');
		if (a->ii == 0)
			while (mas[a->linelen])
				a->linelen++;
		while (mas[a->jj])
			a->jj++;
		free(line);
		freearr(mas);
		if (a->jj != a->linelen)
			return (0);
		a->ii++;
	}
	free(line);
	if (a->ii < 3 || a->linelen < 3)
		return (0);
	return (1);
}

int		checksymb(char *filename, t_mlx *a)
{
	char	*line;
	char	**mas;

	a->fd4 = open(filename, O_RDONLY);
	while (get_next_line(a->fd4, &line))
	{
		a->iii = 0;
		mas = ft_strsplit(line, ' ');
		while (mas[a->iii])
		{
			if (ft_strcmp(mas[a->iii], "1") != 0 && ft_strcmp(mas[a->iii], "2")
			!= 0 && ft_strcmp(mas[a->iii],
			"0") != 0 && ft_strcmp(mas[a->iii], "P") != 0)
			{
				free(line);
				freearr(mas);
				return (0);
			}
			a->iii++;
		}
		free(line);
		freearr(mas);
	}
	free(line);
	return (1);
}

int		checkplayer(char *filename)
{
	int		fd;
	char	*line;
	int		i;
	char	**mas;
	int		j;

	j = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		i = 0;
		mas = ft_strsplit(line, ' ');
		while (mas[i])
		{
			if (ft_strcmp(mas[i], "P") == 0)
				j++;
			i++;
		}
		free(line);
		freearr(mas);
	}
	free(line);
	if (j != 1)
		return (0);
	return (1);
}

int		checkfile(char *filename)
{
	int		fd;
	char	buffer[0];

	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, buffer, 0) < 0)
		return (0);
	return (1);
}

int		checkwalls(char *filename, t_mlx *a)
{
	char	*line;
	char	**m;

	a->e = 0;
	a->fd5 = open(filename, O_RDONLY);
	while (get_next_line(a->fd5, &line))
	{
		a->r = 0;
		m = ft_strsplit(line, ' ');
		if (a->e == 0 || a->e == a->maph - 1)
			if (!checkwalls2(a, m, line))
				return (0);
		if (ft_strcmp(m[0], "1") != 0 || ft_strcmp(m[a->mapw - 1], "1") != 0)
		{
			free(line);
			freearr(m);
			return (0);
		}
		a->e++;
		free(line);
		freearr(m);
	}
	free(line);
	return (1);
}
