/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:34:29 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/17 19:16:39 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../libft/inc/libft.h"
#include <mlx.h>
#include <math.h>
#include <time.h>
#include <stdio.h> // REMOVE THIS LINE

# define WIN_X 512
# define WIN_Y 512
# define MAX_ITER e->iter

# define CXMIN e->m->xmin
# define CXMAX e->m->xmax
# define CYMIN e->m->ymin
# define CYMAX e->m->ymax

#define SQUARE(x) x * x

# define PIXW (CXMAX - CXMIN) / (WIN_X - 1)
# define PIXH (CYMAX - CYMIN) / (WIN_Y - 1)

typedef struct s_mod
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;

}				t_mod;

typedef struct s_frac
{
	char		*d;			// buffer where the image will be stored (d is for data)
	double		cr;			// c is constant, cr is the real part
	double		ci;			// ci is the imaginary part
	double		nr;			// new real
	double		ni;			// new imaginary
	double		orl;			// old real
	double		oi;			// old imaginary
	double		zoom;

	double		mx;			// move x
	double		my;			// move y

	int 		n;			// number to choose which fractal
	int			bpp;
	int			endian;
	int			line_size;
	void		*img;

}				t_frac;

typedef struct  s_env
{
    void        *mlx;
    void        *win;
	t_frac		*f;
	t_mod		*m;
	double		t;
	double		iter;
}               t_env;

//------------Events--------------//

int				key_hook(int keycode, t_env *e);
//------------Rainbow-Color-------------//
int				rainbow_color(int i, double iter);
int				lerp(float v0, float v1, float t);
float			normalize(double x, double y, int i);
//----------Ft_init---------------//
t_env			*init_env(char *av);
//------------------------------//
int				draw_julia(t_env *e, int x, int y);
int				draw_mandel(t_env *e, int x, int y);
int				draw_fractal(t_env *e);

//------------------------------//


#endif

