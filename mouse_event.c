/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 18:50:49 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/22 18:54:09 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void set_value(t_env *e, double dcr, double dci)
{
    dcr = e->f->cr / 2;
    dci = e->f->ci / 2;
    CXMIN = e->f->mx - dcr;
    CXMAX = e->f->mx + dcr;
    CYMIN = e->f->my - dci;
    CYMAX = e->f->my + dci;
    e->zy =  ((CYMAX - CYMIN) / (WIN_Y - 1));
    e->zx = ((CXMAX - CXMIN) / (WIN_X - 1));
}

int     mouse_hook(int button, int x, int y, t_env *e)
{
    double dcr;
    double dci;

    dcr = x;
    dci = y;
    e->f->cr = CXMAX - CXMIN;
    e->f->ci = CYMAX - CYMIN;
    e->f->mx = ((double)x / WIN_X * e->f->cr) - e->f->cr / 2 + e->f->mx;
    e->f->my = (double)(WIN_Y - y) / WIN_Y * e->f->ci - e->f->ci / 2 + e->f->my;
    if ((button == MB_L || button == MB_UP) && x <= WIN_X && y <= WIN_Y)
    {
        e->f->cr /= 1.5;
        e->f->ci /= 1.5;
    }
    else if ((button == MB_R || button == MB_DW) && x <= WIN_X && y <= WIN_Y)
    {
        e->f->cr *= 1.5;
        e->f->ci *= 1.5;
    }
    set_value(e, dcr, dci);
    return (draw_fractal(e));
}

int     motion_hook(int x, int y, t_env *e)
{
    if (x >= 0 && y >= 0 && x <= WIN_X && y <= WIN_Y && e->f->n == 2)
    {
        e->f->ci = CYMAX - (double)y * e->zy;
		e->f->cr = CXMIN + (double)x * e->zx;
    }
    else
        return 0;
    return (draw_fractal(e));
}


