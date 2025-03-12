/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiheaton <fiheaton@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:12:27 by marvin            #+#    #+#             */
/*   Updated: 2025/03/12 17:53:31 by fiheaton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define GREEN_BOLD "\033[1;32m"
# define RED_BOLD "\033[1;31m"
# define YELLOW_BOLD "\033[1;33m"
# define CYAN_BOLD "\033[1;36m"
# define RESET "\033[0m"

# include "./../../libft/src/libft.h"

void	ft_exit(int exit_code,
			t_list **stack_a,
			t_list **stack_b,
			t_list **instructions);
void	print_stacks(char *instruction,	t_list *stack_a, t_list *stack_b);
void	print_stack(t_list **stack_a, int *len_a, t_list **stack_b, int *len_b);
int		is_sorted(t_list *stack);
char	*abc(char *str);

#endif
