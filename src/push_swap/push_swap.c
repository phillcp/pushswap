/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:18:40 by marvin            #+#    #+#             */
/*   Updated: 2021/09/29 17:17:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (argc == 1)
		return (1);
	get_stack(argv + 1, argc - 1, &stack_a);
	if (!is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	ft_exit(0, &stack_a, &stack_b, 0);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*partitions;
	int		len;

	partitions = 0;
	ft_lstadd_front(&partitions, ft_lstnew((void *)ft_lst_get_max(*stack_a)));
	ft_lstadd_front(&partitions, ft_lstnew((void *)ft_lst_get_min(*stack_a)));
	len = ft_lstsize(*stack_a);
	if (len <= 1)
		return ;
	else if (len <= 3)
		sort_stack_small(stack_a);
	else if (len <= 5)
		sort_stack_medium(stack_a, stack_b);
	else
		sort_stack_large(stack_a, stack_b, &partitions);
	ft_lstclear(&partitions, ft_lstdel_int);
}

void	sort_stack_small(t_list **stack_a)
{
	int	min;
	int	max;

	min = ft_lst_get_min(*stack_a);
	max = ft_lst_get_max(*stack_a);
	while (!is_sorted(*stack_a))
	{
		if (((long)(*stack_a)->content < (long)(*stack_a)->next->content)
			|| ((long)(*stack_a)->content == max
					&& (long)(*stack_a)->next->content == min))
			rotate_stack_print(stack_a, "ra");
		else
			swap_stack_print(stack_a, "sa");
	}
}

void	sort_stack_medium(t_list **stack_a,	t_list **stack_b)
{
	split_a_medium(stack_a, stack_b);
	sort_stack_small(stack_a);
	if (ft_lstsize(*stack_b) == 2
		&& (long)(*stack_b)->content < (long)(*stack_b)->next->content)
		swap_stack_print(stack_b, "sb");
	merge_b_into_a_ordering(stack_a, stack_b);
}

void	sort_stack_large(t_list **stack_a,
			t_list **stack_b,
			t_list **partitions)
{
	int	ra_count;
	int	len_curr_partition;

	if (ft_lstsize(*partitions) == 1)
		return ;
	len_curr_partition = get_diff_partitions(*partitions, *stack_a);
	ra_count = split_a(stack_a, stack_b, *partitions, len_curr_partition);
	if (ft_lstsize(*stack_a) != ft_lstsize(*stack_b)
		&& ft_lstsize(*stack_a) + 1 != ft_lstsize(*stack_b))
		while (ra_count--)
			rev_rotate_stack_print(stack_a, "rra");
	if (ft_lstsize(*stack_b) <= MAX_STACK_INCREMENT)
	{
		merge_b_into_a_ordering(stack_a, stack_b);
		ft_lstdel_first(partitions, ft_lstdel_int);
	}
	else
	{
		merge_b_into_a_partitioning(stack_a, stack_b, partitions,
			ft_lstsize(*stack_b));
		ft_lst_sort(partitions, ascending);
		ft_lstdel_first(partitions, ft_lstdel_int);
	}
	sort_stack_large(stack_a, stack_b, partitions);
	rotate_until_sorted(stack_a);
}
