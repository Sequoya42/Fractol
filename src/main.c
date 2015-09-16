/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:34:00 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/15 21:03:33 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_env *e;
	t_frac *f;

	if (ac != 2)
		return (ft_error(NULL, NULL,"Please enter blablabla\n"));
	(void)av;
	f = init_frac();
	e = init_env(f);
	mlx_expose_hook(e->win, draw_fractal , e);
	mlx_loop(e->mlx);
	return (0);
}
