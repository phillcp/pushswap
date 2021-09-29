/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:52:06 by fheaton-          #+#    #+#             */
/*   Updated: 2021/09/29 17:30:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_SORT_H
# define FT_LST_SORT_H

# include "libft.h"

static void		split_list(t_list *head,
					t_list **first_half,
					t_list **second_half);
static t_list	*merge_sort(t_list *a, t_list *b, int (*op)(int, int));

#endif
