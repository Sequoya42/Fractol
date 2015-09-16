/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:49:26 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/13 21:14:53 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_frac  *init_frac(void)
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

t_env   *init_env(t_frac *frac)
{
    t_env *e;

    e = malloc(sizeof(t_env) * 1);
    e->mlx = mlx_init();
    e->f = frac;
	e->f->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
    e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Fractol");
	e->f->d = mlx_get_data_addr(e->f->img, &e->f->bpp, &e->f->line_size, &e->f->endian);
    e->t = (double)time(NULL);
    return e;
}
