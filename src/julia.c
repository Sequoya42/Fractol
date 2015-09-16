/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:57:42 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/16 21:12:03 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		draw_julia(t_frac *f, int x, int y)
{
	int i;

	i = 0;
	f->nr = (CXMIN + x * PIXW + f->mx) * f->zoom;
	f->ni = (CYMIN + y * PIXH + f->my) * f->zoom;
	while (i < MAX_ITER)
	{
		f->orl = f->nr;
		f->oi = f->ni;
		f->nr = (SQUARE(f->orl)) - (SQUARE(f->oi)) + f->cr;
		f->ni = (2 * f->orl * f->oi) + f->ci;
		if ((SQUARE(f->nr)) + (SQUARE(f->ni)) > 4) // 4 means break if the point is 
			break;									//  outside the circle with radius 2
		i++;
	}
	return (i);
}

int		draw_mandel(t_frac *f, int x, int y)
{
	int i;

	i = 0;
//	   f->cr = 1.5 * (x - (WIN_X / 2)) / (0.5 * f->zoom * WIN_X) + f->mx;
//    f->ci = (y - (WIN_Y / 2)) / (0.5 * f->zoom * WIN_Y) + f->my;
	f->cr = (CXMIN + x * PIXW) / f->zoom + f->mx;
	f->ci = (CYMIN + y * PIXH) / f->zoom + f->my;
    f->orl = f->nr = f->oi = f->ni = 0;
	while (i < MAX_ITER)
	{
		f->orl = f->nr;
		f->oi = f->ni;
		f->nr = (SQUARE(f->orl)) - (SQUARE(f->oi)) + f->cr;
		f->ni = (2 * f->orl * f->oi) + f->ci;
		if ((SQUARE(f->nr)) + (SQUARE(f->ni)) > 4) // 4 means break if the point is 
			break;									//  outside the circle with radius 2
		i++;
	}
	return (i);
}
