/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:49:18 by egurfink          #+#    #+#             */
/*   Updated: 2016/12/08 18:49:59 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dtmp;
	char	*stmp;

	i = 0;
	dtmp = dst;
	stmp = (char *)src;
	while (i < n && (i == 0 || stmp[i - 1] != c))
	{
		dtmp[i] = stmp[i];
		i++;
	}
	if (i > 0 && stmp[i - 1] == c)
		return (dtmp + i);
	else
		return (NULL);
}
