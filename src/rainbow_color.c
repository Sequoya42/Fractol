/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:18:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/18 14:18:46 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int rainbow_color(int i, t_env *e)
{
	
    if (i == MAX_ITER)
        return (0);
    int k = i;
    // int red = sin(frequency * k) * 127 + 128;
    // int green = sin(frequency * k + 2) * 127 + 128;
    // int blue = sin(frequency * k + 4) * 127 + 128;
    int red = sin(e->frequency * (k + 1)) * 127 + 128;
    int green = sin(e->frequency * (k + 1) + 2) * 127 + 128;
    int blue = sin(e->frequency * (k + 1) + 4) * 127 + 128;
    return ((red << 16) + (blue << 8) + green);
}
