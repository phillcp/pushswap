/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_print.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:14:11 by marvin            #+#    #+#             */
/*   Updated: 2021/09/29 16:15:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_PRINT_H
# define INSTRUCTIONS_PRINT_H

# include "utils.h"
# include "instructions.h"

void	swap_stack_print(t_list **stack, char *str);
void	push_stack_print(t_list **dest, t_list **src, char *str);
void	rotate_stack_print(t_list **stack, char *str);
void	double_rotate_stack_print(t_list **stack_a, t_list **stack_b);
void	rev_rotate_stack_print(t_list **stack, char *str);

#endif
