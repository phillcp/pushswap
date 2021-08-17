/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 20:57:58 by fheaton-          #+#    #+#             */
/*   Updated: 2021/08/05 21:07:37 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sa(int *stack_a)
{
	int swap;

	swap = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = swap;
}

void	sb(int *stack_b)
{
	int swap;

	swap = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = swap;
}

void	ss(int *stack_a, int *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
