/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:47:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/18 15:21:09 by rbaum            ###   ########.fr       */
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
		change_val(e);
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
	if (button == MB_L && x < (WIN_X - 50) && y < (WIN_Y - 50) && x > 50 && y > 50)
	{
		change_val(e);
		ft_putnbrn(button);
	}
	x = y;
	(void)e;
	draw_fractal(e);
	return button;
}