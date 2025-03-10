/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:02:11 by fheaton-          #+#    #+#             */
/*   Updated: 2025/03/10 18:46:07 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

int	parse_args2(char *stack[], int len, t_list **stack_a)
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
		if (!is_int(item))
			return (1);
		tmp = ft_atoi(item);
		if (is_bigger_than_int(tmp, item))
			return (1);
		node = ft_lstnew((void *)tmp);
		if (!node)
			return (1);
		ft_lstadd_back(stack_a, node);
		i++;
	}
	if (has_duplicates(*stack_a))
		return (1);
	return (0);
}

void	parse_string(char *stack, t_list **stack_a)
{
	char		**list;
	int			i;
	int			ret;

	list = ft_split(stack, ' ');
	i = 0;
	if (stack[0] == '\0')
		ft_exit(1, stack_a, 0, 0);
	while (list[i])
		i++;
	ret = parse_args2(list, i, stack_a);
	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	if (ret)
		ft_exit(1, stack_a, 0, 0);
}
