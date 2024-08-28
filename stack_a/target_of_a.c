/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_of_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:06:42 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/27 10:13:51 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_stack *find_max_num_pointer(t_stack *head)
{
    t_stack *max = head;
    while(head != NULL)
    {
        if(head->number > max->number)
            max = head;
        head = head ->next;
    }
    return(max);
}
void set_target_of_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *new_b;
	new_b = stack_b;
	int i = 0;
	while (stack_a != NULL)
	{
		new_b = stack_b;
		i = 0;
		while (new_b != NULL)
		{
			if (i == 0 )
			{
				
				if (new_b-> number < stack_a->number)
				{
					stack_a->target = new_b;
					i++;
				}
			}
			else {
				if (new_b->number < stack_a->number && new_b->number > stack_a->target->number)
					stack_a->target = new_b;
				
			}
			new_b = new_b->next;	
		}
		if (i ==  0)
			 stack_a->target =   find_max_num_pointer(stack_b);
		stack_a = stack_a->next;
		
	}
}