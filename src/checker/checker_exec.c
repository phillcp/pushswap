/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:00:05 by marvin            #+#    #+#             */
/*   Updated: 2021/09/29 16:25:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_exec.h"

void	exec_instructions(t_list *instructions,
			t_list **stack_a,
			t_list **stack_b,
			char mode)
{
	if (mode == 'v')
		print_stacks("Init", *stack_a, *stack_b);
	while (instructions)
	{
		if (*(char *)instructions->content == 's')
			exec_swap(instructions, stack_a, stack_b);
		else if (*(char *)instructions->content == 'p')
			exec_push(instructions, stack_a, stack_b);
		else if (ft_strlen((char *)instructions->content) == 2)
			exec_rotate(instructions, stack_a, stack_b);
		else
			exec_rev_rotate(instructions, stack_a, stack_b);
		if (mode == 'v')
			print_stacks((char *)instructions->content, *stack_a, *stack_b);
		instructions = instructions->next;
	}
}

static void	exec_swap(t_list *instructions,
			t_list **stack_a,
			t_list **stack_b)
{
	if (!ft_strcmp((char *)instructions->content, "sa"))
		swap_stack(stack_a);
	else if (!ft_strcmp((char *)instructions->content, "sb"))
		swap_stack(stack_b);
	else if (!ft_strcmp((char *)instructions->content, "ss"))
	{
		swap_stack(stack_a);
		swap_stack(stack_b);
	}
}

static void	exec_push(t_list *instructions,
			t_list **stack_a,
			t_list **stack_b)
{
	if (!ft_strcmp((char *)instructions->content, "pa"))
		push_stack(stack_a, stack_b);
	else if (!ft_strcmp((char *)instructions->content, "pb"))
		push_stack(stack_b, stack_a);
}

static void	exec_rotate(t_list *instructions,
			t_list **stack_a,
			t_list **stack_b)
{
	if (!ft_strcmp((char *)instructions->content, "ra"))
		rotate_stack(stack_a);
	else if (!ft_strcmp((char *)instructions->content, "rb"))
		rotate_stack(stack_b);
	else if (!ft_strcmp((char *)instructions->content, "rr"))
	{
		rotate_stack(stack_a);
		rotate_stack(stack_b);
	}
}

static void	exec_rev_rotate(t_list *instructions,
			t_list **stack_a,
			t_list **stack_b)
{
	if (!ft_strcmp((char *)instructions->content, "rra"))
		rev_rotate_stack(stack_a);
	else if (!ft_strcmp((char *)instructions->content, "rrb"))
		rev_rotate_stack(stack_b);
	else if (!ft_strcmp((char *)instructions->content, "rrr"))
	{
		rev_rotate_stack(stack_a);
		rev_rotate_stack(stack_b);
	}
}
