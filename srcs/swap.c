/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraetz <agraetz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:54:28 by anniegraetz       #+#    #+#             */
/*   Updated: 2022/09/01 10:36:15 by agraetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	sa(t_stack **stacka)
{
	swap(*stacka);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stackb)
{
	swap(*stackb);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stacka, t_stack **stackb)
{
	swap(*stacka);
	swap(*stackb);
	write(1, "ss\n", 3);
}
