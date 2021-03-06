/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:34:29 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/23 13:41:51 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/inc/libft.h"
# include <mlx.h>
# include <math.h>
# include <time.h>

# define WIN_X 512
# define WIN_Y 512
# define MAX_ITER e->iter

# define CXMIN e->m->xmin
# define CXMAX e->m->xmax
# define CYMIN e->m->ymin
# define CYMAX e->m->ymax

# define SQUARE(x) x * x

# define PIXW e->zx
# define PIXH e->zy

# define MEH PIXW/PIXH
# define MK_UP	126
# define MK_DW	125
# define MK_LT	123
# define MK_RT	124

# define MK_Z	6
# define MK_C 	8
# define MK_F	3
# define MK_D 	2
# define MK_H	4
# define MK_R  	15
# define MK_B	11
# define MK_N	45

# define MK_ESC	53
# define MK_PL	69
# define MK_MI	78

# define MB_L	1
# define MB_R	2
# define MB_M	3
# define MB_UP	5
# define MB_DW	4

# define MOTION_NOTIFY			6
# define PTR_MOTION_MASK		(1L << 6)

typedef struct	s_mod
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		omx;
	double		omy;

}				t_mod;

typedef struct	s_frac
{
	char		*d;
	double		cr;
	double		ci;
	double		pr;
	double		pi;
	double		nrl;
	double		ni;
	double		orl;
	double		oi;
	double		zoom;

	double		mx;
	double		my;

	int			n;
	int			bpp;
	int			endian;
	int			line_size;
	void		*img;

}				t_frac;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_frac		*f;
	t_mod		*m;
	double		t;
	double		frequency;
	double		iter;
	double		zx;
	double		zy;
	int			color;
}				t_env;

int				key_hook(int keycode, t_env *e);
int				motion_hook(int x, int y, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);

int				rainbow_color(int i, t_env *e);
int				lerp(float v0, float v1, float t);
float			normalize(double x, double y, int i);

t_frac			*init_frac(char *av);
t_env			*init_env(char *av);

int				draw_julia(t_env *e, int x, int y);
int				draw_mandel(t_env *e, int x, int y);
int				draw_ship(t_env *e, int x, int y);
int				draw_fractal(t_env *e);

int				please_choose(void);
void			ft_reset(t_env *e);

#endif
