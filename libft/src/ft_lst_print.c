/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiheaton <fiheaton@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:12:35 by fheaton-          #+#    #+#             */
/*   Updated: 2025/03/12 17:58:20 by fiheaton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_print_s(t_list *lst)
{
	t_list	*tmp;

	if (lst == 0)
	{
		ft_printf("\n");
		return ;
	}
	tmp = lst;
	while (tmp->next)
	{
		ft_printf("\"%s\" -", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_printf(" \"%s\"\n", (char *)tmp->content);
}

void	ft_lst_print_d(t_list *lst)
{
	if (lst == 0)
	{
		ft_printf("\n");
		return ;
	}
	while (lst->next)
	{
		ft_printf("[%ld]-", (long int)lst->content);
		lst = lst->next;
	}
	ft_printf("[%ld]\n", (long int)lst->content);
}
