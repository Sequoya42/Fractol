/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:34:00 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/13 21:29:48 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	t_env *e;
	t_frac *f;


	f = init_frac();
	e = init_env(f);
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, draw_julia , e);
	mlx_loop(e->mlx);
	return (0);
}
