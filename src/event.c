/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:47:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/17 19:17:29 by rbaum            ###   ########.fr       */
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
		f->my -= 0.5 / f->zoom;
	if (keycode == 125)	// down
		f->my += 0.5 / f->zoom;
	if (keycode == 123)	 // left
		f->mx -= 0.5 / f->zoom;
	if (keycode == 124)	// right
		f->mx += 0.5 / f->zoom;
	if (keycode == 6)
	{
		f->zoom *= 2;
		e->iter *= 2;
	}
	// if (keycode == 8)	// c || ZOOM --
	// {
	// 	f->zoom -= 0.1;
	// }
	draw_fractal(e);
    return (0);
}
