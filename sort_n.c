/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:40:19 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/13 13:04:26 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_3_nodes(t_stack **stack)
{
	t_stack	*largest;

	largest = find_max_pointer(*stack);
	if (*stack == largest)
		ra(stack, 1);
	else if ((*stack)->next == largest)
		rra(stack, 1);
	if ((*stack)->number > (*stack)->next->number)
		sa(stack, 1);
}

t_stack	*find_smallest(t_stack *stack_a)
{
	t_stack	*min;

	min = stack_a;
	while (stack_a != NULL)
	{
		if (stack_a->number < min->number)
			min = stack_a;
		stack_a = stack_a->next;
	}
	return (min);
}

void	sort_4_numbers(t_stack **a, t_stack **b)
{
	t_stack	*min;

	set_pos_and_median(*a);
	min = find_smallest(*a);
	while (min->position != 1)
	{
		if (min->median == 1)
			ra(a, 1);
		else
			rra(a, 1);
		set_pos_and_median(*a);
	}
	pb(a, b);
	sort_3_nodes(a);
	pa(a, b);
}

void	sort_5_num(t_stack **a, t_stack **b)
{
	t_stack	*min;

	set_pos_and_median(*a);
	min = find_smallest(*a);
	while (min->position != 1)
	{
		if (min->median == 1)
			ra(a, 1);
		else
			rra(a, 1);
		set_pos_and_median(*a);
	}
	pb(a, b);
	sort_4_numbers(a, b);
	pa(a, b);
}
void sort_2(t_stack **a)
{
	if((*a)->number > (*a)->next->number)
		ra(a,1);
}
