/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:34:29 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/09 16:34:45 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../libft/libft.h"
#include <mlx.h>
#include <math.h>

# define WIN_X 800
# define WIN_Y 800
# define MAX_ITER 256

# define CXMIN -2.5
# define CXMAX -1.5
# define CYMIN -2.0
# define CYMAX 2.0

# define PIXW (CXMAX - CXMIN) / WIN_X
# define PIXH (CYMAX - CYMIN) / WIN_Y

typedef struct  s_env
{
    void        *mlx;
    void        *win;
}               t_env;

#endif
