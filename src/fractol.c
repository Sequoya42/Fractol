/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:26:29 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/19 20:03:07 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void put_pixel(t_frac *e, int x, int y, int color)
{
	const unsigned int bytes = e->bpp / 8;
	const unsigned int p = x * bytes + y * e->line_size;
	size_t i;

	i = 0;
	while (i < bytes)
	{
		e->d[p + i] = color;
		color >>= 8;
		i++;
	}
}

int 	choose_fractal(t_env *e, int x, int y)
{
	if (e->f->n == 1)
		return (draw_mandel(e, x, y));
	else if (e->f->n == 2)
		return (draw_julia(e, x, y));
	return -1;
}

int		mouse_motion_hook(int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= WIN_X && y <= WIN_Y && e->f->n == 2)
	{
		e->f->cr += ((double)e->m->omy - (double)y) / 300.0;
		e->f->ci += ((double)e->m->omx - (double)x) / 300.0;

	}
	e->m->omx = x;
	e->m->omy = y;
	return (0);
}

int draw_fractal(t_env *e)
{
    int 	c;
	int 	ch; // choice of fractal
	double  x;
	double  y;

	x = 0.0;
	y = 0.0;
	// mlx_key_hook(e->win, key_hook, e);
	// mlx_mouse_hook(e->win, mouse_hook, e);
//	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK,
//				mouse_motion_hook, e);
    while (y < WIN_Y)
    {
        x = 0;
        while (x < WIN_Y)
        {
       		ch = choose_fractal(e, y, x);
       	  	c = rainbow_color(ch, e);
			put_pixel(e->f, y, x, c);
            x++;
        }
        y++;
    }
    		printf("%f\t%f\n", e->f->cr, e->f->ci);
	mlx_put_image_to_window(e->mlx, e->win, e->f->img, 0, 0);
    return 0;
}