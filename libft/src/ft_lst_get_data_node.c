/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_data_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:54:32 by fheaton-          #+#    #+#             */
/*   Updated: 2021/09/29 17:33:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lst_get_data_node(t_list *lst, int index)
{
	if (!lst)
		return (0);
	while (index--)
		lst = lst->next;
	return (lst->content);
}
