#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

/*
**				Checker
*/

int		checker(char **list,int argc);

/*
**				Actions
*/

void	sa(int *stack_a);
void	sb(int *stack_b);
void	ss(int *stack_a, int *stack_b);
void	pa(int *stack_a, int *stack_b);
void	pb(int *stack_a, int *stack_b);
void	ra(int *stack_a);
void	rb(int *stack_b);
void	rr(int *stack_a, int *stack_b);
void	rra(int *stack_a, int argc);
void	rrb(int *stack_b, int argc);
void	rrr(int *stack_a, int *stack_b, int argc);

#endif
