/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:41:14 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/13 10:40:47 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_h(t_stack **stack_a, t_stack **stack_b)
{
	set_pos_and_median(*stack_a);
	set_pos_and_median(*stack_b);
	set_target_of_a(*stack_a, *stack_b);
	find_cost(*stack_a);
	find_cost(*stack_b);
	add_cost_of_a_and_b(*stack_a, stack_b);
}

void	sort_max(t_stack **stack_b)
{
	t_stack	*max;

	max = find_max_pointer(*stack_b);
	set_pos_and_median(*stack_b);
	while (max->position != 1)
	{
		if (max->median == 1)
			rb(stack_b, 1);
		else if (max->median == 0)
			rrb(stack_b, 1);
		set_pos_and_median(*stack_b);
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*cheap;

	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	while (count_list(stack_a) > 0)
	{
		sort_h(&stack_a, &stack_b);
		cheap = find_cheapest_node(stack_a);
		if (cheap->median == 1 && cheap->target->median == 1)
			rotate_a_and_b(&stack_a, &stack_b, cheap);
		else if (cheap->median == 0 && cheap->target->median == 0)
			reverse_rotate_a_and_b(&stack_a, &stack_b, cheap);
		put_node_on_top_a(&stack_a, cheap);
		put_node_on_top_b(&stack_b, cheap);
		pb(&stack_a, &stack_b);
	}
	sort_max(&stack_b);
	while (stack_b != NULL)
		pa(&stack_b, &stack_a);
	free_linked_list(stack_a);
}
