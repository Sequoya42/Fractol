/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:47:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/12 20:01:27 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     key_hook(int keycode, t_env *e)
{
    mlx_clear_window(e->mlx, e->win);
    ft_putnbrn(keycode);
	t_frac *f = e->f;
    if (keycode == 53)	// escape
        exit(0);
	if (keycode == 126)	 // up 
		f->my -= 0.1;
	if (keycode == 125)	// down
		f->my += 0.1;
	if (keycode == 123)	 // left
		f->mx -= 0.1;
	if (keycode == 124)	// right
		f->my += 0.1;
	if (keycode == 6)	//z || change zoom
		f->zoom++;
//	if (keycode == 8)	// c || change color
//		;			
	draw_julia(e);
    return (0);
}
