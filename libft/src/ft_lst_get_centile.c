/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_centile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:48:03 by fheaton-          #+#    #+#             */
/*   Updated: 2021/09/29 17:33:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_lst_get_centile(t_list *lst, int ctl_picked)
{
	t_list		*dup;
	t_list		*tmp;
	int			centile;
	long long	ret;

	if (1 < ctl_picked && ctl_picked < 10)
		return (0);
	dup = ft_lstdup(lst);
	centile = ft_lstsize(dup) * ctl_picked / 100;
	ft_lst_sort(&dup, ascending);
	tmp = dup;
	while (centile--)
		tmp = tmp->next;
	ret = (long long)tmp->content;
	ft_lstclear(&dup, ft_lstdel_int);
	return (ret);
}
