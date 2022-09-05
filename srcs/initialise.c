/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anniegraetz <anniegraetz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:53:31 by anniegraetz       #+#    #+#             */
/*   Updated: 2022/09/05 09:29:33 by anniegraetz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int num);
void	add_end(t_stack **stack, t_stack *num);

t_stack	*init_stack(int argc, char **argv)
{
	t_stack		*stacka;
	long int	num;
	int			i;

	stacka = NULL;
	num = 0;
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);//convert to integer
		if (i == 1)
			stacka = new_node((int)num);//argv[1]doesn't need to be added to end as it's the first
		else
			add_end(&stacka, new_node((int)num));//create list node and add to the end
		i++;
	}
	return (stacka);
}

t_stack	*new_node(int num)//create a new node on the list of stack elements
{
	t_stack	*node;

	node = malloc(sizeof * node);//initialise each variable in the node's struct
	if (!node)
		return (NULL);
	node->value = num;
	node->index = 0;
	node->pos = -1;
	node->target_pos = -1;
	node->costa = -1;
	node->costb = -1;
	node->next = NULL;
	return (node);
}

void	add_end(t_stack **stack, t_stack *num)
{
	t_stack	*end;

	if (!num)
		return ;
	if (!*stack)
	{
		*stack = num;
		return ;
	}
	end = get_end(*stack);
	end->next = num;
}

int	stack_size(t_stack *stack)//find the size of the list same way we find length of a string
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	init_index(t_stack *stacka, int size)
{
	t_stack	*i;
	t_stack	*highest;
	int		value;

	while (--size > 0)//working backwards through the values, deincrementing each time
	{
		i = stacka;
		value = INT_MIN;
		highest = NULL;
		while (i)
		{
			if (i->value == INT_MIN && i->index == 0)//checking for the smallest value
				i->index = 1;//1 is lowest number's index
			if (i->value > value && i->index == 0)//if the value is bigger than the value previously checked
			{
				value = i->value;//the value is reset to this bigger value
				highest = i;//highest now stores this bigger value
				i = stacka;//and i returns to stack a
			}
			else
				i = i->next;//if the value isn't larger than the last then continue on
		}
		if (highest != NULL)
			highest->index = size;//this largest value is assigned the highest index
	}
}
