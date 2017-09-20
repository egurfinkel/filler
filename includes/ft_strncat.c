/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:52:55 by egurfink          #+#    #+#             */
/*   Updated: 2016/12/28 16:17:27 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = dest;
	while (*dest)
		dest++;
	while (*src && i++ != n)
		*(dest++) = *(src++);
	*dest = '\0';
	return (str);
}
