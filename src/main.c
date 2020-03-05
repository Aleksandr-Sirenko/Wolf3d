/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:51:55 by asirenko          #+#    #+#             */
/*   Updated: 2019/03/25 18:01:29 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw(t_mlx *a)
{
	a->n = 0;
	a->x = 0;
	a->img = mlx_new_image(a->mlx, SCREENW, SCREENH);
	a->data = mlx_get_data_addr(a->img, &a->bpp, &a->sl, &a->endian);
	while (a->x < SCREENW)
	{
		preinit(a);
		findstep(a);
		checkhit(a);
		calcdist(a);
		chtext(a);
		drawline(a);
		calcfloor(a);
		drawfloor(a);
		a->x++;
	}
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	drawhands(a);
}

void	help(void)
{
	ft_putendl("Move|Rotate: Arrows");
	ft_putendl("Acceleration: Shift");
	ft_putendl("Hide|Show torch: H");
	ft_putendl("Hide|Show shade: T");
	ft_putendl("Open|Close door: E");
}

int		main(int argc, char **argv)
{
	t_mlx a;

	if (argc != 2)
	{
		ft_putendl("usage: ./wolf3d <map_file>");
		return (0);
	}
	if (validate(argv[1], &a) == 0)
		return (0);
	help();
	init(&a);
	playerposition(argv[1], &a, 0, 0);
	readmap(argv[1], &a, 0, 0);
	draw(&a);
	mlx_hook(a.win, 2, 2, keypress, &a);
	mlx_hook(a.win, 3, 3, keydown, &a);
	mlx_loop_hook(a.mlx, movve, &a);
	mlx_hook(a.win, 17, 1L << 17, exit_x, (void *)0);
	mlx_loop(a.mlx);
	return (0);
}
