/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 22:15:09 by egurfink          #+#    #+#             */
/*   Updated: 2017/09/20 22:15:14 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		fill_arr_minus_one(t_t *s)
{
	int		multi;

	s->x_to_send = 0;
	s->y_to_send = 0;
	s->dis_for_current_x = 2048;
	s->dis_for_current_y = 2048;
	s->multi = (s->map_x * s->map_y) * 2;
	multi = s->multi;
	if (s->opponent == NULL)
		s->opponent = (int*)malloc(sizeof(int) * s->multi);
	if (s->to_place == NULL)
		s->to_place = (int*)malloc(sizeof(int) * s->multi);
	while (multi--)
	{
		s->opponent[multi] = -1;
		s->to_place[multi] = -1;
	}
	s->multi = 0;
}

void		add_tab(int x, int y, int *tab)
{
	int		i;

	i = 0;
	while (tab[i] != -1)
		i++;
	tab[i] = x;
	tab[i + 1] = y;
}
