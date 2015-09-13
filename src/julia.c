/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:57:42 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/13 21:30:43 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



void put_pixel(t_frac *e, int x, int y, int color)
{
	const unsigned int bytes = e->bpp / 8;
	const unsigned int p = x * bytes + y * e->line_size;
	size_t i;

	i = 0;
	while (i < bytes)
	{
		e->d[p + i] = color;
		color >>= 8;
		i++;
	}
}

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
			put_pixel(f, x, y, rainbow_color(i, x, y));
//            mlx_pixel_put(e->mlx, e->win, x, y, rainbow_color(i, x, y));
            i = 0;
            y++;
        }
        x++;
    }
	mlx_put_image_to_window(e->mlx, e->win, f->img, 0, 0);
    return 0;
}
