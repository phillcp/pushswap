/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 20:59:30 by fheaton-          #+#    #+#             */
/*   Updated: 2021/08/05 21:25:32 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rm_first(int *stack)
{
	int a;

	a = -1;
	while ((stack[++a] && stack[a + 1]) != 0)
	{
		stack[a] = stack[a + 1];
	}
}

void	pa(int *stack_a, int *stack_b)
{
	int a;

	a = 0;
	while ((stack_b[a] && stack_b[a + 1]) != 0)
		a++;
	stack_b[a] = stack_a[0];
	rm_first(stack_a);
}

void	pb(int *stack_a, int *stack_b)
{
	int a;

	a = 0;
	while ((stack_a[a] && stack_a[a + 1]) != 0)
		a++;
	stack_a[a] = stack_b[0];
	rm_first(stack_b);
}
