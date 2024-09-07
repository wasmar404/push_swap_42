/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:43:46 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/07 18:44:37 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void rotate_a_and_b(t_stack **stack_a, t_stack **stack_b,t_stack *cheap)
{	
	while (cheap->position != 1 && cheap->target->position != 1)
	{
		rr(stack_a,stack_b);
    set_pos_and_median(*stack_a);
    set_pos_and_median(*stack_b);
	}
}
void reverse_rotate_a_and_b(t_stack **stack_a,t_stack **stack_b,t_stack *cheapest)
{
	while (cheapest->position != 1 && cheapest->target->position != 1)
	{
		rrr(stack_a,stack_b);
    set_pos_and_median(*stack_a);
    set_pos_and_median(*stack_b);
	}
}


 void put_node_on_top_a(t_stack **stack_a,t_stack *cheapest)
{
	while (cheapest ->position != 1)
	{
		if(cheapest->median == 1)
		{
			ra(stack_a,1);
		}
		else
			rra(stack_a,1);
        set_pos_and_median(*stack_a);

	}
}
 void put_node_on_top_b(t_stack **stack_b,t_stack *cheapest)
{
	while (cheapest ->target ->position != 1)
	{
		if(cheapest->target->median == 1)
		{
			 rb(stack_b,1);
          
		}
		else
			rrb(stack_b,1);
        set_pos_and_median(*stack_b);
	}        
}