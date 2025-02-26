/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:11:37 by marvin            #+#    #+#             */
/*   Updated: 2025/02/26 13:28:37 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ARGS_H
# define PARSE_ARGS_H

# include "utils.h"

int	is_int(char *stack_item);
int	is_bigger_than_int(long long nb, char *item);
int	is_all_zeros(char *item);
int	has_duplicates(t_list *stack);

#endif
