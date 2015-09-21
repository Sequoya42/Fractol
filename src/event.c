/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:47:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/21 16:31:00 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_coor(t_env *e, int keycode)
{
	if (keycode == MK_DW)	 // up 
	{
		e->m->ymax -= 0.1;
		e->m->ymin -= 0.1;
	    e->zy =  ((CYMAX - CYMIN) / (WIN_Y - 1));
	}
	if (keycode == MK_UP)	// down
	{
		e->m->ymax += 0.1;
		e->m->ymin += 0.1;
	    e->zy =  ((CYMAX - CYMIN) / (WIN_Y - 1));
	}
	if (keycode == MK_LT)	 // left
	{
		e->m->xmax -= 0.1;
		e->m->xmin -= 0.1;
    	e->zx = ((CXMAX - CXMIN) / (WIN_X - 1));
	}
	if (keycode == MK_RT)	// right
	{
		e->m->xmax += 0.1;
		e->m->xmin += 0.1;
	    e->zx = ((CXMAX - CXMIN) / (WIN_X - 1));
	}
}

int     key_hook(int keycode, t_env *e)
{
    mlx_clear_window(e->mlx, e->win);
	t_frac *f = e->f;
	move_coor(e, keycode);
    if (keycode == MK_ESC)
        exit(0);
	else if (keycode == MK_F)
		e->frequency *= 2;
	else if (keycode == MK_PL)
		MAX_ITER = (MAX_ITER < 8000) ? MAX_ITER * 2 : MAX_ITER;
	else if (keycode == MK_MI)
		MAX_ITER = (MAX_ITER > 2) ? MAX_ITER / 2 : MAX_ITER;
	else if (keycode == MK_C)
	{
		f->n = (f->n == 2) ?  1 : 2;
		init_frac(ft_itoa(f->n));
	}
	draw_fractal(e);
    return (0);
}

int 	mouse_hook(int button, int x, int y, t_env *e)
{
	double dcr;
	double dci;

	dcr = x;
	dci = y;
	e->f->cr = CXMAX - CXMIN;
	e->f->ci = CYMAX - CYMIN;
	e->f->mx = ((double)x / WIN_X * e->f->cr) - e->f->cr / 2 + e->f->mx;
	e->f->my = (double)(WIN_Y - y) / WIN_Y * e->f->ci - e->f->ci / 2 + e->f->my;
	if (button == MB_L || button == MB_UP)
	{
		e->f->cr /= 1.5;
		e->f->ci /= 1.5;
	}
	else if (button == MB_R || button == MB_DW)
	{
		e->f->cr *= 1.5;
		e->f->ci *= 1.5;
	}
	dcr = e->f->cr / 2;
	dci = e->f->ci / 2;
	CXMIN = e->f->mx - dcr;
	CXMAX = e->f->mx + dcr;
	CYMIN = e->f->my - dci;
	CYMAX = e->f->my + dci;
    e->zy =  ((CYMAX - CYMIN) / (WIN_Y - 1));
    e->zx = ((CXMAX - CXMIN) / (WIN_X - 1));
	draw_fractal(e);
	return button;
}

















