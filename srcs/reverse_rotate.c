/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraetz <agraetz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:37:45 by anniegraetz       #+#    #+#             */
/*   Updated: 2022/09/01 10:34:04 by agraetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_penultimate(t_stack *stack);

static void	rev_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*end;
	t_stack	*penultimate;

	end = get_end(*stack);
	penultimate = get_penultimate(*stack);
	temp = *stack;
	*stack = end;
	(*stack)->next = temp;
	penultimate->next = NULL;
}

void	rra(t_stack **stacka)
{
	rev_rotate(stacka);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stackb)
{
	rev_rotate(stackb);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stacka, t_stack **stackb)
{
	rev_rotate(stacka);
	rev_rotate(stackb);
	write(1, "rrr\n", 4);
}

t_stack	*get_penultimate(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
