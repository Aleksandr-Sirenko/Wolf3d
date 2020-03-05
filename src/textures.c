/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:36:26 by asirenko          #+#    #+#             */
/*   Updated: 2019/03/25 18:01:40 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	loadtexture(t_mlx *a)
{
	int		n;
	char	*path;
	char	*fn;

	n = 0;
	a->t = malloc(sizeof(t_texture) * TEXTUREC);
	while (n < TEXTUREC)
	{
		fn = ft_itoa(n + 1);
		path = ft_strjoin("textures/", fn);
		a->t[n].img = mlx_xpm_file_to_image(a->mlx, path,
		&a->t[n].w, &a->t[n].h);
		a->t[n].data = mlx_get_data_addr(a->t[n].img,
		&a->t[n].bpp, &a->t[n].sl, &a->t[n].endian);
		free(path);
		free(fn);
		n++;
	}
}

void	doortexture(t_mlx *a)
{
	if (a->map[a->mapx][a->mapy] == 2)
	{
		if (a->side == 0)
			a->n = a->door;
		if (a->side == 1)
			a->n = a->door;
		if (a->side == 2 || a->side == 3)
			a->n = 9;
		if ((int)a->ply == (int)a->mapy && a->plx <= a->mapx + 2
		&& a->plx >= a->mapx - 1)
			a->neardoor = 1;
	}
}

void	chtext(t_mlx *a)
{
	if ((a->side == 1 || a->side == 0) && a->raydirx > 0)
		a->texx = a->t[a->n].w - a->texx - 1;
	if ((a->side == 3 || a->side == 2) && a->raydiry < 0)
		a->texx = a->t[a->n].w - a->texx - 1;
	if (a->side == 0)
		a->n = 0;
	if (a->side == 1)
		a->n = 1;
	if (a->side == 2)
		a->n = 2;
	if (a->side == 3)
		a->n = 3;
	doortexture(a);
}
