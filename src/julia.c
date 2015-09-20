/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:57:42 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/20 20:55:10 by rbaum            ###   ########.fr       */
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
