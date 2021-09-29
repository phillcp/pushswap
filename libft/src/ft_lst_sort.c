/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:03:47 by fheaton-          #+#    #+#             */
/*   Updated: 2021/09/29 17:32:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst_sort.h"

void	ft_lst_sort(t_list **lst, int (*op)(int, int))
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *lst;
	if (head == NULL || head->next == NULL)
		return ;
	split_list(head, &a, &b);
	ft_lst_sort(&a, op);
	ft_lst_sort(&b, op);
	*lst = merge_sort(a, b, op);
}

static void	split_list(t_list *head, t_list **first_half, t_list **second_half)
{
	t_list	*slow;
	t_list	*fast;

	slow = head;
	fast = head->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*first_half = head;
	*second_half = slow->next;
	slow->next = NULL;
}

static t_list	*merge_sort(t_list *a, t_list *b, int (*op)(int, int))
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (op((long int)a->content, (long int)b->content))
	{
		result = a;
		result->next = merge_sort(a->next, b, op);
	}
	else
	{
		result = b;
		result->next = merge_sort(a, b->next, op);
	}
	return (result);
}

int	ascending(int a, int b)
{
	return (a < b);
}

int	descending(int a, int b)
{
	return (a > b);
}
