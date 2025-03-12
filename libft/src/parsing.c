/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiheaton <fiheaton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:49:41 by fheaton-          #+#    #+#             */
/*   Updated: 2024/05/14 13:16:08 by fiheaton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(char flag, t_fmt *fmt)
{
	if (flag == '-')
	{
		fmt->left_align = 1;
		fmt->fill = ' ';
	}
	if (!fmt->left_align && flag == '0')
		fmt->fill = '0';
	if (flag == '+')
		fmt->plus = '+';
	if (!fmt->plus && flag == ' ')
		fmt->plus = ' ';
	if (flag == '#')
		fmt->hash = 1;
}

static void	deal_neg_width(t_fmt *fmt)
{
	fmt->width *= -1;
	fmt->left_align = 1;
	fmt->fill = ' ';
}

static void	deal_neg_preci(t_fmt *fmt)
{
	fmt->point = 0;
	fmt->precision = 0;
}

static void	parse_size(char flag, t_fmt *fmt)
{
	if (fmt->size == 'l' && flag == 'l')
		fmt->size = 'L';
	if (fmt->size == 'h' && flag == 'h')
		fmt->size = 'H';
	if (!fmt->size && flag == 'l')
		fmt->size = 'l';
	if (!fmt->size && flag == 'h')
		fmt->size = 'h';
}

int	parse(const char *str, t_fmt *fmt, va_list ap)
{
	int		i;

	i = 0;
	while (str_include("-0+ #", str[i]))
		parse_flags(str[i++], fmt);
	if (str[i] == '*' && str[i++])
		fmt->width = va_arg(ap, int);
	if (fmt->width < 0)
		deal_neg_width(fmt);
	while (str[i] >= '0' && str[i] <= '9')
		fmt->width = fmt->width * 10 + (str[i++] - '0');
	if (str[i] == '.' && str[i++])
		fmt->point = 1;
	if (str[i] == '*' && str[i++])
		fmt->precision = va_arg(ap, int);
	if (fmt->precision < 0)
		deal_neg_preci(fmt);
	while (str[i] >= '0' && str[i] <= '9')
		fmt->precision = fmt->precision * 10 + (str[i++] - '0');
	while (str[i] == 'l' || str[i] == 'h')
		parse_size(str[i++], fmt);
	if (str_include("cspdiuxXnf%", str[i]))
		fmt->conv = str[i++];
	return (i);
}
