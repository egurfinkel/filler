/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:31:08 by egurfink          #+#    #+#             */
/*   Updated: 2017/05/09 17:10:31 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int						clr_nl(t_list *clr, char **line)
{
	int					len;

	len = 0;
	if (ft_strchr(clr->content, 10) != NULL)
	{
		len = (int)ft_strchr(clr->content, 10) - (int)clr->content;
		*line = ft_strncpy(ft_strnew((size_t)len), clr->content, (size_t)len);
		len = ((char*)clr->content)[0];
		clr->content = ft_strchr(clr->content, 10) + 1;
	}
	else
	{
		len = (int)ft_strchr(clr->content, 0) - (int)clr->content;
		*line = ft_strncpy(ft_strnew((size_t)len), clr->content, (size_t)len);
		len = ((char*)clr->content)[0];
		clr->content = 0;
	}
	if (*line[0] || len == 10)
		return (1);
	return (0);
}

int						ft_read(t_list *lst, char **line)
{
	char				*buff;

	buff = ft_strnew(BUFF_SIZE);
	while (ft_strchr(lst->content, 10) == NULL &&
			(read(lst->content_size, buff, BUFF_SIZE) != 0))
	{
		lst->content = ft_strjoin(lst->content, buff);
		ft_bzero(buff, BUFF_SIZE);
	}
	buff ? free(buff) : 0;
	if (lst->content)
		return (clr_nl(lst, line));
	return (0);
}

int						get_next_line(const int fd, char **line)
{
	static t_list		*gnl = 0;
	t_list				*multi;

	if (fd < 0 || read(fd, NULL, 0) < 0 || !line)
		return (-1);
	multi = gnl;
	while (multi)
	{
		if (multi->content_size == (size_t)fd)
			return (ft_read(multi, line));
		multi = multi->next;
	}
	multi = ft_lstnew(0, 0);
	multi->content_size = (size_t)fd;
	ft_lstadd(&gnl, multi);
	return (ft_read(gnl, line));
}
