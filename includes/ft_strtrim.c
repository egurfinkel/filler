/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 19:58:06 by egurfink          #+#    #+#             */
/*   Updated: 2016/12/28 18:48:22 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	unsigned int	len;

	if (s)
	{
		if (!*s)
			return (ft_strnew(1));
		i = 0;
		len = ft_strlen(s) - 1;
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
					|| s[i] == '.') && i < len + 1)
			i++;
		while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n'
					|| s[len] == '.') && &s[len] != s)
			len--;
		if (i >= len || i == ft_strlen(s))
			return (ft_strnew(1));
		if ((str = ft_strnew(len - i + 1)))
		{
			ft_strncpy(str, s + i, len - i + 1);
			return (str);
		}
	}
	return (NULL);
}
