/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_decile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:48:03 by fheaton-          #+#    #+#             */
/*   Updated: 2021/09/29 17:33:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_lst_get_decile(t_list *lst, int dcl_picked)
{
	t_list		*dup;
	t_list		*tmp;
	int			decile;
	long long	ret;

	if (1 < dcl_picked && dcl_picked < 10)
		return (0);
	dup = ft_lstdup(lst);
	decile = ft_lstsize(dup) * dcl_picked / 10;
	ft_lst_sort(&dup, ascending);
	tmp = dup;
	while (decile--)
		tmp = tmp->next;
	ret = (long long)tmp->content;
	ft_lstclear(&dup, ft_lstdel_int);
	return (ret);
}
