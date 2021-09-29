/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:12:35 by fheaton-          #+#    #+#             */
/*   Updated: 2021/09/29 17:33:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_print_s(t_list *lst)
{
	t_list	*tmp;

	if (lst == 0)
	{
		printf("\n");
		return ;
	}
	tmp = lst;
	while (tmp->next)
	{
		printf("\"%s\" -", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf(" \"%s\"\n", (char *)tmp->content);
}

void	ft_lst_print_d(t_list *lst)
{
	if (lst == 0)
	{
		printf("\n");
		return ;
	}
	while (lst->next)
	{
		printf("[%ld]-", (long int)lst->content);
		lst = lst->next;
	}
	printf("[%ld]\n", (long int)lst->content);
}
