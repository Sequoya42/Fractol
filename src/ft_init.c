/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:49:26 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/17 19:15:31 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_mod   *init_mod()
{
    t_mod       *m;

    m = malloc(sizeof(t_mod) * 1);
    m->xmax = 2.0;
    m->xmin = -1.5;
    m->ymin = -1.5;
    m->ymax = 2.0;
//    m->rfactor = m->xmax - m->xmin) / (WIN_X)
    return (m);
}

static t_frac  *init_frac(char *av)
{
    t_frac *f;
    f = malloc(sizeof(t_frac) * 1);
    f->cr = 0.7;
    f->ci = 0.27015;
    f->zoom = 1.1;
    f->mx = 0.0;
    f->my = 0.0;
    f->n = ft_atoi(av);
    return f;
}

t_env   *init_env(char *av)
{
    t_env *e;

    e = malloc(sizeof(t_env) * 1);
    e->mlx = mlx_init();
    e->m = init_mod();
    e->f = init_frac(av);
	e->f->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
    e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Fractol");
	e->f->d = mlx_get_data_addr(e->f->img, &e->f->bpp, &e->f->line_size, &e->f->endian);
    e->t = (double)time(NULL);
    e->iter = 32;
    return e;
}
