/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uxll_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:49:41 by fheaton-          #+#    #+#             */
/*   Updated: 2021/07/24 14:05:55 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	uxll_num_len(unsigned long long n, t_fmt *fmt)
{
	int	len;
	int	base;

	len = 0;
	base = 16;
	if (fmt->conv == 'u')
		base = 10;
	if (n == 0 && !(fmt->point && fmt->precision == 0))
		len = 1;
	if (fmt->hash && fmt->conv != 'u' && n != 0)
		len += 2;
	while (n != 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}

static void	uxll_zero_print(unsigned long long n, t_fmt *fmt, int extra)
{
	if (fmt->hash && fmt->conv != 'u' && n != 0)
	{
		write(1, "0", 1);
		write(1, &fmt->conv, 1);
	}
	while (extra-- > 0)
		write(1, "0", 1);
	if (n == 0 && fmt->point && fmt->precision == 0)
		return ;
	if (fmt->conv == 'u')
		ft_put_ullnbr(n);
	else if (fmt->conv == 'x')
		ft_put_xllnbr(n, "0123456789abcdef");
	else
		ft_put_xllnbr(n, "0123456789ABCDEF");
}

static void	uxll_actual_print(unsigned long long n, t_fmt *fmt, int xw, int xpr)
{
	if (fmt->fill == '0')
		uxll_zero_print(n, fmt, xw);
	else
	{
		if (!fmt->left_align)
		{
			while (xw-- > 0)
				write(1, " ", 1);
		}
		uxll_zero_print(n, fmt, xpr);
		if (fmt->left_align)
		{
			while (xw-- > 0)
				write(1, " ", 1);
		}
	}
}

int	uxll_print(t_fmt *fmt, va_list ap)
{
	unsigned long long	n;
	int					n_len;
	int					real_preci;
	int					extra_preci;
	int					extra_width;

	n = (unsigned long long)va_arg(ap, unsigned long long);
	n_len = uxll_num_len(n, fmt);
	real_preci = fmt->precision;
	if (fmt->hash && fmt->conv != 'u' && n != 0)
		real_preci += 2;
	extra_preci = 0;
	if (real_preci > n_len)
		extra_preci = real_preci - n_len;
	extra_width = calc_width(n_len, fmt->width, real_preci);
	if (fmt->point && fmt->fill != ' ')
		fmt->fill = ' ';
	uxll_actual_print(n, fmt, extra_width, extra_preci);
	return (extra_preci + extra_width + n_len);
}
