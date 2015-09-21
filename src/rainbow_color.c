/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:18:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/21 17:22:22 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int rainbow_color(int i, t_env *e)
{
    if (i == MAX_ITER)
        return (0);
    double c = e->frequency * (i + 1);
    int red = cos(c) * 127 + 128;
    int green = cos(c + e->color) * 127 + 128;
    int blue = cos(c + e->color + e->color) * 127 + 128;
    return ((red << 16) + (blue << 8) + green);
}
