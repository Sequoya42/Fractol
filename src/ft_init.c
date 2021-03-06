/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:49:26 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/23 13:30:14 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_reset(t_env *e)
{
	t_frac			*f;

	f = e->f;
	CXMAX = 2.0;
	CXMIN = -2.0;
	CYMIN = -2.0;
	CYMAX = 1.5;
	f->cr = -0.8;
	f->ci = 0.156;
	f->mx = 0.0;
	f->my = 0.0;
	f->nrl = 0.0;
	f->ni = 0.0;
	e->frequency = 0.1;
	e->iter = 16;
	e->color = 2;
	e->zx = ((CXMAX - CXMIN) / (WIN_X - 1));
	e->zy = ((CYMAX - CYMIN) / (WIN_Y - 1));
}

static t_mod		*init_mod(void)
{
	t_mod			*m;

	m = malloc(sizeof(t_mod) * 1);
	m->xmax = 2.0;
	m->xmin = -2.0;
	m->ymin = -2.0;
	m->ymax = 1.5;
	return (m);
}

t_frac				*init_frac(char *av)
{
	t_frac			*f;

	f = malloc(sizeof(t_frac) * 1);
	f->cr = -0.8;
	f->ci = 0.156;
	f->mx = 0.0;
	f->my = 0.0;
	f->n = ft_atoi(av);
	f->nrl = 0.0;
	f->ni = 0.0;
	if (f->n != 1 && f->n != 2 && f->n != 3)
	{
		please_choose();
		exit(0);
	}
	return (f);
}

t_env				*init_env(char *av)
{
	t_env			*e;

	e = malloc(sizeof(t_env) * 1);
	e->m = init_mod();
	e->f = init_frac(av);
	e->mlx = mlx_init();
	e->f->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Fractol");
	e->f->d = mlx_get_data_addr(e->f->img, &e->f->bpp, &e->f->line_size,
&e->f->endian);
	e->t = (double)time(NULL);
	e->frequency = 0.1;
	e->iter = 16;
	e->color = 2;
	e->zx = ((CXMAX - CXMIN) / (WIN_X - 1));
	e->zy = ((CYMAX - CYMIN) / (WIN_Y - 1));
	return (e);
}
