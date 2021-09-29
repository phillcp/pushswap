/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:09:26 by marvin            #+#    #+#             */
/*   Updated: 2021/09/29 17:37:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	split_a(t_list **stack_a,
				t_list **stack_b,
				t_list *partitions,
				int partition_len)
{
	int	is_first_split;
	int	ra_count;

	is_first_split = ft_round(ft_lstsize(*stack_a) / 2.0) == partition_len;
	ra_count = 0;
	while (partition_len)
	{
		if ((long)partitions->content <= (long)(*stack_a)->content
			&& (long)(*stack_a)->content < (long)partitions->next->content)
		{
			partition_len--;
			if (is_first_node_a_sorted(*stack_a, *stack_b) && !is_first_split)
				rotate_stack_print(stack_a, "ra");
			else
				push_stack_print(stack_b, stack_a, "pb");
		}
		else if ((long)(*stack_a)->content < (long)partitions->content)
			rotate_stack_print(stack_a, "ra");
		else
		{
			ra_count++;
			rotate_stack_print(stack_a, "ra");
		}
	}
	return (ra_count);
}

int	is_first_node_a_sorted(t_list *stack_a, t_list *stack_b)
{
	t_list		*dup;
	int			index_first_node;
	int			index_last_node;
	long long	data_last_node;

	data_last_node = (long long)ft_lst_get_data_last_node(stack_a);
	dup = ft_lstdup(stack_a);
	ft_lstadd_back(&dup, ft_lstdup(stack_b));
	ft_lst_sort(&dup, ascending);
	index_first_node = ft_lst_get_node_index(dup, (long long)stack_a->content);
	index_last_node = ft_lst_get_node_index(dup, data_last_node);
	ft_lstclear(&dup, ft_lstdel_int);
	if (index_last_node == (index_first_node - 1)
		&& ft_lstsize(stack_a) > index_last_node)
		return (1);
	else
		return (0);
}

void	merge_b_into_a_partitioning(t_list **stack_a,
				t_list **stack_b,
				t_list **partitions,
				int old_len)
{
	int	curr_len;
	int	tmp;

	tmp = 0;
	if (old_len == 0 || !(*stack_b))
		return ;
	ft_lstadd_front(partitions, ft_lstnew((void *)ft_lst_get_median(*stack_b)));
	curr_len = old_len;
	while (curr_len > old_len / 2 && *stack_b)
	{
		if ((long)(*partitions)->content <= (long)(*stack_b)->content && curr_len--)
			push_stack_print(stack_a, stack_b, "pa");
		else if ((long)(*stack_b)->content == ft_lst_get_min(*stack_b))
		{
			tmp++;
			push_stack_print(stack_a, stack_b, "pa");
			if (*stack_b != 0)
				rotate_stack_print(stack_a, "ra");
		}
		else
			rotate_stack_print(stack_b, "rb");
	}
	merge_b_into_a_partitioning(stack_a, stack_b, partitions, curr_len - tmp);
}

void	rotate_until_sorted(t_list **stack)
{
	int	min;
	int	half_len;
	int	index;

	min = ft_lst_get_min(*stack);
	half_len = ft_lstsize(*stack) / 2;
	index = ft_lst_get_node_index(*stack, (long long)min);
	if (index < half_len)
	{
		while ((long)(*stack)->content != min)
			rotate_stack_print(stack, "ra");
	}
	else
	{
		while ((long)(*stack)->content != min)
			rev_rotate_stack_print(stack, "rra");
	}
}
