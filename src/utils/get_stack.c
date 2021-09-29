/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:11:10 by marvin            #+#    #+#             */
/*   Updated: 2021/09/29 16:29:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_stack.h"

void	get_stack(char *stack[], int len, t_list **stack_a)
{
	t_list		*node;
	int			i;
	long long	tmp;

	i = 0;
	while (i < len)
	{
		if (!is_int(stack[i]))
			ft_exit(1, stack_a, 0, 0);
		tmp = ft_atoi(stack[i]);
		if (is_bigger_than_int(tmp, stack[i]))
			ft_exit(1, stack_a, 0, 0);
		node = ft_lstnew((void *)tmp);
		if (!node)
			ft_exit(1, stack_a, 0, 0);
		ft_lstadd_back(stack_a, node);
		i++;
	}
	if (has_duplicates(*stack_a))
		ft_exit(1, stack_a, 0, 0);
}

static int	is_int(char *stack_item)
{
	int	check;

	check = 1;
	if (*stack_item == '-')
	{
		if (!ft_strisdigit(stack_item + 1))
			check = 0;
	}
	else if (!ft_strisdigit(stack_item))
		check = 0;
	return (check);
}

static int	is_bigger_than_int(long long nb, char *item)
{
	int	check;

	check = 0;
	if (nb < INT_MIN || INT_MAX < nb)
		check = 1;
	if (nb == 0 && !is_all_zeros(item))
		check = 1;
	return (check);
}

static int	is_all_zeros(char *item)
{
	if (*item == '-')
		item++;
	while (*item)
	{
		if (*item++ != '0')
			return (0);
	}
	return (1);
}

static int	has_duplicates(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->content == tmp->content)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}
