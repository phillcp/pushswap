/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:21:46 by fheaton-          #+#    #+#             */
/*   Updated: 2021/07/29 16:26:02 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}
