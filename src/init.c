/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:21:49 by asirenko          #+#    #+#             */
/*   Updated: 2019/03/24 16:55:10 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init(t_mlx *a)
{
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, SCREENW, SCREENH, "WOLF");
	loadtexture(a);
	a->dirx = -1;
	a->diry = 0;
	a->planex = 0;
	a->planey = 0.66;
	a->rs = 0.1;
	a->hands = 1;
	a->shade = 0;
	a->keyup = 0;
	a->keydown = 0;
	a->keyright = 0;
	a->keyleft = 0;
	a->ms = 0.08;
	a->door = 4;
}

void	preinit(t_mlx *a)
{
	a->shf = 2;
	a->shadedst = 0.6;
	if (a->hands % 2 == 0)
	{
		a->shf = 8;
		a->shadedst = 0.15;
	}
	a->camerax = 2 * a->x / (double)SCREENW - 1;
	a->raydirx = a->dirx + a->planex * a->camerax;
	a->raydiry = a->diry + a->planey * a->camerax;
	a->mapx = (int)a->plx;
	a->mapy = (int)a->ply;
	a->deltadistx = fabs(1 / a->raydirx);
	a->deltadisty = fabs(1 / a->raydiry);
	a->hit = 0;
	a->f.dpl = 0.0;
	a->neardoor = 0;
	a->z = a->endy + 1;
}
