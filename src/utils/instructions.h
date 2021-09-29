/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:13:38 by marvin            #+#    #+#             */
/*   Updated: 2021/09/29 16:13:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "utils.h"

void	swap_stack(t_list **stack);
void	push_stack(t_list **dest, t_list **src);
void	rotate_stack(t_list **stack);
void	rev_rotate_stack(t_list **stack);

#endif
