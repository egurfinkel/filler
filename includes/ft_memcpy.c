/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:34:24 by egurfink          #+#    #+#             */
/*   Updated: 2016/12/14 19:19:58 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *str1, const void *str2, size_t n)
{
	const unsigned char		*src;
	unsigned char			*dest;

	src = str2;
	dest = str1;
	while (n-- > 0)
		*dest++ = *src++;
	return (str1);
}
