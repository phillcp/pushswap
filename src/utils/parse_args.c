/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiheaton <fiheaton@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:11:10 by marvin            #+#    #+#             */
/*   Updated: 2025/03/12 19:50:31 by fiheaton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

void	parse_args(char *stack[], int len, t_list **stack_a)
{
	t_list		*node;
	int			i;
	long long	tmp;
	char		*item;

	i = 0;
	if (stack[i][0] == '\0')
		ft_exit(1, stack_a, 0, 0);
	while (i < len)
	{
		item = abc(stack[i]);
		if (!is_int(stack[i]))
			ft_exit(1, stack_a, 0, 0);
		tmp = ft_atoi(stack[i]);
		if (is_bigger_than_int(tmp, item))
			ft_exit(1, stack_a, 0, 0);
		node = ft_lstnew((void *)tmp);
		if (!node)
			ft_exit(1, stack_a, 0, 0);
		ft_lstadd_back(stack_a, node);
		i++;
	}
	if (has_duplicates(*stack_a))
		ft_exit(1, stack_a, 0, 0);
}

int	is_int(char *stack_item)
{
	int	check;

	check = 1;
	if (*stack_item == '-')
	{
		if (ft_strlen(stack_item) == 1)
			check = 0;
		if (!ft_strisdigit(stack_item + 1))
			check = 0;
	}
	else if (!ft_strisdigit(stack_item))
		check = 0;
	return (check);
}

int	is_bigger_than_int(long long nb, char *item)
{
	int	check;
	int	ret;

	ret = 0;
	check = ft_strlen(item);
	if (nb < 0)
	{
		if (check > 10)
			ret = 1;
		else if (check == 10)
			if (ft_strcmp("2147483648", item) < 0)
				ret = 1;
	}
	else
	{
		if (check > 10)
			ret = 1;
		else if (check == 10)
			if (ft_strcmp("2147483647", item) < 0)
				ret = 1;
	}
	if (nb == 0 && !is_all_zeros(item))
		ret = 1;
	return (ret);
}

int	is_all_zeros(char *item)
{
	if (*item == '-')
		item++;
	while (*item)
	{
		if (*item++ != '0')
			return (0);
	}
	return (1);
}

int	has_duplicates(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->content == tmp->content)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}
