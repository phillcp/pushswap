/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:06:00 by fheaton-          #+#    #+#             */
/*   Updated: 2021/08/05 22:39:00 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_dirs(char* dir, int *stack_a, int *stack_b, int argc)
{
	if(ft_strnstr (dir, "sa", 2))
		sa(stack_a);
	else if(ft_strnstr (dir, "sb", 2))
		sb(stack_b);
	else if(ft_strnstr (dir, "ss", 2))
		ss(stack_a, stack_b);
	else if(ft_strnstr (dir, "pa", 2))
		pa(stack_a, stack_b);
	else if(ft_strnstr (dir, "pb", 2))
		pb(stack_a, stack_b);
	else if(ft_strnstr (dir, "ra", 2))
		ra(stack_a);
	else if(ft_strnstr (dir, "rb", 2))
		rb(stack_b);
	else if(ft_strnstr (dir, "rr", 2))
		rr(stack_a, stack_b);
	else if(ft_strnstr (dir, "rra", 3))
		rra(stack_a, argc);
	else if(ft_strnstr (dir, "rrb", 3))
		rrb(stack_b, argc);
	else if(ft_strnstr (dir, "rrr", 3))
		rrr(stack_a, stack_b, argc);
	else
		return (0);
	return (1);
}

int	convert_stack_a (char **list, int argc, int *stack_a)
{
	int a;
	int b;
	int num_size;

	a = 0;
	num_size = 0;
	while (list[++a])
		if(ft_strlen(list[a]) > num_size)
			num_size = ft_strlen(list[a]);
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

int init_stack_b(int *stack_b, int num_size, int argc)
{
	stack_b = malloc((argc - 1) * num_size * sizeof(int));
	if (!stack_b)
		return (NULL);
	return (1);
}

int	*init(char **list, int argc)
{
	char **dirs;
	int *stack_a;
	int *stack_b;
	int a;
	int b;

	a = convert_stack_a(**list, argc, stack_a);
	if (a = 0)
		return (NULL);
	if (!init_stack_b(stack_b, a, argc));
		return(NULL);
	a = -1;
	while (get_next_line(0, dirs) != -1)
	{
		if (!check_dirs(dirs[++a], stack_a, stack_b, argc));
			return (NULL);
	}
	return (stack_a);
}


int		checker(char **list,int argc)
{
	int *stack_a;
	int a;

	stack_a = init(list, argc);
	if (!stack_a)
		return (2);
	a = -1;
	while(++a)
	{
		if((stack_a[a + 1] && stack_a[a + 2]) == 0)
			return (1);
		if((stack_a[a + 1] || stack_a[a + 2]) != 0)
		{
			if(stack_a[a] > stack_a[a + 1])
				return (0);
		}
	}
}
