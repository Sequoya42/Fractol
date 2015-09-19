/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:47:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/19 18:40:55 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_val(t_env *e, int x, int y, double zoom)
{
	double move_x;
	double move_y;

	e->f->zoom *= zoom;
	printf("Value of zoom %f\n", e->f->zoom);
	move_x = ((double)x - (WIN_X / 2.0)) / (WIN_X / 2);
	move_y = ((double)y - (WIN_Y / 2.0)) / (WIN_Y / 2);
	e->f->mx += move_x / e->f->zoom;
	e->f->my += move_y / e->f->zoom;
}

void	move_coor(t_env *e, t_frac *f, int keycode)
{
	if (keycode == MK_UP)	 // up 
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
}
int     key_hook(int keycode, t_env *e)
{
    mlx_clear_window(e->mlx, e->win);
	t_frac *f = e->f;
    if (keycode == MK_ESC)
        exit(0);
    move_coor(e, f, keycode);
	if (keycode == MK_Z)
	{
//		change_val(e);
//		f->zoom <<= 1;
		if (e->iter < 512)
			e->iter *= 2;
	}
	if (keycode == MK_F)
		e->frequency *= 2;
	if (keycode == MK_C)
	{
		f->n = (f->n == 2) ?  1 : 2;
		init_frac(ft_itoa(f->n));
	}
	draw_fractal(e);
    return (0);
}

int 	mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{	
		change_val(e, x, y, 1.05);
	}
	draw_fractal(e);
	return button;
}











































