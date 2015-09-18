/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:34:00 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/18 14:45:09 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int 	please_choose()
{
	ft_putstr("Type 1 for mandelbrot\n");
	ft_putstr("Type 2 for julia\n");
	return (-1);
}

int main(int ac, char **av)
{
	t_env *e;

	if (ac != 2)
		return (please_choose());
	e = init_env(av[1]);
	mlx_expose_hook(e->win, draw_fractal , e);
	mlx_loop(e->mlx);
	return (0);
}
