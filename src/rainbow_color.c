/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:18:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/20 20:30:40 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int rainbow_color(int i, t_env *e)
{
    if (i == MAX_ITER)
        return (0);
     double c = e->frequency * (i + 1);
    int red = sin(c) * 127 + 128;
    int green = sin(c + 2) * 127 + 128;
    int blue = sin(c + 4) * 127 + 128;
    return ((red << 16) + (blue << 8) + green);
}
