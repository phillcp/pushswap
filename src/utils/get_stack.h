/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:11:37 by marvin            #+#    #+#             */
/*   Updated: 2021/09/29 16:11:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_STACK_H
# define GET_STACK_H

# include "utils.h"

static int	is_int(char *stack_item);
static int	is_bigger_than_int(long long nb, char *item);
static int	is_all_zeros(char *item);
static int	has_duplicates(t_list *stack);

#endif
