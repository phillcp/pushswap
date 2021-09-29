/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:08:28 by marvin            #+#    #+#             */
/*   Updated: 2021/09/29 17:37:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	split_a_medium(t_list **stack_a, t_list **stack_b)
{
	int	median;
	int	half_len;

	median = ft_lst_get_median(*stack_a);
	half_len = ft_lstsize(*stack_a) / 2;
	while (half_len)
	{
		if ((long)(*stack_a)->content < median)
		{
			half_len--;
			push_stack_print(stack_b, stack_a, "pb");
		}
		else if (is_median_closer_to_top(*stack_a, median))
			rotate_stack_print(stack_a, "ra");
		else
			rev_rotate_stack_print(stack_a, "rra");
	}
}

int	is_median_closer_to_top(t_list *stack, int median)
{
	int		check;
	int		curr_index;
	int		first_index;
	int		last_index;

	curr_index = 0;
	first_index = -1;
	last_index = -1;
	while (stack)
	{
		if ((long)stack->content < median)
		{
			if (first_index == -1)
				first_index = curr_index;
			else
				last_index = curr_index;
		}
		curr_index++;
		stack = stack->next;
	}
	if (last_index == -1)
		check = first_index < (curr_index / 2);
	else
		check = first_index < (curr_index - last_index);
	return (check);
}

void	merge_b_into_a_ordering(t_list **stack_a, t_list **stack_b)
{
	int	min_b;
	int	max_b;

	while (*stack_b)
	{
		min_b = ft_lst_get_min(*stack_b);
		max_b = ft_lst_get_max(*stack_b);
		if ((long)(*stack_a)->content < min_b
			&& is_min_max_closer_to_top(*stack_b, min_b, max_b))
			double_rotate_stack_print(stack_a, stack_b);
		else if ((long)(*stack_a)->content < min_b)
			rotate_stack_print(stack_a, "ra");
		else if ((long)(*stack_b)->content == max_b)
			push_stack_print(stack_a, stack_b, "pa");
		else if ((long)(*stack_b)->content == min_b)
			push_stack_print(stack_a, stack_b, "pa");
		else if (is_min_max_closer_to_top(*stack_b, min_b, max_b))
			rotate_stack_print(stack_b, "rb");
		else
			rev_rotate_stack_print(stack_b, "rrb");
	}
}

int	is_min_max_closer_to_top(t_list *stack, int min, int max)
{
	int		len;
	int		index_min;
	int		index_max;
	int		check;

	len = ft_lstsize(stack);
	index_min = ft_lst_get_node_index(stack, min);
	index_max = ft_lst_get_node_index(stack, max);
	if (index_min < index_max)
		check = (index_min < (len - index_max));
	else
		check = (index_max < (len - index_min));
	return (check);
}

int	get_diff_partitions(t_list *partitions, t_list *stack_a)
{
	t_list	*dup;
	int		index_first;
	int		index_second;
	void	*data_intermediate_node;

	dup = ft_lstdup(stack_a);
	ft_lst_sort(&dup, ascending);
	index_first = ft_lst_get_node_index(dup, (long)partitions->content);
	index_second = ft_lst_get_node_index(dup, (long)partitions->next->content);
	if (index_second - index_first > MAX_STACK_INCREMENT
		|| (index_first == 0 && index_second == (ft_lstsize(stack_a) - 1)))
	{
		index_second = index_first + (index_second - index_first) / 2 + 1;
		data_intermediate_node = ft_lst_get_data_node(dup, index_second);
		ft_lstadd_after_another(partitions, ft_lstnew(data_intermediate_node));
	}
	ft_lstclear(&dup, ft_lstdel_int);
	return (index_second - index_first);
}
