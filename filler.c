/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:23:42 by egurfink          #+#    #+#             */
/*   Updated: 2017/09/20 19:20:15 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#define FD 0

void		first_init(t_t *s)
{
	s->player = 'X';
	s->enemy = 'O';
	s->touch = 0;
	s->map = NULL;
	s->map_x = 0;
	s->map_y = 0;
	s->piece = NULL;
	s->piece_cord_x = 0;
	s->piece_cord_y = 0;
	s->multi = 0;
	s->line = NULL;
	s->to_place = NULL;
	s->opponent = NULL;
	s->x_to_send = 0;
	s->y_to_send = 0;
	s->y_dis = 0;
	s->x_dis = 0;
	s->dis_for_current_x = 2048;
	s->dis_for_current_y = 2048;
	s->sum_dis = s->dis_for_current_x + s->dis_for_current_y;
}

int			place_figure(int x, int y, t_t *s)
{
	int		count_x;
	int		count_y;

	count_x = 0;
	s->touch = 0;
	while (count_x < s->piece_cord_x &&
			(s->piece_cord_x + x - 1) < s->map_x)
	{
		count_y = 0;
		while (count_y < s->piece_cord_y &&
				(s->piece_cord_y + y - 1) < s->map_y)
		{
			if (s->piece[count_x][count_y] == '*' &&
					(s->map[count_x + x][count_y + y] == s->player))
				s->touch++;
			if (s->map[count_x + x][count_y + y] == s->enemy)
				return (0);
			count_y++;
		}
		count_x++;
	}
	return (s->touch != 1 ? 0 : 1);
}

void		closest(t_t *s)
{
	int		i_opp;
	int		i_my;

	i_opp = 0;
	while (s->opponent[i_opp] != -1)
	{
		i_my = 0;
		while (s->to_place[i_my] != -1)
		{
			s->x_dis = (s->to_place[i_my] - s->opponent[i_opp]);
			s->x_dis < 0 ? s->x_dis *= -1 : 0;
			s->y_dis = (s->to_place[i_my + 1] - s->opponent[i_opp + 1]);
			s->y_dis < 0 ? s->y_dis *= -1 : 0;
			if (s->x_dis + s->y_dis < s->sum_dis)
			{
				s->dis_for_current_x = s->x_dis;
				s->dis_for_current_y = s->y_dis;
				s->x_to_send = s->to_place[i_my];
				s->y_to_send = s->to_place[i_my + 1];
			}
			i_my += 2;
		}
		i_opp += 2;
	}
	ft_printf("%d %d\n", s->x_to_send, s->y_to_send);
}

void		coordinates(t_t *s)
{
	int		x;
	int		y;

	x = 0;
	while (x < s->map_x)
	{
		y = 0;
		while (y < s->map_y)
		{
			if (place_figure(x, y, s))
				add_tab(x, y, s->to_place);
			if (s->map[x][y] == s->enemy ||
					s->map[x][y] == ft_tolower(s->enemy))
				add_tab(x, y, s->opponent);
			y++;
		}
		x++;
	}
	closest(s);
}

int			main(void)
{
	t_t		*s;

	s = (t_t*)malloc(sizeof(t_t));
	first_init(s);
	fill_player(s);
	fill_map(s);
	fill_piece(s);
	fill_arr_minus_one(s);
	coordinates(s);
	while (1)
	{
		get_next_line(FD, &s->line);
		ft_write_map_fig(s);
		fill_arr_minus_one(s);
		coordinates(s);
	}
}
