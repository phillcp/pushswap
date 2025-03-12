/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:49:41 by fheaton-          #+#    #+#             */
/*   Updated: 2021/07/24 14:02:50 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lnum_len(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	fnum_len(double f, t_fmt *fmt)
{
	int			len;
	long int	bef;
	long int	aft;
	long int	next;

	len = 0;
	if (f < 0 || 1 / f == -INFINITY || fmt->plus)
		len++;
	if (f > 0)
		f *= -1;
	bef = (long int)f;
	aft = (f - bef) * ft_recursive_power(10, fmt->precision);
	next = (aft * 10) - (f - bef) * ft_recursive_power(10, fmt->precision + 1);
	if (bef == 0 || (next >= 5 && (bef % 10) == -9
			&& (!fmt->precision || lnum_len(aft - 1) > fmt->precision)))
		len++;
	while (bef != 0)
	{
		len++;
		bef = bef / 10;
	}
	if (fmt->precision || fmt->hash)
		len++;
	return (len + fmt->precision);
}

static void	ft_actual_putfloat(long int bef, long int aft, int prec, int hash)
{
	int	extra_zeros;

	ft_put_lnbr_nosign(bef);
	if (prec || hash)
		write(1, ".", 1);
	if (prec)
	{
		extra_zeros = prec - lnum_len(aft);
		while (extra_zeros-- > 0)
			write(1, "0", 1);
		ft_put_lnbr_nosign(aft);
	}
}

void	ft_putfloat_nosign(double f, int precision, int hash)
{
	long int	bef;
	long int	aft;
	double		nextn;

	if (f > 0)
		f *= -1;
	bef = (long int)f;
	aft = (f - bef) * ft_recursive_power(10, precision);
	nextn = (aft * 100) - (f - bef) * ft_recursive_power(10, precision + 2);
	if (!precision && (nextn > 50 || (nextn >= 50 && bef % 2 != 0)))
		bef--;
	else if (precision && nextn >= 50)
	{
		if (lnum_len(aft - 1) > precision)
		{
			bef--;
			aft = 0;
		}
		else
			aft--;
	}
	ft_actual_putfloat(bef, aft, precision, hash);
}
