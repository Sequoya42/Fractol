/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:47:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/22 18:55:02 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_coor(t_env *e, int keycode)
{
	const	double k = e->zx * 10;

	if (keycode == MK_DW)
	{
		CYMAX -= k;
		CYMIN -= k;
	    e->zy =  ((CYMAX - CYMIN) / (WIN_Y - 1));
	}
	if (keycode == MK_UP)
	{
		CYMAX += k;
		CYMIN += k;
	    e->zy =  ((CYMAX - CYMIN) / (WIN_Y - 1));
	}
	if (keycode == MK_LT)
	{
		CXMAX -= k;
		CXMIN -= k;
    	e->zx = ((CXMAX - CXMIN) / (WIN_X - 1));
	}
	if (keycode == MK_RT)
	{
		CXMAX += k;
		CXMIN += k;
	    e->zx = ((CXMAX - CXMIN) / (WIN_X - 1));
	}
}

void	ft_frequ(int keycode, t_env *e)
{
	if (keycode == MK_F)
		e->frequency *= 2;
	else if (keycode == MK_D && e->frequency > 0.02)
		e->frequency /= 2;
	printf("frequ: %f\n", e->frequency);
}

void	ft_change_frac(t_env *e)
{
	ft_reset(e);
	if (e->f->n == 1)
		e->f->n = 2;
	else if (e->f->n == 2)
		e->f->n = 3;
	else if (e->f->n == 3)
		e->f->n = 1;
}

int     key_hook(int keycode, t_env *e)
{
    mlx_clear_window(e->mlx, e->win);
    if (keycode == MK_ESC)
        exit(0);
	else if (keycode == MK_PL)
		MAX_ITER = (MAX_ITER < 8000) ? MAX_ITER * 2 : MAX_ITER;
	else if (keycode == MK_MI)
		MAX_ITER = (MAX_ITER > 2) ? MAX_ITER / 2 : MAX_ITER;
	else if (keycode == MK_N)
		e->color++;
	else if (keycode == MK_B)
		e->color = e->color == 0 ? 2: 0;
	else if (keycode == MK_R)
		ft_reset(e);
	else if (keycode == MK_C)
		ft_change_frac(e);
	move_coor(e, keycode);
	ft_frequ(keycode, e);
	draw_fractal(e);
    return (0);
}







