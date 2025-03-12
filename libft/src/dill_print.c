/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dill_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:49:41 by fheaton-          #+#    #+#             */
/*   Updated: 2021/07/24 14:01:39 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ll_num_len(long long int n, t_fmt *fmt)
{
	int	len;

	len = 0;
	if (n == 0 && !(fmt->point && fmt->precision == 0))
		len = 1;
	if (n < 0 || fmt->plus)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	dill_zero_print(long long int n, t_fmt *fmt, int extra)
{
	if (fmt->plus && n >= 0)
		write(1, &fmt->plus, 1);
	if (n < 0)
		write(1, "-", 1);
	while (extra-- > 0)
		write(1, "0", 1);
	if (n != 0 || !fmt->point || fmt->precision != 0)
		ft_put_llnbr_nosign(n);
}

static void	dill_actual_print(long long int n, t_fmt *fmt, int xwd, int xprec)
{
	if (fmt->fill == '0')
		dill_zero_print(n, fmt, xwd);
	else
	{
		if (!fmt->left_align)
		{
			while (xwd-- > 0)
				write(1, " ", 1);
		}
		dill_zero_print(n, fmt, xprec);
		if (fmt->left_align)
		{
			while (xwd-- > 0)
				write(1, " ", 1);
		}
	}
}

int	dill_print(t_fmt *fmt, va_list ap)
{
	long long int	n;
	int				n_len;
	int				real_preci;
	int				extra_preci;
	int				extra_width;

	n = (long long int)va_arg(ap, long long int);
	n_len = ll_num_len(n, fmt);
	real_preci = fmt->precision;
	if (n < 0 || (fmt->plus && !(n == 0 && fmt->point && fmt->precision == 0)))
		real_preci++;
	extra_preci = 0;
	if (real_preci > n_len)
		extra_preci = real_preci - n_len;
	extra_width = calc_width(n_len, fmt->width, real_preci);
	if (fmt->point && fmt->fill != ' ')
		fmt->fill = ' ';
	dill_actual_print(n, fmt, extra_width, extra_preci);
	return (extra_preci + extra_width + n_len);
}
