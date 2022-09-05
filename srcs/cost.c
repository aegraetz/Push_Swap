/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anniegraetz <anniegraetz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:52:26 by anniegraetz       #+#    #+#             */
/*   Updated: 2022/09/05 09:25:30 by anniegraetz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_of_move(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tempa;
	t_stack	*tempb;
	int		sizea;
	int		sizeb;

	tempa = *stacka;
	tempb = *stackb;
	sizea = stack_size(tempa);
	sizeb = stack_size(tempb);
	while (tempb) //cycling through stack b
	{
		tempb->costb = tempb->pos; //set the cost of reaching the top of stack b as the element's pos
		if (tempb->pos > sizeb / 2)//if that pos is in the end half of the list
			tempb->costb = (sizeb - tempb->pos) * -1;//the cost is negative
		tempb->costa = tempb->target_pos;//the cost of getting to the target_pos in stack a is the target_pos number
		if (tempb->target_pos > sizea / 2)//if the target_pos is in the end half of stack a 
			tempb->costa = (sizea - tempb->target_pos) * -1;//the cost is negative
		tempb = tempb->next;
	}
}

int	absolute(int num)//find the absolute value of the cost = the distance of that number from 0
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	execute_cheapest(t_stack **stacka, t_stack **stackb)
{
	t_stack	*temp;
	int		cheapest;
	int		costa;
	int		costb;

	temp = *stackb;
	cheapest = INT_MAX;
	while (temp)
	{
		if (absolute(temp->costa) + absolute(temp->costb) < absolute(cheapest))
		{
			cheapest = absolute(temp->costb) + absolute(temp->costa);
			costa = temp->costa;
			costb = temp->costb;
		}
		temp = temp->next;
	}
	execute_move(stacka, stackb, costa, costb);
}
