/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:00:12 by fheaton-          #+#    #+#             */
/*   Updated: 2021/08/05 21:29:44 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rra(int *stack_a, int argc)
{
	int a;
	int swap;

	swap = stack_a[argc - 1];
	a = argc;
	while ((stack_a[--a] && stack_a[a - 1]) != 0)
	{
		stack_a[a] = stack_a[a - 1];
	}
	stack_a[0] = swap;
}

void	rrb(int *stack_b, int argc)
{
	int a;
	int swap;

	swap = stack_b[argc - 1];
	a = argc;
	while ((stack_b[--a] && stack_b[a - 1]) != 0)
	{
		stack_b[a] = stack_b[a - 1];
	}
	stack_b[0] = swap;
}

void	rrr(int *stack_a, int *stack_b, int argc)
{
	rra(stack_a, argc);
	rrb(stack_b, argc);
}
