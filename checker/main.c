/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:01:11 by fheaton-          #+#    #+#             */
/*   Updated: 2021/08/15 18:20:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc,char **argv)
{
	int a;

	a = checker(argv, argc);
	if (a = 2)
		ft_putstr_fd("Error\n", 2);
	else if (a = 1)
		ft_putstr_fd("OK\n", 1);
	else if (a = 0)
		ft_putstr_fd("KO\n", 1);
	return(0);
}
