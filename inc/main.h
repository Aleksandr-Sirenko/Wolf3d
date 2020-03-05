/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:19:02 by asirenko          #+#    #+#             */
/*   Updated: 2019/03/25 18:40:47 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAIN_H
# define _MAIN_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../lib/libft/libft.h"
# define SCREENW 1600
# define SCREENH 900
# define TEXTUREC 10

typedef struct	s_texture
{
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
	int			w;
	int			h;
}				t_texture;

typedef struct	s_fl
{
	double		flx;
	double		fly;
	double		cdst;
	double		dwall;
	double		dpl;
	double		w;
	double		cflx;
	double		cfly;
	int			ftexx;
	int			ftexy;
}				t_fl;

typedef struct	s_mlx
{
	int			**map;
	int			mapw;
	int			maph;
	double		plx;
	double		ply;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		dst;
	double		ms;
	double		rs;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
	int			lh;
	int			sty;
	int			endy;
	double		wx;
	int			texx;
	int			texy;
	int			x;
	int			y;
	int			n;
	int			d;
	int			fd;
	int			fd2;
	int			fd3;
	int			fd4;
	int			fd5;
	int			z;
	int			ii;
	int			iii;
	size_t		jj;
	double		shf;
	int			hands;
	int			shade;
	int			keyup;
	int			keydown;
	int			keyleft;
	int			keyright;
	double		shadedst;
	double		shad;
	int			shiftkey;
	int			door;
	int			neardoor;
	size_t		linelen;
	int			r;
	int			e;
	t_texture	*t;
	t_fl		f;
}				t_mlx;

int				keypress(int keycode, t_mlx *a);
void			draw(t_mlx *a);
void			loadtexture(t_mlx *a);
void			mapsize(char *filename, t_mlx *a);
void			readmap(char *filename, t_mlx *a, int i, int j);
void			playerposition(char *filename, t_mlx *a, int i, int j);
int				exit_x(void);
void			preinit(t_mlx *a);
void			findstep(t_mlx *a);
void			checkhit(t_mlx *a);
void			chtext(t_mlx *a);
void			calcdist(t_mlx *a);
void			drawline(t_mlx *a);
void			calcfloor(t_mlx *a);
void			drawfloor(t_mlx *a);
void			init(t_mlx *a);
void			drawhands(t_mlx *a);
int				movve(t_mlx *a);
int				keydown(int keycode, t_mlx *a);
void			loadtexture(t_mlx *a);
void			doortexture(t_mlx *a);
int				maplen(char *filename, t_mlx *a);
int				checksymb(char *filename, t_mlx *a);
int				checkplayer(char *filename);
int				checkfile(char *filename);
int				checkwalls(char *filename, t_mlx *a);
int				validate(char *filename, t_mlx *a);
void			freearr(char **arr);
void			rotateleft(t_mlx *a);
void			rotateright(t_mlx *a);
int				checkwalls2(t_mlx *a, char **m, char *line);
#endif
