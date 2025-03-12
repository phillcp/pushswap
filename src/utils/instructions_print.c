/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiheaton <fiheaton@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:14:54 by marvin            #+#    #+#             */
/*   Updated: 2025/03/12 17:59:11 by fiheaton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_print.h"

void	swap_stack_print(t_list **stack, char *str)
{
	ft_printf("%s\n", str);
	swap_stack(stack);
}

void	push_stack_print(t_list **dest, t_list **src, char *str)
{
	ft_printf("%s\n", str);
	push_stack(dest, src);
}

void	rotate_stack_print(t_list **stack, char *str)
{
	ft_printf("%s\n", str);
	rotate_stack(stack);
}

void	double_rotate_stack_print(t_list **stack_a, t_list **stack_b)
{
	ft_printf("rr\n");
	rotate_stack(stack_a);
	rotate_stack(stack_b);
}

void	rev_rotate_stack_print(t_list **stack, char *str)
{
	ft_printf("%s\n", str);
	rev_rotate_stack(stack);
}
