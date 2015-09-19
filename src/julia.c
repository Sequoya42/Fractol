/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:57:42 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/19 21:15:26 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		draw_julia(t_env *e, int x, int y)
{
	int i;
	t_frac *f;

	i = 0;
	f = e->f;

	f->ni = CYMAX - (long double)y * e->zy;
	f->nrl = CXMIN + (long double)x  * e->zx;
// f->nrl = (CXMIN + x * PIXW + f->mx) / f->zoom;
// f->ni = (CYMIN + y * PIXH + f->my) / f->zoom;
	while (i < MAX_ITER)
	{
		f->orl = f->nrl;
		f->oi = f->ni;
		f->nrl = (SQUARE(f->orl)) - (SQUARE(f->oi)) + f->cr;
		f->ni = (2 * f->orl * f->oi) + f->ci;
		if ((SQUARE(f->nrl)) + (SQUARE(f->ni)) > 4) // 4 means break if the point is 
			break;									//  outside the circle with radius 2
		i++;
	}
		return (i);
}

int		draw_mandel(t_env *e, int x, int y)
{
	int i;
	t_frac *f;

	i = 0;
	f = e->f;
	f->pi = CYMAX - (long double)y * e->zy;
	f->pr = CXMIN + (long double)x * e->zx;
//	f->pr = (CXMIN + x * PIXW)+ f->mx;
//	f->pi = (CYMIN + y * PIXH)+ f->my;
    f->orl = f->nrl = f->oi = f->ni = 0;
	while (i < MAX_ITER)
	{
		f->orl = f->nrl;
		f->oi = f->ni;
		f->nrl = (SQUARE(f->orl)) - (SQUARE(f->oi)) + f->pr;
		f->ni = (2 * f->oi * f->orl) + f->pi;
		if ((SQUARE(f->nrl)) + (SQUARE(f->ni)) > 4) // 4 means break if the point is 
			break;
		i++;
	}
	return (i);
}

// int		zoom(int x, int y, double zoom, t_mlx *mlx)
// {
// 	double move_x;
// 	double move_y;

// 	mlx->calc->zoom *= zoom;
// 	move_x = ((double)x - (WIDTH / 2.0)) / (WIDTH / 2);
// 	move_y = ((double)y - (HEIGHT / 2.0)) / (HEIGHT / 2);
// 	mlx->calc->move_x += move_x / mlx->calc->zoom / 10;
// 	mlx->calc->move_y += move_y / mlx->calc->zoom / 10;
// 	return (1);
// }

// int		mouse_button_hook(int button, int x, int y, t_mlx *mlx)
// {
// 	mlx->redraw = 1;
// 	if (button == MOUSE_WHEEL_UP)
// 		return (zoom(x, y, ZOOM_STEP, mlx));
// 	else if (button == MOUSE_WHEEL_DOWN)
// 		return (zoom(x, y, 0.9, mlx));
// 	mlx->redraw = 0;
// 	return (0);
// }














