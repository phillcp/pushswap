/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:47:25 by fheaton-          #+#    #+#             */
/*   Updated: 2021/09/29 17:33:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_lst_get_max(t_list *lst)
{
	long long	max;

	if (!lst)
		return (INT_MAX);
	max = (long long int)lst->content;
	while (lst)
	{
		if (max < (long long int)lst->content)
			max = (long long int)lst->content;
		lst = lst->next;
	}
	return (max);
}
