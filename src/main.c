/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:34:00 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/12 17:33:59 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <math.h>

int lerp(float v0, float v1, float t) {
	return (1 - t ) * v0 + t * v1;
}

float normalize(double x, double y, int i)
{
	double zn = sqrt(x * x + y * y);
	double nu = log(log(zn) / log(2)) / log(2);
	return (i + 1 - nu);
}

int rainbow_color(int i, double x, double y)
{
	float frequency = .8;

	if (i == MAX_ITER)
		return (0);
	int k = floor(normalize(x, y, i));
	int red = sin(frequency * k) * 127 + 128;
	int green = sin(frequency * k + 2) * 127 + 128;
	int blue = sin(frequency * k + 4) * 127 + 128;
	int red_2 = sin(frequency * (k + 1)) * 127 + 128;
	int green_2 = sin(frequency * (k + 1) + 2) * 127 + 128;
	int blue_2 = sin(frequency * (k + 1) + 4) * 127 + 128;
	return ((lerp(red, red_2, i % 1) << 16) +
			(lerp(blue, blue_2, i % 1) << 8) + lerp(green, green_2, i % 1));
}

int	ft_draw(t_env *e)
{
	int x = 0;
	int y = 0;
	while (x < 112)
	{
		y = 0;
		while (y < 220)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, rainbow_color(x, x, y));
			y++;
		}
		x++;
	}
	return 0;
}


int     key_hook(int keycode, t_env *e)
{
    mlx_clear_window(e->mlx, e->win);
	ft_putnbrn(keycode);
    if (keycode == 53)
        exit(0);
	ft_draw(e);
    return (0);
}

int main(void)
{
	t_env *e;

	e = malloc(sizeof(t_env) * 1);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Fractol");
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, ft_draw , e);
	mlx_loop(e->mlx);
	return (0);
}
