/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anniegraetz <anniegraetz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 09:59:00 by anniegraetz       #+#    #+#             */
/*   Updated: 2022/09/05 09:45:05 by anniegraetz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	largest_index(t_stack *stack)
{
	int	i;

	i = stack->index;
	while (stack)//cycle through the stack to find the highest index number
	{
		if (stack->index > i)
			i = stack->index;
		stack = stack->next;
	}
	return (i);
}

void	three_sort(t_stack **stack)
{
	int	largest;

	if (sorted(*stack))//first check to see the elements are already sorted
		return ;
	largest = largest_index(*stack);//then find the highest index (this is the largest element)
	if ((*stack)->index == largest)//if index at front of the list is the largest
		ra(stack);//rotate it to the end
	else if ((*stack)->next->index == largest)//if the second index in the list is the largest
		rra(stack); //then rotate the end of the list to the front
	if ((*stack)->index > (*stack)->next->index)//then, if the first index in the list is larger than the second index
		sa(stack);//swap them
}

static void	push_but_three(t_stack **stacka, t_stack **stackb)//we want to push all but 3 to stack b but we want to do it with efficiency
{
	int	size;
	int	push;
	int	i;

	size = stack_size(*stacka);
	push = 0;
	i = 0;
	//if there's a lot of elements we want to get them somewhat sorted before we push them across
	while (size > 6 && i < size && push < size / 2)
	{
		if ((*stacka)->index <= size / 2)//if the index is in the front half of the list
		{
			pb(stacka, stackb);//we're happy to push the elements across to stack b
			push++;
		}
		else//but if it's in the back half of the lis
			ra(stacka);//we want to rotate it to the bottom of stack a
		i++;
	}
	while (size - push > 3)//if there's between 4 & 6 elements in the list then we're happy to push them straight across (except the last 3)
	{
		pb(stacka, stackb);
		push++;
	}
}

static void	sort_a(t_stack **stacka)
{
	int	start_pos;
	int	size;

	size = stack_size(*stacka);
	start_pos = lowest_index(stacka);//the position at which the element with the lowest index is found (ie. what we need at the start fo the list)
	if (start_pos > size / 2)//if it's in the end half of the stack
	{
		while (start_pos < size)
		{
			rra(stacka); //we reverse rotate till it's at the top
			start_pos++;
		}
	}
	else//if it's in the first half
	{
		while (start_pos > 0)
		{
			ra(stacka); //we rotate till it's at the top
			start_pos--;
		}
	}
}

void	big_sort(t_stack **stacka, t_stack **stackb)
{
	push_but_three(stacka, stackb);
	three_sort(stacka);
	while (*stackb)
	{
		init_target_pos(stacka, stackb);//find the target_pos for each element in stack b
		cost_of_move(stacka, stackb);//find out the cost for moving each of these elements in to their target_pos
		execute_cheapest(stacka, stackb);//determine the cheapest moves and then execute them one by one
	}
	//now we look at stack a
	if (!sorted(*stacka))//if it's not fully sorted (most likely wont be)
		sort_a(stacka); //we shuffle till it is
}
