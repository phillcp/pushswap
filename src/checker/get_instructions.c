/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:02:57 by marvin            #+#    #+#             */
/*   Updated: 2021/09/29 16:03:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_instructions.h"

void	get_instructions(t_list **instructions,
			t_list **stack_a,
			t_list **stack_b)
{
	char	*line;
	t_list	*tmp;

	while (get_next_line(STDIN_FILENO, &line))
	{
		if (!is_instruction_valid(line))
		{
			free(line);
			ft_exit(2, stack_a, stack_b, instructions);
		}
		tmp = ft_lstnew((void *)line);
		if (!tmp)
		{
			free(line);
			ft_exit(2, stack_a, stack_b, instructions);
		}
		ft_lstadd_back(instructions, tmp);
	}
	free(line);
}

static int	is_instruction_valid(char *instruction)
{
	if (!ft_strcmp(instruction, "sa"))
		return (1);
	else if (!ft_strcmp(instruction, "sb"))
		return (1);
	else if (!ft_strcmp(instruction, "ss"))
		return (1);
	else if (!ft_strcmp(instruction, "pa"))
		return (1);
	else if (!ft_strcmp(instruction, "pb"))
		return (1);
	else if (!ft_strcmp(instruction, "ra"))
		return (1);
	else if (!ft_strcmp(instruction, "rb"))
		return (1);
	else if (!ft_strcmp(instruction, "rr"))
		return (1);
	else if (!ft_strcmp(instruction, "rra"))
		return (1);
	else if (!ft_strcmp(instruction, "rrb"))
		return (1);
	else if (!ft_strcmp(instruction, "rrr"))
		return (1);
	else
		return (0);
}
