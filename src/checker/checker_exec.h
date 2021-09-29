/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:01:00 by marvin            #+#    #+#             */
/*   Updated: 2021/09/29 16:04:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_EXEC_H
# define CHECKER_EXEC_H

# include "checker.h"

static void	exec_swap(t_list *instructions,
				t_list **stack_a,
				t_list **stack_b);
static void	exec_push(t_list *instructions,
				t_list **stack_a,
				t_list **stack_b);
static void	exec_rotate(t_list *instructions,
				t_list **stack_a,
				t_list **stack_b);
static void	exec_rev_rotate(t_list *instructions,
				t_list **stack_a,
				t_list **stack_b);

#endif
