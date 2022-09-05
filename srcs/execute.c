/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anniegraetz <anniegraetz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:56:56 by anniegraetz       #+#    #+#             */
/*   Updated: 2022/09/05 09:27:08 by anniegraetz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_both(t_stack **a, t_stack **b, int *costa, int *costb);
static void	rotate_both(t_stack **a, t_stack **b, int *costa, int *costb);
static void	rotate_a(t_stack **a, int *cost);
static void	rotate_b(t_stack **b, int *cost);

void	execute_move(t_stack **a, t_stack **b, int costa, int costb)
{
	if (costa < 0 && costb < 0)//if both costs are a negative number
		rev_rotate_both(a, b, &costa, &costb);
	else if (costa > 0 && costb > 0)//if bother costs are positive numbers
		rotate_both (a, b, &costa, &costb);
	//if both costs are not matching (ie. not both +ve or -ve) they need to be rotated separately
	rotate_a(a, &costa);
	rotate_b(b, &costb);
	pa(a, b);//until we can push the element at the front of stack b to the front of stack a
}

static void	rev_rotate_both(t_stack **a, t_stack **b, int *costa, int *costb)
{
	while (*costa < 0 && *costb < 0)//when one stack reaches 0, the element has reached it's target position
	{
		(*costa)++;
		(*costb)++;
		rrr(a, b);//continues to rotate both stacks until one is in the target position
	}
}

static void	rotate_both(t_stack **a, t_stack **b, int *costa, int *costb)
{
	while (*costa > 0 && *costb > 0)//when one stack reaches 0, the element has reached it's target position
	{
		(*costa)--;
		(*costb)--;
		rr(a, b);//continues to rotate both stacks until one is in the target position
	}
}

static void	rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

static void	rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}
