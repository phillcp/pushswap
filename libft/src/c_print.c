/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:49:41 by fheaton-          #+#    #+#             */
/*   Updated: 2021/07/24 13:59:57 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_print(t_fmt *fmt, va_list ap)
{
	unsigned char	c;
	int				extra_width;
	int				total_width;

	if (fmt->conv == '%')
		c = '%';
	else
		c = (unsigned char)va_arg(ap, int);
	extra_width = 0;
	if (fmt->width > 1)
		extra_width = fmt->width - 1;
	total_width = extra_width + 1;
	if (!fmt->left_align)
	{
		while (extra_width-- > 0)
			write(1, &fmt->fill, 1);
	}
	write(1, &c, 1);
	if (fmt->left_align)
	{
		while (extra_width-- > 0)
			write(1, &fmt->fill, 1);
	}
	return (total_width);
}
