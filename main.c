/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:04:33 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/28 09:09:38 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void set_pos_and_median(t_stack *head)
{
	int i = 1;
	int list_size = count_list(head);
	while(head != NULL)
	{
		head->position= i;
		if( i <= list_size/2+1)
			head->median = 1;
		else
			head->median = 0;
		head = head->next;
		i++;
	}
}
int main(int argc, char **argv)
{
    int *data = create_array_with_input(argv,argc);
    t_stack *stack_a =  create_list_a(data,argc);
    t_stack *stack_b = NULL;
    pb(&stack_a,&stack_b);
    pb(&stack_a,&stack_b);
    set_pos_and_median(stack_a);
    set_pos_and_median(stack_b);
    set_target_of_a(stack_a,stack_b);
    find_cost(stack_a);
    find_cost(stack_b);
    add_cost_of_a_and_b(stack_a,stack_b);

    // while (stack_a != NULL)
    // {
    //     printf("%d ",stack_a->cost);
    //     stack_a = stack_a ->next;
    // }
    
 

   free_linked_list(stack_a);
   free(data);
}