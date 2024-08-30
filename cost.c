/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:29:45 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/30 06:17:14 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void find_cost(t_stack *head)
{
	int size_list;
	
	size_list= count_list(head);
	
	while (head != NULL)
	{
		if(head->median == 1 )
			head->cost = (head->position) - 1;
		else
			head->cost = size_list - (head->position)+1;
		head = head ->next;
	}
}

void add_cost_of_a_and_b(t_stack *stack_a, t_stack **stack_b)
{ t_stack *temp;
    while (stack_a != NULL)
    {
        temp = *stack_b;
        while (temp != NULL)
        {
            if (stack_a->target->number == temp->number)
            {
                stack_a->cost += temp->cost;
                break;  
            }
            temp = temp->next;
        }
        stack_a = stack_a->next;  
    }
}

t_stack *find_cheapest_node(t_stack *head)
{
    if (head == NULL) return NULL;  

    t_stack *cheapest = head;
    t_stack *current = head;

    while (current != NULL)
    {
        if (cheapest->cost > current->cost)
        {
            cheapest = current;
        }
        current = current->next;
    }
    return cheapest;
}