/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:47:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/17 19:58:24 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     key_hook(int keycode, t_env *e)
{

    mlx_clear_window(e->mlx, e->win);
	t_frac *f = e->f;
    if (keycode == 53)	// escape
        exit(0);
	if (keycode == 126)	 // up 
	{
		e->m->ymax -= 0.1;
		e->m->ymin -= 0.1;
		f->my -= 0.5;
	}
	if (keycode == 125)	// down
	{
		e->m->ymax += 0.1;
		e->m->ymin += 0.1;
		f->my += 0.5;
	}
	if (keycode == 123)	 // left
	{
		e->m->xmax -= 0.1;
		e->m->xmin -= 0.1;
		f->mx -= 0.5;
	}
	if (keycode == 124)	// right
	{
		e->m->xmax += 0.1;
		e->m->xmin += 0.1;
		f->mx += 0.5;
	}
	if (keycode == 6)
	{
		if (f->zoom)
		f->zoom <<= 1;
		if (e->iter < 512)
			e->iter *= 2;
	}
	// if (keycode == 8)	// c || ZOOM --
	// {
	// 	f->zoom -= 0.1;
	// }
	draw_fractal(e);
    return (0);
}
