/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:34:00 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/12 19:46:22 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_draw(t_env *e)
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

int     key_hook(int keycode, t_env *e)
{
    mlx_clear_window(e->mlx, e->win);
	ft_putnbrn(keycode);
    if (keycode == 53)
        exit(0);
	ft_draw(e);
    return (0);
}

t_frac	*init_frac(void)
{
	t_frac *f;
	f = malloc(sizeof(t_frac) * 1);
	f->cr = -0.7;
	f->ci = 0.27015;
	f->iter = 256;
	f->zoom = 1;
	f->mx = 0;
	f->my = 0;
	return f;
}

t_env	*init_env(t_frac *frac)
{
	t_env *e;
	e = malloc(sizeof(t_env) * 1);
	e->mlx = mlx_init();
	e->f = frac;
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Fractol");
	return e;
}

int main(void)
{
	t_env *e;
	t_frac *f;

	f = init_frac();
	e = init_env(f);
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, ft_draw , e);
	mlx_loop(e->mlx);
	return (0);
}
