/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:26:29 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/08 19:26:30 by rbaum            ###   ########.fr       */
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

int 	choose_fractal(t_frac *f, int x, int y)
{
	if (f->n == 1)
		return (draw_mandel(f, x, y));
	else if (f->n == 2)
		return (draw_julia(f, x, y));
	return 0;
}

int draw_fractal(t_env *e)
{
    t_frac *f;  
    double 	x;
    double 	y;
    int 	c;
	int 	ch; // choice of fractal

	f = e->f;
	x = 0.0;
	y = 0.0;
	mlx_key_hook(e->win, key_hook, e);
    while (x < WIN_X)
    {
        y = 0;
        while (y < WIN_Y)
        {
       		ch = choose_fractal(f, x, y);
       	  	c = rainbow_color(ch);
			put_pixel(f, x, y, c);
            y++;
        }
        x++;
    }
	mlx_put_image_to_window(e->mlx, e->win, f->img, 0, 0);
    return 0;
}