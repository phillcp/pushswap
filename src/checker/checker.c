/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:06:00 by fheaton-          #+#    #+#             */
/*   Updated: 2021/09/29 16:46:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_list	*instructions;
	t_list	*stack_a;
	t_list	*stack_b;
	char	mode;

	instructions = 0;
	stack_a = 0;
	stack_b = 0;
	mode = '\0';
	if (argc == 1 || (argc == 2 && !ft_strcmp(argv[1], "-v")))
		return (1);
	if (!ft_strcmp(argv[1], "-v"))
		mode = 'v';
	if (!ft_strcmp(argv[1], "-v"))
		get_stack(argv + 2, argc - 2, &stack_a);
	else
		get_stack(argv + 1, argc - 1, &stack_a);
	get_instructions(&instructions, &stack_a, &stack_b);
	exec_instructions(instructions, &stack_a, &stack_b, mode);
	if (is_sorted(stack_a) && ft_lstsize(stack_b) == 0)
		printf("OK\n");
	else
		printf("KO\n");
	ft_exit(0, &stack_a, &stack_b, &instructions);
}
