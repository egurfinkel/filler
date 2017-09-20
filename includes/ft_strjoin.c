/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 21:42:34 by egurfink          #+#    #+#             */
/*   Updated: 2017/02/22 21:28:31 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*join;
	size_t		len;

	len = 0;
	if (!s1 && !s2)
		return (0);
	(!s1 && s2) ? join = ft_strdup(s2) : 0;
	(s1 && !s2) ? join = ft_strdup(s1) : 0;
	if (s1 && s2)
	{
		join = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		while (*s1)
			join[len++] = *s1++;
		while (*s2)
			join[len++] = *s2++;
		join[len] = '\0';
	}
	return (join);
}
