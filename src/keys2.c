/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:45:50 by asirenko          #+#    #+#             */
/*   Updated: 2019/03/24 18:05:56 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		exit_x(void)
{
	exit(1);
	return (0);
}

int		keypress2(int keycode, t_mlx *a)
{
	if (keycode == 14)
		if (a->neardoor == 1)
		{
			if (a->door == 7)
				a->door = 4;
			else
				a->door = 7;
			mlx_clear_window(a->mlx, a->win);
			mlx_destroy_image(a->mlx, a->img);
			draw(a);
		}
	if (keycode == 4)
	{
		a->hands++;
		if (a->hands == 10)
			a->hands = 0;
	}
	if (keycode == 17)
	{
		a->shade++;
		if (a->shade == 10)
			a->shade = 0;
	}
	return (0);
}

int		keypress(int keycode, t_mlx *a)
{
	if (keycode == 126)
		a->keyup = 1;
	if (keycode == 125)
		a->keydown = 1;
	if (keycode == 123)
		a->keyleft = 1;
	if (keycode == 124)
		a->keyright = 1;
	if (keycode == 257)
		a->shiftkey = 1;
	if (keycode == 53)
		exit_x();
	keypress2(keycode, a);
	return (0);
}

int		keydown(int keycode, t_mlx *a)
{
	if (keycode == 126)
		a->keyup = 0;
	if (keycode == 125)
		a->keydown = 0;
	if (keycode == 123)
		a->keyleft = 0;
	if (keycode == 124)
		a->keyright = 0;
	if (keycode == 257)
	{
		a->shiftkey = 0;
		a->ms = 0.08;
	}
	return (0);
}
