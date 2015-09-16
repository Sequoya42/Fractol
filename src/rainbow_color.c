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

int lerp(float v0, float v1, float t) 
{
    return ((1 - t) * v0 + (t * v1));
}

float normalize(double x, double y, int i)
{
    double zn;
	double nu;

	zn = sqrt(x * x + y * y);
    nu = log(log(zn) / log(2)) / log(2);
    return (i + 1 - nu);
}

int rainbow_color(int i, double x, double y)
{
    float frequency = .8;
	
    if (i == MAX_ITER)
        return (0);
    int k = floor(normalize(x, y, i));
    int red = sin(frequency * k) * 127 + 128;
    int green = sin(frequency * k + 2) * 127 + 128;
    int blue = sin(frequency * k + 4) * 127 + 128;
    int red_2 = sin(frequency * (k + 1)) * 127 + 128;
    int green_2 = sin(frequency * (k + 1) + 2) * 127 + 128;
    int blue_2 = sin(frequency * (k + 1) + 4) * 127 + 128;
    return ((lerp(red, red_2, i % 2) << 16) +
            (lerp(blue, blue_2, i % 1) << 8) + lerp(green, green_2, i % 1));
}
