/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:57:42 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/12 19:59:31 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int draw_julia(t_env *e)
{
    t_frac *f;
    f = e->f;
    int x = 0;
    int y = 0;
    int i = 0;
    while (x < WIN_X)
    {
        y = 0;
        while (y < WIN_Y)
        {
            f->nr = 1.5 * (x - (WIN_X / 2)) / (0.5 * f->zoom * WIN_X) + f->mx;
            f->ni = (y - (WIN_Y / 2)) / (0.5 * f->zoom * WIN_Y) + f->my;
            while (i < MAX_ITER)
            {
                f->or = f->nr;
                f->oi = f->ni;
                f->nr = (f->or * f->or) - (f->oi * f->oi) + f->cr;
                f->ni = (2 * f->or * f->oi) + f->ci;
                if ((f->nr * f->nr) + (f->ni * f->ni) > 4)
                    break;
                i++;
            }
            mlx_pixel_put(e->mlx, e->win, x, y, rainbow_color(i, x, y));
            i = 0;
            y++;
        }
        x++;
    }
    return 0;
}
