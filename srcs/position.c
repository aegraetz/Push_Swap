/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anniegraetz <anniegraetz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:51:50 by anniegraetz       #+#    #+#             */
/*   Updated: 2022/09/05 09:35:17 by anniegraetz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_pos(t_stack **stack);
static int	get_target(t_stack **a, int b_index, int t_index, int target_pos);

void	init_target_pos(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tempb;
	int		target_pos;

	tempb = *stackb;
	get_pos(stacka);//assign position numbers to each element
	get_pos(stackb);
	target_pos = 0;
	while (tempb)
	{
		target_pos = get_target(stacka, tempb->index, INT_MAX, target_pos);//find the position in stack a where the element in stack b needs to be
		tempb->target_pos = target_pos;//this becomes the element's target position
		tempb = tempb->next;//do this for each element in stack b
	}
}

static void	get_pos(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)//cycle through each element in the list and assign it a position number
	{
		temp->pos = i;//starting from 0 and increasing with each node
		temp = temp->next;
		i++;
	}
}

static int	get_target(t_stack **a, int b_index, int t_index, int target_pos)
{
	t_stack	*tempa;

	tempa = *a;
	while (tempa)//cycling through the indexes in stack a 
	{
		if (tempa->index > b_index && tempa->index < t_index)//if the index in stack a is more than the index of the element in b and less than INT_MAX
		{
			t_index = tempa->index;//the target index is now the index of that stack a element's index
			target_pos = tempa->pos;//and the target position is where that element is
		}
		tempa = tempa->next;//then we compare the next element in stack a till we get the closest index &, as a result, the target pos
	}
	if (t_index != INT_MAX)//if the target index is no longer INT_MAX then this process worked and we can return the target pos
		return (target_pos);
	tempa = *a; //if the first if statement was never satisfied and the target index was never changed, we need a new strategy
	while (tempa)//cycling through till the end of the list
	{
		if (tempa->index < t_index)//this time, if the stack a element's index is only less than INT_MAX
		{
			t_index = tempa->index;
			target_pos = tempa->pos;
		}
		tempa = tempa->next;//cycle through stack a to the end of the list- this is the target position as the index is clearly larger than all the elements in a
	}
	return (target_pos);
}

int	lowest_index(t_stack **stack)//find the position of the element with the lowest index in a stack
{
	t_stack	*temp;
	int		lowest_index;
	int		position;

	temp = *stack;
	lowest_index = INT_MAX;
	get_pos(stack);
	position = temp->pos;
	while (temp)//cycle through each index in the stack till the lowest index is found
	{
		if (temp->index < lowest_index)
		{
			lowest_index = temp->index;
			position = temp->pos;
		}
		temp = temp->next;
	}
	return (position);//return the position of that lowest index
}
