/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:34:00 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/23 13:31:20 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				please_choose(void)
{
	ft_strcol(KMAG, "Type", " 1 ", "for Mandelbrot\n");
	ft_strcol(KMAG, "Type", " 2 ", "for Julia\n");
	ft_strcol(KMAG, "Type", " 3 ", "for Burning Ship\n");
	ft_colstr(KGRN, "\n\t\tUsage\n");
	ft_strcol(KMAG, NULL, "Mouse left", " to zoom in\t");
	ft_strcol(KMAG, NULL, "Mouse right", " to zoom out\n");
	ft_strcol(KMAG, NULL, "Escape", " to quit\n");
	ft_strcol(KMAG, NULL, "F", " to increase frequency\n");
	ft_strcol(KMAG, NULL, "+", " to  increase iteration\n");
	ft_strcol(KMAG, NULL, "-", " to decrease iteration\n");
	ft_strcol(KMAG, NULL, "C", " to change between fractal\n");
	ft_strcol(KMAG, NULL, "N", " to play with the colors\n");
	ft_strcol(KMAG, NULL, "B", " to altern between black and white\n");
	ft_strcol(KMAG, NULL, "Arrow keys", " to move a bit\n");
	return (-1);
}

int				main(int ac, char **av)
{
	t_env		*e;

	if (ac != 2)
		return (please_choose());
	e = init_env(av[1]);
	draw_fractal(e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK,
				motion_hook, e);
	mlx_loop(e->mlx);
	mlx_destroy_window(e->mlx, e->win);
	return (0);
}
