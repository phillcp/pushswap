/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:47:53 by fheaton-          #+#    #+#             */
/*   Updated: 2021/09/29 17:33:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_lst_get_min(t_list *lst)
{
	long long	min;

	if (!lst)
		return (INT_MIN);
	min = (long long int)lst->content;
	while (lst)
	{
		if ((long long int)lst->content < min)
			min = (long long int)lst->content;
		lst = lst->next;
	}
	return (min);
}
