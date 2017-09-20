/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_map_fig.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 22:15:56 by egurfink          #+#    #+#             */
/*   Updated: 2017/09/20 22:15:58 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_write_map_fig(t_t *s)
{
	int		i;
	int		j;
	int		k;

	get_next_line(FD, &(s->line));
	i = 0;
	while (i < s->map_x)
	{
		j = 0;
		k = 0;
		get_next_line(FD, &(s->line));
		while (ft_isdigit(s->line[k]) || s->line[k] == ' ')
			k++;
		while (j < s->map_y)
		{
			s->map[i][j] = s->line[k];
			j++;
			k++;
		}
		ft_strclr(s->line);
		i++;
	}
	fill_piece(s);
}
