/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:18:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/23 13:35:55 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int						rainbow_color(int i, t_env *e)
{
	register double		c;
	register int		red;
	register int		green;
	register int		blue;

	if (i == MAX_ITER)
		return (0);
	c = e->frequency * (i + 1);
	red = cos(c) * 127 + 128;
	green = cos(c + e->color) * 127 + 128;
	blue = cos(c + e->color + e->color) * 127 + 128;
	return ((red << 16) + (blue << 8) + green);
}
