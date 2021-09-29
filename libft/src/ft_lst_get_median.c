/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_median.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:48:03 by fheaton-          #+#    #+#             */
/*   Updated: 2021/09/29 17:33:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_lst_get_median(t_list *lst)
{
	t_list		*dup;
	t_list		*tmp;
	int			half_size;
	long long	median;

	dup = ft_lstdup(lst);
	half_size = ft_lstsize(dup) / 2;
	ft_lst_sort(&dup, ascending);
	tmp = dup;
	while (half_size--)
		tmp = tmp->next;
	median = (long long)tmp->content;
	ft_lstclear(&dup, ft_lstdel_int);
	return (median);
}
