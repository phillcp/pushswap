/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:14:54 by marvin            #+#    #+#             */
/*   Updated: 2021/09/29 16:18:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_print.h"

void	swap_stack_print(t_list **stack, char *str)
{
	printf("%s\n", str);
	swap_stack(stack);
}

void	push_stack_print(t_list **dest, t_list **src, char *str)
{
	printf("%s\n", str);
	push_stack(dest, src);
}

void	rotate_stack_print(t_list **stack, char *str)
{
	printf("%s\n", str);
	rotate_stack(stack);
}

void	double_rotate_stack_print(t_list **stack_a, t_list **stack_b)
{
	printf("rr\n");
	rotate_stack(stack_a);
	rotate_stack(stack_b);
}

void	rev_rotate_stack_print(t_list **stack, char *str)
{
	printf("%s\n", str);
	rev_rotate_stack(stack);
}
