/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:04:33 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/07 18:54:33 by wasmar           ###   ########.fr       */
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
    t_stack *stack_a;
    t_stack *stack_b = NULL;
    if(argc != 1)
    {
    if(argc == 2)
        one_argument(argv[1],&stack_a);  
    else if( argc >2)
        many_arguments(&stack_a,argv,argc);
     sort(stack_a,stack_b);
    }
    else
    {
        exit(0);
    }
}
