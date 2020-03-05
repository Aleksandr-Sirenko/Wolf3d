/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:04:25 by asirenko          #+#    #+#             */
/*   Updated: 2019/03/24 18:13:35 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	moveforward2(t_mlx *a)
{
	if (a->diry > 0)
	{
		if (a->map[(int)(a->plx)][(int)((a->ply + 0.1) + a->diry * a->ms)] == 0
		|| (a->map[(int)(a->plx)][(int)((a->ply + 0.1) +
		a->diry * a->ms)] == 2 && a->door == 7))
			a->ply += a->diry * a->ms;
	}
	else
	{
		if (a->map[(int)(a->plx)][(int)((a->ply - 0.1) + a->diry * a->ms)] == 0
		|| (a->map[(int)(a->plx)][(int)((a->ply - 0.1)
		+ a->diry * a->ms)] == 2 && a->door == 7))
			a->ply += a->diry * a->ms;
	}
}

void	moveforward(t_mlx *a)
{
	if (a->dirx > 0)
	{
		if (a->map[(int)((a->plx + 0.1) + a->dirx * a->ms)][(int)a->ply] == 0
		|| (a->map[(int)((a->plx + 0.1) + a->dirx * a->ms)]
		[(int)a->ply] == 2 && a->door == 7))
			a->plx += a->dirx * a->ms;
	}
	else
	{
		if (a->map[(int)((a->plx - 0.1) + a->dirx * a->ms)][(int)a->ply] == 0
		|| (a->map[(int)((a->plx - 0.1) + a->dirx * a->ms)]
		[(int)a->ply] == 2 && a->door == 7))
			a->plx += a->dirx * a->ms;
	}
	moveforward2(a);
}

void	movebackwards2(t_mlx *a)
{
	if (a->diry > 0)
	{
		if (a->map[(int)(a->plx)][(int)((a->ply - 0.1) - a->diry * a->ms)] == 0
		|| (a->map[(int)(a->plx)][(int)((a->ply - 0.1) - a->diry
		* a->ms)] == 2 && a->door == 7))
			a->ply -= a->diry * a->ms;
	}
	else
	{
		if (a->map[(int)(a->plx)][(int)((a->ply + 0.1) - a->diry * a->ms)] == 0
		|| (a->map[(int)(a->plx)][(int)((a->ply + 0.1) - a->diry
		* a->ms)] == 0 && a->door == 7))
			a->ply -= a->diry * a->ms;
	}
}

void	movebackwards(t_mlx *a)
{
	if (a->dirx > 0)
	{
		if (a->map[(int)((a->plx - 0.1) - a->dirx * a->ms)][(int)a->ply] == 0
		|| (a->map[(int)((a->plx - 0.1) - a->dirx * a->ms)]
		[(int)a->ply] == 2 && a->door == 7))
			a->plx -= a->dirx * a->ms;
	}
	else
	{
		if (a->map[(int)((a->plx + 0.1) - a->dirx * a->ms)][(int)a->ply] == 0
		|| (a->map[(int)((a->plx + 0.1) - a->dirx * a->ms)]
		[(int)a->ply] == 2 && a->door == 7))
			a->plx -= a->dirx * a->ms;
	}
	movebackwards2(a);
}

int		movve(t_mlx *a)
{
	if (a->keyup == 1)
		moveforward(a);
	if (a->keydown == 1)
		movebackwards(a);
	if (a->keyleft == 1)
		rotateleft(a);
	if (a->keyright == 1)
		rotateright(a);
	if (a->shiftkey == 1)
		a->ms = 0.14;
	mlx_clear_window(a->mlx, a->win);
	mlx_destroy_image(a->mlx, a->img);
	draw(a);
	return (0);
}
