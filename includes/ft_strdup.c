/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:01:29 by egurfink          #+#    #+#             */
/*   Updated: 2016/12/08 19:13:33 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	size_t	l;
	char	*dup;

	l = 0;
	while (src[l])
		l++;
	dup = (char*)malloc(sizeof(char) * (l + 1));
	if (dup)
	{
		ft_strcpy(dup, src);
		return (dup);
	}
	else
		return (NULL);
}
