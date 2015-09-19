/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:47:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/19 20:39:34 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	change_val(t_env *e, int x, int y, double zoom)
{
	double move_x;
	double move_y;

	if (e->f->zoom < 2000000000)
		e->f->zoom *= zoom;
	move_x = ((double)x - (WIN_X / 2.0)) / (WIN_X / 2);
	move_y = ((double)y - (WIN_Y / 2.0)) / (WIN_Y / 2);
	e->f->mx += move_x / e->f->zoom;
	e->f->my += move_y / e->f->zoom;
	return 1;
}

void	move_coor(t_env *e, t_frac *f, int keycode)
{
	if (keycode == MK_UP)	 // up 
	{
		e->m->ymax -= 0.1;
		e->m->ymin -= 0.1;
    e->zx = ((CXMAX - CXMIN) / (WIN_X - 1)) / f->zoom;
    e->zy =  ((CYMAX - CYMIN) / (WIN_Y - 1)) / e->f->zoom;
	}
	if (keycode == MK_DW)	// down
	{
		e->m->ymax += 0.1;
		e->m->ymin += 0.1;
    e->zx = ((CXMAX - CXMIN) / (WIN_X - 1)) / e->f->zoom;
    e->zy =  ((CYMAX - CYMIN) / (WIN_Y - 1)) / e->f->zoom;
	}
	if (keycode == MK_LT)	 // left
	{
		e->m->xmax -= 0.1;
		e->m->xmin -= 0.1;
    e->zx = ((CXMAX - CXMIN) / (WIN_X - 1)) / e->f->zoom;
    e->zy =  ((CYMAX - CYMIN) / (WIN_Y - 1)) / e->f->zoom;
	}
	if (keycode == MK_RT)	// right
	{
		e->m->xmax += 0.1;
		e->m->xmin += 0.1;
    e->zx = ((CXMAX - CXMIN) / (WIN_X - 1)) / e->f->zoom;
    e->zy =  ((CYMAX - CYMIN) / (WIN_Y - 1)) / e->f->zoom;
	}
}
int     key_hook(int keycode, t_env *e)
{
    mlx_clear_window(e->mlx, e->win);
	t_frac *f = e->f;
    if (keycode == MK_ESC)
        exit(0);
    move_coor(e, f, keycode);
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
	int fx = x;
	int fy = y;
	if (button == 1)
	change_val(e, fx, fy, 1.05);
	else if (button == 5)
		change_val(e, fx, fy, 1.05);
	else if (button == 4)
		change_val(e, fx, fy, 0.9);
	draw_fractal(e);
	return button;
}











































