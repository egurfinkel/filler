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

void		fill_player(t_t *s)
{
	get_next_line(FD, &s->line);
	if (s->line[10] == '1')
	{
		s->player = 'O';
		s->enemy = 'X';
	}
}

void		fill_map(t_t *s)
{
	int		i;
	int		l;
	int		p;

	i = 0;
	get_next_line(FD, &s->line);
	while (!ft_isdigit(s->line[i]))
		i++;
	s->map_x = 0;
	while (ft_isdigit(s->line[i]))
	{
		s->map_x += s->line[i] - '0';
		s->map_x *= 10;
		i++;
	}
	s->map_x /= 10;
	i++;
	s->map_y = 0;
	while (ft_isdigit(s->line[i]))
	{
		s->map_y += s->line[i] - '0';
		s->map_y *= 10;
		i++;
	}
	s->map_y /= 10;
	s->map = (char **)malloc(sizeof(char *) * (s->map_x + 1));
	s->map[s->map_x] = NULL;
	i = 0;
	while (i < s->map_x)
	{
		s->map[i] = ft_strnew((size_t)(s->map_y + 1));
		i++;
	}
	get_next_line(FD, &s->line);
	i = 0;
	while (i < s->map_x)
	{
		get_next_line(FD, &(s->line));
		l = 0;
		p = 4;
		while (s->line[p])
		{
			s->map[i][l] = s->line[p];
			l++;
			p++;
		}
		i++;
	}
}

void		fill_piece(t_t *s)
{
	int		i;
	int		l;

	s->piece_cord_x = 0;
	s->piece_cord_y = 0;
	i = 0;
	get_next_line(FD, &s->line);
	while (s->line[i] && !ft_isdigit(s->line[i]))
		i++;
	while (s->line[i] && ft_isdigit(s->line[i]))
	{
		s->piece_cord_x += s->line[i] - '0';
		s->piece_cord_x *= 10;
		i++;
	}
	s->piece_cord_x /= 10;
	i++;
	while (s->line[i] && ft_isdigit(s->line[i]))
	{
		s->piece_cord_y += s->line[i] - '0';
		s->piece_cord_y *= 10;
		i++;
	}
	s->piece_cord_y /= 10;
	i = 0;
	s->piece = (char **)malloc(sizeof(char *) * (s->piece_cord_x + 1));
	s->piece[s->piece_cord_x] = NULL;
	while (i < s->piece_cord_x)
	{
		l = 0;
		s->piece[i] = ft_strnew((size_t)(s->piece_cord_y + 1));
		get_next_line(FD, &s->line);
		while (s->line[l])
		{
			s->piece[i][l] = s->line[l];
			l++;
		}
		i++;
	}
}

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

void		add_tab(int x, int y, int *tab)
{
	int		i;

	i = 0;
	while (tab[i] != -1)
		i++;
	tab[i] = x;
	tab[i + 1] = y;
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
