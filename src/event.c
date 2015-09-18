/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:47:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/18 14:20:04 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//FIND GOOD RATIO TO * INSTEAD OF + A VALUE

void	change_val(t_env *e)
{
		e->m->xmin *= 0.5;
		e->m->xmax *= 0.5;
		e->m->ymax *= 0.5;
		e->m->ymin *= 0.5;
}

int     key_hook(int keycode, t_env *e)
{

    mlx_clear_window(e->mlx, e->win);
    ft_putnbrn(keycode);
	t_frac *f = e->f;
    if (keycode == MK_ESC)
        exit(0);
	if (keycode == 126)	 // up 
	{
		e->m->ymax -= 0.1 * MEH;
		e->m->ymin -= 0.1 * MEH;
		f->my -= 0.5;
	}
	if (keycode == MK_DW)	// down
	{
		e->m->ymax += 0.1 * MEH;
		e->m->ymin += 0.1 * MEH;
		f->my += 0.5;
	}
	if (keycode == MK_LT)	 // left
	{
		e->m->xmax -= 0.1 * MEH;
		e->m->xmin -= 0.1 * MEH;
		f->mx -= 0.5;
	}
	if (keycode == MK_RT)	// right
	{
		e->m->xmax += 0.1 * MEH;
		e->m->xmin += 0.1 * MEH;
		f->mx += 0.5;
	}
	if (keycode == MK_Z)
	{
		change_val(e);
		f->zoom <<= 1;
		if (e->iter < 512)
			e->iter *= 2;
	}
	if (keycode == MK_F)
		e->frequency *= 2;
	// if (keycode == 8)	// c || ZOOM --
	// {
	// 	f->zoom -= 0.1;
	// }
	draw_fractal(e);
    return (0);
}
