/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:57:42 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/22 18:22:21 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		draw_mandel(t_env *e, int x, int y)
{
	register int i;
	register double zr;
	register double zi;
	t_frac *f;

	i = -1;
	f = e->f;
	f->pi = CYMAX - (long double)y * e->zy;
	f->pr = CXMIN + (long double)x * e->zx;
    f->orl = f->nrl = f->oi = f->ni = 0;
    zr = SQUARE(f->nrl);
    zi = SQUARE(f->ni);
	while (++i < MAX_ITER && (zr + zi < 4))
	{
		f->ni *= f->nrl;
		f->ni += f->ni + f->pi;
		f->nrl = (zr - zi) + f->pr;
	    zr = SQUARE(f->nrl);
	    zi = SQUARE(f->ni);
	}
	return (i);
}

int		draw_julia(t_env *e, int x, int y)
{
	t_frac *f;
	register int i;
	register long double zr;
	register long double zi;

	i = -1;
	f = e->f;
	f->ni = CYMAX - (long double)y * e->zy;
	f->nrl = CXMIN + (long double)x * e->zx;
	zr = SQUARE(f->nrl);
	zi = SQUARE(f->ni);
	while (++i < MAX_ITER && (zr + zi) < 4)
	{
		f->ni *= f->nrl;
		f->ni += f->ni + f->ci;
		f->nrl = zr - zi + f->cr;
		zr = SQUARE(f->nrl);
		zi = SQUARE(f->ni);
	}
		return (i);
}

int				draw_ship(t_env *e, int x, int y)
 {
 		t_frac *f;
	register int i;
	register long double zr;
	register long double zi;

	i = -1;
	f = e->f;
	f->pr = CXMIN + (long double)x * e->zx;
	f->pi = CYMAX - (long double)y * e->zy;
	f->nrl = f->pr;
	f->ni = f->pi;
	zr = SQUARE(f->nrl);
	zi = SQUARE(f->ni);
	while (++i < MAX_ITER && (zr + zi) < 4)
	{
		f->ni = 2 * fabs(f->nrl * f->ni);
		f->ni -= f->pi;
		f->nrl = zr - zi + f->pr;
		zr = SQUARE(f->nrl);
		zi = SQUARE(f->ni);
	}
		return (i);
 }