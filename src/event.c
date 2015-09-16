/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:47:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/14 18:28:47 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     key_hook(int keycode, t_env *e)
{
	double i = 0.6;
    mlx_clear_window(e->mlx, e->win);
	t_frac *f = e->f;
    if (keycode == 53)	// escape
        exit(0);
	if (keycode == 126)	 // up 
		f->my -= 0.1;
	if (keycode == 125)	// down
		f->my += 0.1;
	if (keycode == 123)	 // left
		f->mx -= 0.1;
	if (keycode == 124)	// right
		f->mx += 0.1;
	if (keycode == 6)
	{
		f->zoom += i;
		i -= 0.05;
	}
	if (keycode == 8)	// c || ZOOM --
	{
		f->zoom -= i;
		i += 0.05;
	}
	draw_fractal(e);
    return (0);
}
