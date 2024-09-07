/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:04:33 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/07 18:50:29 by wasmar           ###   ########.fr       */
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




void many_args_error(int *data,bool error)
{
        if(error == false)
        {
            free(data);
            write(2,"Error3",6);
            exit(0);
        } 
}
void many_arguments(t_stack **stack_a,char **argv,int argc)
{
    int *data;
    bool error;

    data = malloc((argc-1)*sizeof(int));
    many_args_error(data,create_array_with_input(argv,argc,&data));
    many_args_error(data,check_numeric(argv,1));
     (*stack_a) =  create_list_a(data,argc,1);
       bool error2 = true; 
         error2 = check_if_sorted(*stack_a);
        if(error2 == false)
        {
            free(data);
             free_linked_list(*stack_a);
            exit(0);
        }
               bool error1 = check_dup (*stack_a);
        if(error1 == false)
        {
            free(data);
            free_linked_list(*stack_a);
            write(2,"Error2",6);
            exit(0);
        }
        free(data);
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
