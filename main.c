/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:04:33 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/30 07:36:05 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void set_pos_and_median(t_stack *head)
{
	int i = 1;
	int list_size = count_list(head);
    if(list_size % 2 != 0)
    {
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
    else
    {
        	while(head != NULL)
	{
		head->position= i;
		if( i <= list_size/2)
			head->median = 1;
		else
			head->median = 0;
		head = head->next;
		i++;
	}
    }
}
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
    // int x = count_list(*stack_b);
    // if(x % 2 != 0)
    // {
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
    // }
    // else{
	// while (cheapest ->target ->position != 1)
	// {
	// 	if(cheapest ->target ->position <= x/2)
	// 	{
	// 		rb(stack_b,1);
	// 	}
	// 	else
	// 		rrb(stack_b,1);
    //     set_pos_and_median(*stack_b);
	// }

        
    }

	

t_stack *find_max_pointer(t_stack *head)
{
    t_stack *max = head;
    while(head != NULL)
    {
        if(max->number < head ->number)
            max = head;
        head = head->next;
    }
    return(max);
}

int main(int argc, char **argv)
{
    int *data = create_array_with_input(argv,argc);
    t_stack *stack_a =  create_list_a(data,argc);
    t_stack *stack_b = NULL;
    pb(&stack_a,&stack_b);
    pb(&stack_a,&stack_b);
    //pb(&stack_a,&stack_b);
    // pb(&stack_a,&stack_b);
        //     set_pos_and_median(stack_a);
        // set_pos_and_median(stack_b);
        // set_target_of_a(stack_a,stack_b);
        // find_cost(stack_a);
        // find_cost(stack_b);
        //  add_cost_of_a_and_b(stack_a,&stack_b);
        //print_stack(stack_b);
        // while(stack_a)
        // {
        //     printf("%d",stack_a->cost);
        //     stack_a= stack_a ->next;
        // }
   // int count = count_list(stack_a);
    while (count_list(stack_a) > 0)
    {
        set_pos_and_median(stack_a);
        set_pos_and_median(stack_b);
        set_target_of_a(stack_a,stack_b);
        find_cost(stack_a);
        find_cost(stack_b);
        add_cost_of_a_and_b(stack_a,&stack_b);
        t_stack *cheap = find_cheapest_node(stack_a);
        if(cheap->median == 1 && cheap->target->median == 1)
        {  
            rotate_a_and_b(&stack_a,&stack_b,cheap);
        }
        else if(cheap->median == 0 && cheap->target->median == 0)
        {
            reverse_rotate_a_and_b(&stack_a,&stack_b,cheap);
        }
        // else if (cheap->median == 0 && cheap->target->median == 1)
        // {
        //     rra(&stack_a, 1);
        //     rb(&stack_b, 1);
        // }
        // else
        // {
        //     ra(&stack_a, 1);
        //     rrb(&stack_b, 1);
        // }
        // printf("%d this is the median and the number %d \n",cheap->median,stack_b)
        put_node_on_top_a(&stack_a,cheap);
        // printf("%d is the cheapest's target", cheap->target->number);
        put_node_on_top_b(&stack_b,cheap);
        pb(&stack_a,&stack_b);
    }
    t_stack *max = find_max_pointer(stack_b);
    set_pos_and_median(stack_b);
    while (max ->position != 1)
    {
        if(max ->median == 1)
            rb(&stack_b,1);
        else if(max ->median == 0)
            rrb(&stack_b,1);
        set_pos_and_median(stack_b);

    }
    while (stack_b != NULL)
    {
        pa(&stack_b,&stack_a);
    }
    
//    print_stack(stack_a);
    free_linked_list(stack_a);
   free(data);
}
