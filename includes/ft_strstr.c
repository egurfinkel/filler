/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:34:01 by egurfink          #+#    #+#             */
/*   Updated: 2016/12/14 17:34:04 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *target)
{
	char	*p1;
	char	*p2;
	char	*begin;

	p1 = (char*)str;
	p2 = (char*)target;
	if (!*target)
		return ((void*)str);
	while (*p1)
	{
		begin = p1;
		p2 = (char*)target;
		while (*p1 && *p2 && *p1 == *p2)
		{
			p1++;
			p2++;
		}
		if (!*p2)
			return (begin);
		p1 = begin + 1;
	}
	return (NULL);
}
