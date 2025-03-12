/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiheaton <fiheaton@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:33:44 by marvin            #+#    #+#             */
/*   Updated: 2025/03/12 19:40:53 by fiheaton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

long	ft_atoi(const char *str)
{
	long	a;
	long	b;
	long	c;

	a = 0;
	b = 1;
	c = 0;
	while (ft_isspace(str[a]))
		a++;
	if (str[a] == '+')
		a++;
	else if (str[a] == '-')
	{
		b *= -1;
		a++;
	}
	while (ft_isdigit(str[a]))
	{
		c = c * 10 + str[a] - '0';
		a++;
	}
	return (c *= b);
}
