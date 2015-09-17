/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:26:29 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/17 19:16:49 by rbaum            ###   ########.fr       */
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

int 	choose_fractal(t_env *e, int x, int y)
{
	if (e->f->n == 1)
		return (draw_mandel(e, x, y));
	else if (e->f->n == 2)
		return (draw_julia(e, x, y));
	return 0;
}

int draw_fractal(t_env *e)
{
    double 	x;
    double 	y;
    int 	c;
  	double 	iter;
	int 	ch; // choice of fractal

	x = 0.0;
	y = 0.0;
	iter = MAX_ITER;
	mlx_key_hook(e->win, key_hook, e);
    while (y < WIN_Y)
    {
        x = 0;
        while (x < WIN_Y)
        {
       		ch = choose_fractal(e, y, x);
       	  	c = rainbow_color(ch, iter);
			put_pixel(e->f, y, x, c);
            x++;
        }
        y++;
    }
	mlx_put_image_to_window(e->mlx, e->win, e->f->img, 0, 0);
    return 0;
}