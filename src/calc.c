/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:09:22 by asirenko          #+#    #+#             */
/*   Updated: 2019/03/22 18:38:39 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	drawhands(t_mlx *a)
{
	if (a->hands % 2 != 0)
		mlx_put_image_to_window(a->mlx, a->win, a->t[8].img,
	(SCREENW / 1.8), SCREENH - a->t[8].h);
}

void	findstep(t_mlx *a)
{
	if (a->raydirx < 0)
	{
		a->stepx = -1;
		a->sidedistx = (a->plx - a->mapx) * a->deltadistx;
	}
	else
	{
		a->stepx = 1;
		a->sidedistx = (a->mapx + 1.0 - a->plx) * a->deltadistx;
	}
	if (a->raydiry < 0)
	{
		a->stepy = -1;
		a->sidedisty = (a->ply - a->mapy) * a->deltadisty;
	}
	else
	{
		a->stepy = 1;
		a->sidedisty = (a->mapy + 1.0 - a->ply) * a->deltadisty;
	}
}

void	calcdist(t_mlx *a)
{
	if (a->side == 0 || a->side == 1)
		a->dst = (a->mapx - a->plx + (1 - a->stepx) / 2) / a->raydirx;
	else
		a->dst = (a->mapy - a->ply + (1 - a->stepy) / 2) / a->raydiry;
	a->lh = (int)(SCREENH / a->dst);
	a->sty = -a->lh / 2 + SCREENH / 2;
	if (a->sty < 0)
		a->sty = 0;
	a->endy = a->lh / 2 + SCREENH / 2;
	if (a->endy >= SCREENH)
		a->endy = SCREENH - 1;
	if (a->side == 0 || a->side == 1)
		a->wx = a->ply + a->dst * a->raydiry;
	else
		a->wx = a->plx + a->dst * a->raydirx;
	a->wx -= floor((a->wx));
	a->texx = (int)(a->wx * a->t[a->n].w);
}

void	checkhit(t_mlx *a)
{
	while (a->hit == 0)
	{
		if (a->sidedistx < a->sidedisty)
		{
			a->sidedistx += a->deltadistx;
			a->mapx += a->stepx;
			if (a->raydirx > 0)
				a->side = 0;
			else
				a->side = 1;
		}
		else
		{
			a->sidedisty += a->deltadisty;
			a->mapy += a->stepy;
			if (a->raydiry > 0)
				a->side = 2;
			else
				a->side = 3;
		}
		if (a->map[a->mapx][a->mapy] > 0)
		{
			a->hit = 1;
		}
	}
}
