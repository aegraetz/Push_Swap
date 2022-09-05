/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anniegraetz <anniegraetz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:41:18 by anniegraetz       #+#    #+#             */
/*   Updated: 2022/09/05 09:38:36 by anniegraetz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_method(t_stack **stacka, t_stack **stackb, int size);
void		free_stacks(t_stack **stack);

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	int		size;

	if (argc < 2)
	{
		return (0);
	}
	if (input_check(argv) != 0)
	{	
		return (0);
	}//make sure that the characters inputted are valid as per pdf
	stackb = NULL;
	stacka = init_stack(argc, argv);
	size = stack_size(stacka);//get the size of the stack (amount of elements in the list)
	init_index(stacka, size + 1);//assign indexes to the values so that the indexes can be compared rather than the values
	sort_method(&stacka, &stackb, size);//checks the size of the stack and chooses a method of sorting accordingly
	free_stacks(&stacka);
	free_stacks(&stackb);
	return (0);
}

int	sorted(t_stack *stack)
{
	while (stack->next != NULL)//while not at the end of the list
	{
		if (stack->value > stack->next->value)//if a value is bigger than the next value then it's not sorted
			return (0); //in this case, returns 0 as stack is clearly not sorted
		stack = stack->next; //check next if the if statement not entered
	}
	return (1);//if stack is sorted returns 1
}

static void	sort_method(t_stack **stacka, t_stack **stackb, int size)
{
	if (size == 2 && !sorted(*stacka))//if there's only 2 elements and they're not sorted
		sa(stacka);//do a swap
	else if (size == 3)//if there's 3 elements
		three_sort(stacka);//sort method for 3 elements
	else if (size > 3 && !sorted(*stacka))//if it's bigger than 3 elements and not sorted
		big_sort(stacka, stackb);//bust out the big sort method
}

void	free_stacks(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
	{
		return ;
	}
	while (*stack)
	{
		temp = (*stack)->next;//free each element in the stack
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;//set pointer to NULL
}
