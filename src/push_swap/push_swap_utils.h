/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:10:05 by marvin            #+#    #+#             */
/*   Updated: 2021/09/29 16:10:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# define MAX_STACK_INCREMENT 20

# include "utils.h"
# include "instructions.h"
# include "instructions_print.h"

/*
** push_swap_utils1.c
*/

void	split_a_medium(t_list **stack_a, t_list **stack_b);
int		is_median_closer_to_top(t_list *stack, int median);
void	merge_b_into_a_ordering(t_list **stack_a, t_list **stack_b);
int		is_min_max_closer_to_top(t_list *stack, int min, int max);
int		get_diff_partitions(t_list *partitions, t_list *stack_a);

/*
** push_swap_utils2.c
*/

int		split_a(t_list **stack_a,
			t_list **stack_b,
			t_list *partitions,
			int partition_len);
int		is_first_node_a_sorted(t_list *stack_a, t_list *stack_b);
void	merge_b_into_a_partitioning(t_list **stack_a,
			t_list **stack_b,
			t_list **partitions,
			int old_len);
void	rotate_until_sorted(t_list **stack);

#endif
