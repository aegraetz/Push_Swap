/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anniegraetz <anniegraetz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:28:38 by agraetz           #+#    #+#             */
/*   Updated: 2022/09/05 09:24:13 by anniegraetz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;//int to sort
	int				index;//index in the list of values for sorting
	int				pos;//current position in stack
	int				target_pos;//target position in stack a where the elements in stack b should go
	int				costa;//how many actions it will cost to get element from stack b into the target_post in stack
	int				costb;//how many actions it will cost to rotate stack b so that target element is at top
	struct s_stack	*next;//pointer to next element in the list
}	t_stack;

/*Cost*/
void		cost_of_move(t_stack **stacka, t_stack **stackb);
void		execute_cheapest(t_stack **stacka, t_stack **stackb);
int			absolute(int num);

/*Execute*/
void		execute_move(t_stack **a, t_stack **b, int costa, int costb);

/*Initialise*/
t_stack		*init_stack(int argc, char **argv);
void		init_index(t_stack *stacka, int size);
int			stack_size(t_stack *stack);
t_stack		*new_node(int num);
void		add_end(t_stack **stack, t_stack *num);

/*Input Checks*/
int			input_check(char **argv);

/*Position*/
void		init_target_pos(t_stack **stacka, t_stack **stackb);
int			lowest_index(t_stack **stack);
t_stack		*get_end(t_stack *stack);

/*Utils*/
void		free_stacks(t_stack **stack);
int			ft_atoi(const char *str);

/*Operations*/
void		pa(t_stack **stacka, t_stack **stackb);
void		pb(t_stack **stacka, t_stack **stackb);
void		rra(t_stack **stacka);
void		rrb(t_stack **stackb);
void		rrr(t_stack **stacka, t_stack **stackb);
void		ra(t_stack **stacka);
void		rb(t_stack **stackb);
void		rr(t_stack **stacka, t_stack **stackb);
void		sa(t_stack **stacka);
void		sb(t_stack **stackb);
void		ss(t_stack **stacka, t_stack **stackb);

/*Sort*/
void		three_sort(t_stack **stack);
void		big_sort(t_stack **stacka, t_stack **stackb);
int			sorted(t_stack *stack);

#endif