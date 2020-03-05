/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:16:28 by asirenko          #+#    #+#             */
/*   Updated: 2019/03/22 18:18:10 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	drawline(t_mlx *a)
{
	a->y = a->sty;
	while (a->y < a->endy)
	{
		a->shad = a->dst * a->shf;
		if (a->shade % 2 != 0)
			a->shad = 1;
		if (a->dst < a->shadedst && a->shade % 2 == 0)
			a->shad = a->shadedst * a->shf;
		a->d = a->y * 256 - SCREENH * 128 + a->lh * 128;
		a->texy = ((a->d * a->t[a->n].h) / a->lh) / 256;
		a->data[a->y * a->sl + a->x * a->bpp / 8] =
		(unsigned char)a->t[a->n].data[a->texy * a->t[a->n].
		sl + a->texx * a->t[a->n].bpp / 8] / a->shad;
		a->data[a->y * a->sl + a->x * a->bpp / 8 + 1] =
		(unsigned char)a->t[a->n].data[a->texy * a->t[a->n].
		sl + a->texx * a->t[a->n].bpp / 8 + 1] / a->shad;
		a->data[a->y * a->sl + a->x * a->bpp / 8 + 2] =
		(unsigned char)a->t[a->n].data[a->texy * a->t[a->n].
		sl + a->texx * a->t[a->n].bpp / 8 + 2] / a->shad;
		a->y++;
	}
}

void	drawcell(t_mlx *a)
{
	a->data[(SCREENH - a->z) * a->sl + a->x * a->bpp / 8] =
	(unsigned char)a->t[6].data[a->f.ftexy * a->t[6].sl +
	a->f.ftexx * a->t[6].bpp / 8] / a->shad;
	a->data[(SCREENH - a->z) * a->sl + a->x * a->bpp / 8 + 1] =
	(unsigned char)a->t[6].data[a->f.ftexy * a->t[6].sl +
	a->f.ftexx * a->t[6].bpp / 8 + 1] / a->shad;
	a->data[(SCREENH - a->z) * a->sl + a->x * a->bpp / 8 + 2] =
	(unsigned char)a->t[6].data[a->f.ftexy * a->t[6].sl +
	a->f.ftexx * a->t[6].bpp / 8 + 2] / a->shad;
}

void	drawfloor(t_mlx *a)
{
	a->f.dwall = a->dst;
	while (a->z < SCREENH)
	{
		a->f.cdst = SCREENH / (2.0 * a->z - SCREENH);
		a->shad = a->f.cdst * a->shf;
		if (a->shade % 2 != 0)
			a->shad = 1;
		a->f.w = (a->f.cdst - a->f.dpl) / (a->f.dwall - a->f.dpl);
		a->f.cflx = a->f.w * a->f.flx + (1.0 - a->f.w) * a->plx;
		a->f.cfly = a->f.w * a->f.fly + (1.0 - a->f.w) * a->ply;
		a->f.ftexx = (int)(a->f.cflx * 64) % 64;
		a->f.ftexy = (int)(a->f.cfly * 64) % 64;
		a->data[a->z * a->sl + a->x * a->bpp / 8] =
		(unsigned char)a->t[5].data[a->f.ftexy * a->t[5].sl
		+ a->f.ftexx * a->t[5].bpp / 8] / a->shad;
		a->data[a->z * a->sl + a->x * a->bpp / 8 + 1] =
		(unsigned char)a->t[5].data[a->f.ftexy * a->t[5].sl
		+ a->f.ftexx * a->t[5].bpp / 8 + 1] / a->shad;
		a->data[a->z * a->sl + a->x * a->bpp / 8 + 2] =
		(unsigned char)a->t[5].data[a->f.ftexy * a->t[5].sl
		+ a->f.ftexx * a->t[5].bpp / 8 + 2] / a->shad;
		drawcell(a);
		a->z++;
	}
}

void	calcfloor(t_mlx *a)
{
	if ((a->side == 0 || a->side == 1) && a->raydirx > 0)
	{
		a->f.flx = a->mapx;
		a->f.fly = a->mapy + a->wx;
	}
	else if ((a->side == 0 || a->side == 1) && a->raydirx < 0)
	{
		a->f.flx = a->mapx + 1.0;
		a->f.fly = a->mapy + a->wx;
	}
	else if ((a->side == 2 || a->side == 3) && a->raydiry > 0)
	{
		a->f.flx = a->mapx + a->wx;
		a->f.fly = a->mapy;
	}
	else
	{
		a->f.flx = a->mapx + a->wx;
		a->f.fly = a->mapy + 1.0;
	}
	if (a->endy < 0)
		a->endy = SCREENH;
}
