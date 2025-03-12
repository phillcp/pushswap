/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiheaton <fiheaton@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:06:00 by fheaton-          #+#    #+#             */
/*   Updated: 2025/03/12 17:58:28 by fiheaton         ###   ########.fr       */
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
		parse_args(argv + 2, argc - 2, &stack_a);
	else
		parse_args(argv + 1, argc - 1, &stack_a);
	get_instructions(&instructions, &stack_a, &stack_b);
	exec_instructions(instructions, &stack_a, &stack_b, mode);
	if (is_sorted(stack_a) && ft_lstsize(stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_exit(0, &stack_a, &stack_b, &instructions);
}
