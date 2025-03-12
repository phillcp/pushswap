/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiheaton <fiheaton@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:49:41 by fheaton-          #+#    #+#             */
/*   Updated: 2024/06/13 12:47:50 by fiheaton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	p_num_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	len += 2;
	return (len);
}

int	align(int extra_width)
{
	while (extra_width-- > 0)
		write(1, " ", 1);
	return (extra_width);
}

int	p_print(t_fmt *fmt, va_list ap)
{
	void			*p;
	int				p_len;
	int				extra_width;
	int				total_width;

	p = va_arg(ap, void *);
	p_len = p_num_len((unsigned long)p);
	extra_width = 0;
	if (fmt->width > p_len)
		extra_width = fmt->width - p_len;
	total_width = extra_width + p_len;
	if (!fmt->left_align)
		extra_width = align(extra_width);
	if (p == NULL)
		write(1, "(nil)", 5);
	if (p == NULL)
		return (total_width + 2);
	write(1, "0x", 2);
	ft_put_xl((unsigned long)p, "0123456789abcdef");
	if (fmt->left_align)
		extra_width = align(extra_width);
	return (total_width);
}
