/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:00:10 by fheaton-          #+#    #+#             */
/*   Updated: 2021/08/05 21:26:07 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ra(int *stack_a)
{
	int a;
	int swap;

	swap = stack_a[0];
	a = -1;
	while ((stack_a[++a] && stack_a[a + 1]) != 0)
	{
		stack_a[a] = stack_a[a + 1];
	}
	stack_a[a] = swap;
}

void	rb(int *stack_b)
{
	int a;
	int swap;

	swap = stack_b[0];
	a = -1;
	while ((stack_b[++a] && stack_b[a + 1]) != 0)
	{
		stack_b[a] = stack_b[a + 1];
	}
	stack_b[a] = swap;
}

void	rr(int *stack_a, int *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
