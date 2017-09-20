/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 14:57:38 by egurfink          #+#    #+#             */
/*   Updated: 2016/12/29 14:57:40 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_pushback(t_list *lst, t_list *news)
{
	t_list	*temp;

	if (lst != NULL)
	{
		temp = lst;
		while (lst->next)
			lst = lst->next;
		lst->next = news;
		lst = temp;
	}
	else
		lst = news;
	return (lst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_temp;
	t_list	*new_list;
	t_list	*temp1;
	t_list	*temp2;

	temp1 = lst;
	new_list = NULL;
	while (temp1)
	{
		temp2 = f((t_list*)temp1);
		new_temp = ft_lstnew(temp2->content, temp2->content_size);
		new_list = ft_pushback(new_list, new_temp);
		temp1 = temp1->next;
	}
	return (new_list);
}
