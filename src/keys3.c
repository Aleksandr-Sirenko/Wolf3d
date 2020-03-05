/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:13:15 by asirenko          #+#    #+#             */
/*   Updated: 2019/03/24 18:13:37 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	rotateleft(t_mlx *a)
{
	double dirx2;
	double planex2;

	dirx2 = a->dirx;
	planex2 = a->planex;
	a->dirx = a->dirx * cos(a->rs) - a->diry * sin(a->rs);
	a->diry = dirx2 * sin(a->rs) + a->diry * cos(a->rs);
	a->planex = a->planex * cos(a->rs) - a->planey * sin(a->rs);
	a->planey = planex2 * sin(a->rs) + a->planey * cos(a->rs);
}

void	rotateright(t_mlx *a)
{
	double dirx2;
	double planex2;

	planex2 = a->planex;
	dirx2 = a->dirx;
	a->dirx = a->dirx * cos(-a->rs) - a->diry * sin(-a->rs);
	a->diry = dirx2 * sin(-a->rs) + a->diry * cos(-a->rs);
	a->planex = a->planex * cos(-a->rs) - a->planey * sin(-a->rs);
	a->planey = planex2 * sin(-a->rs) + a->planey * cos(-a->rs);
}
