/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraetz <agraetz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:01:49 by anniegraetz       #+#    #+#             */
/*   Updated: 2022/09/01 10:34:20 by agraetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_end(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*end;

	temp = *stack;
	*stack = (*stack)->next;
	end = get_end(*stack);
	temp->next = NULL;
	end->next = temp;
}

void	ra(t_stack **stacka)
{
	rotate(stacka);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stackb)
{
	rotate(stackb);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stacka, t_stack **stackb)
{
	rotate(stacka);
	rotate(stackb);
	write(1, "rr\n", 3);
}
