/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiheaton <fiheaton@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:07:41 by marvin            #+#    #+#             */
/*   Updated: 2025/03/12 18:43:41 by fiheaton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap_utils.h"

void	parse_args(char *stack[], int len, t_list **stack_a);
void	parse_string(char **stack, t_list **stack_a);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	sort_stack_small(t_list **stack_a);
void	sort_stack_medium(t_list **stack_a, t_list **stack_b);
void	sort_stack_large(t_list **stack_a,
			t_list **stack_b,
			t_list **partitions);

#endif
