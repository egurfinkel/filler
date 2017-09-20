/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 14:58:09 by egurfink          #+#    #+#             */
/*   Updated: 2016/12/29 15:43:33 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

	link = (t_list*)malloc(sizeof(t_list));
	if (link == NULL)
		return (NULL);
	if (content == NULL)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		link->content = malloc(content_size);
		link->content_size = content_size;
		ft_memmove(link->content, content, content_size);
	}
	link->next = NULL;
	return (link);
}
