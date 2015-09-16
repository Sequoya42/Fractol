/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:34:29 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/15 21:01:42 by rbaum            ###   ########.fr       */
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
# define MAX_ITER 128

# define CXMIN -2.5
# define CXMAX -1.5
# define CYMIN -2.0
# define CYMAX 2.0

#define SQUARE(x) x * x

# define PIXW (CXMAX - CXMIN) / WIN_X
# define PIXH (CYMAX - CYMIN) / WIN_Y

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
	int			iter;
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
	double		t;
}               t_env;

//------------Events--------------//

int				key_hook(int keycode, t_env *e);
//------------Rainbow-Color-------------//
int				rainbow_color(int i, double x, double y);
int				lerp(float v0, float v1, float t);
float			normalize(double x, double y, int i);
//----------Ft_init---------------//
t_frac			*init_frac(char *av);
t_env			*init_env(t_frac *frac);
//------------------------------//
int				draw_julia(t_frac *f, int x, int y);
int				draw_mandel(t_frac *f, int x, int y);
int				draw_fractal(t_env *e);

//------------------------------//


#endif

