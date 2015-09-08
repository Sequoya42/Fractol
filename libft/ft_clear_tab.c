/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 19:50:14 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/15 19:51:39 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_clear_tab(char **tab)
{
	int		i;
	int		k;

	i = 0;
	if (tab == NULL)
		tab = NULL;
	else
	{
		while (tab[i])
		{
			k = ft_strlen(tab[i]);
			while (tab[i][k])
			{
				tab[i][k] = '\0';
				k--;
			}
			i++;
		}
		tab = NULL;
	}
}
