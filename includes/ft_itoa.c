/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:21:40 by egurfink          #+#    #+#             */
/*   Updated: 2016/12/21 21:54:26 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*nul_n(void)
{
	char			*str;

	str = (char*)malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static int			count_len(unsigned int num)
{
	int				i;

	i = 0;
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	char			*out;
	int				count;
	int				nbr;
	int				flag;

	nbr = n;
	flag = (n < 0 ? 1 : 0);
	if (flag)
		nbr = n * -1;
	if (!n)
		return (nul_n());
	count = count_len(nbr);
	if (!(out = (char*)malloc(sizeof(char) * count + flag + 1)))
		return (NULL);
	count += flag;
	out[count--] = '\0';
	while (count >= 0)
	{
		out[count] = (nbr % 10) + '0';
		nbr /= 10;
		count--;
	}
	if (flag)
		out[0] = '-';
	return (out);
}
