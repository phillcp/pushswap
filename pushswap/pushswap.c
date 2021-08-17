/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:18:40 by marvin            #+#    #+#             */
/*   Updated: 2021/08/15 21:16:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	convert_stack_a (char **list, int argc, int *stack_a)
{
	int a;
	int b;
	int num_size;

	a = 0;
	num_size = 0;
	while (list[++a])
	{
		if(ft_strlen(list[a]) > num_size)
			num_size = ft_strlen(list[a]);
	}
	stack_a = malloc((argc - 1) * num_size * sizeof(int));
	if (!stack_a)
		return (0);
	a = 0;
	while (list[++a])
	{
		b = -1;
		while (list[a][++b])
		{
			if (!ft_isdigit(list[a][b]))
				return (0);
		}
		stack_a[a] = atoi(list[a]);
	}
	return (num_size);
}

int *init_stack(int size_a)
{
	int *stack_extra;

	stack_extra = malloc((size_a - 1) * sizeof(int));
	if (!stack_extra)
		return (0);
	return (stack_extra);
}

void	swap_int(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

int orden(int *stack_a, int size_a)
{
	int *stack_extra;
	int a;
	int b;

	stack_extra = init_stack(size_a);
	a = -1;
	while (++a < (size_a - 1))
		stack_extra[a] = stack_a[a];
	a = -1;
	while (++a < (size_a - 1))
	{
		b = -1;
		while (++b < (size_a - 1))
		{
			if (stack_extra[a] > stack_extra[b])
				swap_int(&stack_extra[a], &stack_extra[b]);
		}
	}
	return (stack_extra);
}

int	find_median(int *stack_a, int size_a)
{
	int *stack_extra;
	
	stack_extra = orden(stack_a, size_a);
	if (size_a % 2 == 0)
		return ((stack_extra[size_a / 2 - 1] + stack_extra[size_a / 2]) / 2);
	else
		return (stack_extra[size_a / 2]);
}

void copy_stacks(int *stack_a, int *copy_a, int size_a)
{
	int a;

	a = -1;
	while (++a < size_a)
		copy_a[a] = stack_a[a];
}

int init_stacks(int *stack_a, int *stack_b, int *copy_a, int size_a)
{
	stack_b = init_stack(size_a);
	copy_a = init_stack(size_a);
	copy_stacks(stack_a, copy_a, size_a);
}

int stack_a(int *stack_a)
{
	int median;
	int size_a;
	int *stack_b;
	int *copy_a;

	size_a = (sizeof(stack_a) / sizeof(int));
	median = find_median(stack_a, size_a);
	init_stacks(stack_a, stack_b, copy_a, size_a);
	while (--size_a != 0)
	{
		if (stack_a[size_a] < median)
			pb(copy_a, stack_b);
		else 
			ra(copy_a, stack_b);
	}
}

int	calc(int *stack_a)
{
	int median;
	int size_a;
	int *stack_b;
	int *copy_a;

	new_stack(stack_a);
	size_a = (sizeof(stack_a) / sizeof(int));
	median = find_median(stack_a, size_a);
	init_stacks(stack_a, stack_b, copy_a, size_a);
	while (--size_a != 0)
		if (stack_a[size_a] < median)
			pb(copy_a, stack_b);
		else 
			ra(copy_a, stack_b);
}

int	*init(char **list, int argc)
{
	char **dirs;
	int *stack_a;
	int a;
	int b;

	a = convert_stack_a(**list, argc, stack_a);
	if (a = 0)
		return (0);
	calc(stack_a, argc);
}

int		pushswap(char **list,int argc)
{
	int *stack_a;
	int a;

	stack_a = init(list, argc);
}
