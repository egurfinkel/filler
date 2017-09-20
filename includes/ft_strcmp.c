/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:10:43 by egurfink          #+#    #+#             */
/*   Updated: 2016/12/28 16:06:25 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	while (*c1 || *c2)
	{
		if (*c1 < *c2)
			return (*c1 - *c2);
		if (*c1 > *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	return (0);
}
