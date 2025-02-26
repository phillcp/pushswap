/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:01:52 by marvin            #+#    #+#             */
/*   Updated: 2025/02/26 13:31:45 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "utils.h"
# include "instructions.h"

void	parse_args(char *stack[], int len, t_list **stack_a);
void	get_instructions(t_list **instructions,
			t_list **stack_a,
			t_list **stack_b);
void	exec_instructions(t_list *instructions,
			t_list **stack_a,
			t_list **stack_b,
			char mode);

#endif
