/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:23:53 by fheaton-          #+#    #+#             */
/*   Updated: 2021/08/15 21:16:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int init_stack(int num_size, int argc)
{
	int stack_extra;

	stack_extra = malloc((argc - 1) * num_size * sizeof(int));
	if (!stack_extra)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	pushswap(argv, argc);
}
