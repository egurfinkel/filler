/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:23:42 by egurfink          #+#    #+#             */
/*   Updated: 2017/05/09 17:26:54 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "includes/libft.h"
#include "includes/get_next_line.h"
#include "includes/ft_printf.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#define FD 0

typedef struct		s_s
{
	char			player;
	char			enemy;
	int				brk;
	char			**map;
	int				map_x;
	int				map_y;
	char 			**piece;
	int 			piece_x;
	int 			piece_y;
}					t_t;

void				_struct_init(t_t **s)
{
	(*s) = (t_t*)malloc(sizeof(t_t));
	(*s)->player = 'X';
	(*s)->enemy = 'O';
	(*s)->brk = 0;
	(*s)->map = NULL;
	(*s)->map_x = 0;
	(*s)->map_y = 0;
	(*s)->piece = NULL;
	(*s)->piece_x = 0;
	(*s)->piece_y = 0;
}

int			main()
{
	char	*line;
	t_t		*s;
	int		i = 0;
	int 	x = 0;
	int 	y = 0;

	_struct_init(&s);
	line = (char*)malloc(sizeof(char) * 10000);
	get_next_line(FD, &line);
	if (line[10] == '1')
	{
		s->player = 'O';
		s->enemy = 'X';
	}
	get_next_line(FD, &line);
	if (ft_strstr(line, "Plateau"))
	{
		i = 8;
		s->map_y = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
		s->map_x = ft_atoi(&line[++i]);
		free(line);
	}
	s->map = (char **) malloc(sizeof(char *) * s->map_y);
	while (y <= s->map_y)
	{
		s->map[y] = (char *) malloc(sizeof(char) * s->map_x);
		s->map[y++][s->map_x] = '\0';
	}
	s->map[y] = NULL;
	get_next_line(FD, &line);
	y = 0;
	while (y < s->map_y)
	{
		x = 0;
		i = 4;
		get_next_line(FD, &line);
		while (x < s->map_x)
			s->map[y][x++] = line[i++];
		y++;
	}
	while (!ft_strstr(line, "Piece"))
		get_next_line(FD, &line);
	if (ft_strstr(line, "Piece"))
	{
		i = 6;
		s->piece_y = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
		s->piece_x = ft_atoi(&line[++i]);
		free(line);
	}
	int xx = 0;
	int yy = 0;
	printf("%c %c\n", s->player, s->enemy);
	printf("%d %d\n", s->map_y, s->map_x);
	printf("%d %d\n", s->piece_y, s->piece_x);
	close(FD);
}


/*

$$$ exec p2 : [./a.out]
Plateau 15 17:
01234567890123456
000 .................
001 .................
002 .................
003 .................
004 .................
005 .................
006 .................
007 .................
008 ..O..............
009 ..OOOO.......X...
010 ....Oo......XXX..
011 .....o.......XX..
012 ..............X..
013 .................
014 .................
Piece 2 2:
**
.*
<got (X): [8, 12]
 ===
 $$$ exec p1 : [./a.out]
 Plateau 15 17:
    01234567890123456
000 .................
001 .................
002 .................
003 .................
004 .................
005 .................
006 .................
007 .................
008 ..OO.............
009 .................
010 .................
011 .................
012 .............xx..
013 .................
014 .................
Piece 1 3:
.**
 $$$ exec p2 : [./a.out]
 Plateau 100 99:
    012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678
000 ...................................................................................................
001 ...................................................................................................
002 ...................................................................................................
003 ...................................................................................................
004 ...................................................................................................
005 ...................................................................................................
006 ...................................................................................................
007 ...................................................................................................
008 ...................................................................................................
009 ...................................................................................................
010 ...................................................................................................
011 ...................................................................................................
012 ...................................................................................................
013 ...................................................................................................
014 ...................................................................................................
015 ...................................................................................................
016 ...................................................................................................
017 ...................................................................................................
018 ...................................................................................................
019 ...................................................................................................
020 ...................................................................................................
021 ...................................................................................................
022 ...................................................................................................
023 ...................................................................................................
024 ...................................................................................................
025 ...................................................................................................
026 ...................................................................................................
027 ...................................................................................................
028 ...................................................................................................
029 ..............................X....................................................................
030 ...................................................................................................
031 ...................................................................................................
032 ...................................................................................................
033 ...................................................................................................
034 ...................................................................................................
035 ...................................................................................................
036 ...................................................................................................
037 ...................................................................................................
038 ...................................................................................................
039 ...................................................................................................
040 ...................................................................................................
041 ...................................................................................................
042 ...................................................................................................
043 ...................................................................................................
044 ...................................................................................................
045 ...................................................................................................
046 ...................................................................................................
047 ...................................................................................................
048 ...................................................................................................
049 ...................................................................................................
050 ...................................................................................................
051 ...................................................................................................
052 ...................................................................................................
053 ...................................................................................................
054 ...................................................................................................
055 ...................................................................................................
056 ...................................................................................................
057 ...................................................................................................
058 ...................................................................................................
059 ...................................................................................................
060 ...................................................................................................
061 ...................................................................................................
062 ...................................................................................................
063 ...................................................................................................
064 ...................................................................................................
065 ...................................................................................................
066 ...................................................................................................
067 ......................................................................o............................
068 .....................................................................oo............................
069 ......................................................................o............................
070 ...................................................................................................
071 ...................................................................................................
072 ...................................................................................................
073 ...................................................................................................
074 ...................................................................................................
075 ...................................................................................................
076 ...................................................................................................
077 ...................................................................................................
078 ...................................................................................................
079 ...................................................................................................
080 ...................................................................................................
081 ...................................................................................................
082 ...................................................................................................
083 ...................................................................................................
084 ...................................................................................................
085 ...................................................................................................
086 ...................................................................................................
087 ...................................................................................................
088 ...................................................................................................
089 ...................................................................................................
090 ...................................................................................................
091 ...................................................................................................
092 ...................................................................................................
093 ...................................................................................................
094 ...................................................................................................
095 ...................................................................................................
096 ...................................................................................................
097 ...................................................................................................
098 ...................................................................................................
099 ...................................................................................................
Piece 19 1:
.
.
.
.
.
.
.
.
.
.
.
*
*
*
.
.
.
.
.
  $$$ exec p2 : [./a.out]
 Plateau 100 99:
    012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678
000 ...................................................................................................
001 ...................................................................................................
002 ...................................................................................................
003 ...................................................................................................
004 ...................................................................................................
005 ...................................................................................................
006 ...................................................................................................
007 ...................................................................................................
008 ...................................................................................................
009 ...................................................................................................
010 ...................................................................................................
011 ...................................................................................................
012 ...................................................................................................
013 ...................................................................................................
014 ...................................................................................................
015 ...................................................................................................
016 ...................................................................................................
017 ...................................................................................................
018 ...................................................................................................
019 ...................................................................................................
020 ...................................................................................................
021 ...................................................................................................
022 ...................................................................................................
023 ...................................................................................................
024 ...................................................................................................
025 ...................................................................................................
026 ...................................................................................................
027 ...................................................................................................
028 ...................................................................................................
029 ..............................X....................................................................
030 ...................................................................................................
031 ...................................................................................................
032 ...................................................................................................
033 ...................................................................................................
034 ...................................................................................................
035 ...................................................................................................
036 ...................................................................................................
037 ...................................................................................................
038 ...................................................................................................
039 ...................................................................................................
040 ...................................................................................................
041 ...................................................................................................
042 ...................................................................................................
043 ...................................................................................................
044 ...................................................................................................
045 ...................................................................................................
046 ...................................................................................................
047 ...................................................................................................
048 ...................................................................................................
049 ...................................................................................................
050 ...................................................................................................
051 ...................................................................................................
052 ...................................................................................................
053 ...................................................................................................
054 ...................................................................................................
055 ...................................................................................................
056 ...................................................................................................
057 ...................................................................................................
058 ...................................................................................................
059 ...................................................................................................
060 ...................................................................................................
061 ...................................................................................................
062 ...................................................................................................
063 ...................................................................................................
064 ...................................................................................................
065 ...................................................................................................
066 ...................................................................................................
067 ...................................................................................................
068 ....................................................................oo.............................
069 .....................................................................oo............................
070 ...................................................................................................
071 ...................................................................................................
072 ...................................................................................................
073 ...................................................................................................
074 ...................................................................................................
075 ...................................................................................................
076 ...................................................................................................
077 ...................................................................................................
078 ...................................................................................................
079 ...................................................................................................
080 ...................................................................................................
081 ...................................................................................................
082 ...................................................................................................
083 ...................................................................................................
084 ...................................................................................................
085 ...................................................................................................
086 ...................................................................................................
087 ...................................................................................................
088 ...................................................................................................
089 ...................................................................................................
090 ...................................................................................................
091 ...................................................................................................
092 ...................................................................................................
093 ...................................................................................................
094 ...................................................................................................
095 ...................................................................................................
096 ...................................................................................................
097 ...................................................................................................
098 ...................................................................................................
099 ...................................................................................................
Piece 1 4:
..**
 ++
p2
Plateau 24 40:
    0123456789012345678901234567890123456789
000 ........................................
001 ........................................
002 ........................................
003 ...o....................................
004 ...o....................................
005 ...o....................................
006 ........................................
007 ........................................
008 ........................................
009 ........................................
010 ........................................
011 ........................................
012 ........................................
013 ........................................
014 ........................................
015 ........................................
016 ........................................
017 ........................................
018 ........................................
019 ................................X.......
020 ........................................
021 ........................................
022 ........................................
023 ........................................
Piece 4 4:
....
...*
.*.*
.***

 */