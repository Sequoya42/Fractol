/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 19:18:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/12 19:22:58 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int rainbow_color(int i)
{
    float frequency = .8;
	
    if (i == MAX_ITER)
        return (0);
    int k = i;
    // int red = sin(frequency * k) * 127 + 128;
    // int green = sin(frequency * k + 2) * 127 + 128;
    // int blue = sin(frequency * k + 4) * 127 + 128;
    int red = sin(frequency * (k + 1)) * 127 + 128;
    int green = sin(frequency * (k + 1) + 2) * 127 + 128;
    int blue = sin(frequency * (k + 1) + 4) * 127 + 128;
    return ((red << 16) + (blue << 8) + green);
}
