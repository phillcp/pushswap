/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_node_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:47:41 by fheaton-          #+#    #+#             */
/*   Updated: 2021/09/29 17:33:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_get_node_index(t_list *lst, long long data_to_find)
{
	int	index;

	index = 0;
	while (lst)
	{
		if ((long long)lst->content == data_to_find)
			break ;
		index++;
		lst = lst->next;
	}
	if (!lst)
		index = -1;
	return (index);
}
