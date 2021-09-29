/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:20:55 by fheaton-          #+#    #+#             */
/*   Updated: 2021/09/29 17:33:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_last(t_list *lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*last_node;

	if (!lst || !lst->next)
		return ;
	tmp = lst;
	while (tmp->next->next)
		tmp = tmp->next;
	last_node = tmp->next;
	tmp->next = 0;
	del(last_node->content);
	free(last_node);
}
