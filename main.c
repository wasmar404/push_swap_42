/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:04:33 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/05 11:51:24 by wasmar           ###   ########.fr       */
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
void sort_h(t_stack **stack_a, t_stack **stack_b)
{
            set_pos_and_median(*stack_a);
        set_pos_and_median(*stack_b);
        set_target_of_a(*stack_a,*stack_b);
        find_cost(*stack_a);
        find_cost(*stack_b);
        add_cost_of_a_and_b(*stack_a,stack_b);
}
void sort_max(t_stack **stack_b)
{
        t_stack *max = find_max_pointer(*stack_b);
    set_pos_and_median(*stack_b);
    while (max ->position != 1)
    {
        if(max ->median == 1)
            rb(stack_b,1);
        else if(max ->median == 0)
            rrb(stack_b,1);
        set_pos_and_median(*stack_b);
    }
}
void sort(t_stack *stack_a, t_stack *stack_b)
{
    pb(&stack_a,&stack_b);
    pb(&stack_a,&stack_b);
    while (count_list(stack_a) > 0)
    {
        sort_h(&stack_a,&stack_b);
        t_stack *cheap = find_cheapest_node(stack_a);
        if(cheap->median == 1 && cheap->target->median == 1) 
            rotate_a_and_b(&stack_a,&stack_b,cheap);
        else if(cheap->median == 0 && cheap->target->median == 0)
            reverse_rotate_a_and_b(&stack_a,&stack_b,cheap);
        put_node_on_top_a(&stack_a,cheap);
        put_node_on_top_b(&stack_b,cheap);
        pb(&stack_a,&stack_b);
    }
    sort_max(&stack_b);
    while (stack_b != NULL)
        pa(&stack_b,&stack_a);
    free_linked_list(stack_a);
}
bool  check_if_sorted(t_stack *head)
{
    while(head->next != NULL)
    {  
        if(head->number > head->next->number)
        {
            return(true);
        }
        head = head ->next;
    }
    return(false);
}
bool check_numeric(char **data,int flag);
bool split_argument(char *argv, t_input *input, int **data)
{
    char *charset = " \t\v";
    int i = 0;

    int error = 0;
    int ftatoi = 0;
    char **split = ft_split(argv, charset);
     if(split == NULL)
    {
        return(false);
    }
   bool errorr = check_numeric(split,0);
   i = 0;
   if(errorr == false)
   {
        for (int j = 0; split[j]; j++) // fix this
            free(split[j]);
        free(split);
    return false;
   }
    if (!split)
        return NULL;
    while (split[i])
        i++;
    *data = (int *)malloc(sizeof(int) * i);
    if (!data)
        return NULL;
    i = 0;
    while (split[i])
    {
        error = ft_atoi(split[i], &ftatoi);
        if(error == 0)
        {
                for (int j = 0; split[j]; j++) // fix this 
        free(split[j]);
    free(split);
    free(*data);
            return (false);
        }
        (*data)[i] = ftatoi;
        i++;
    }
    input->input_count = i;
        for (int j = 0; split[j]; j++) // fix this 
        free(split[j]);
    free(split);
    return (true);
}
bool check_dup(t_stack *head)
{
    t_stack *temp;
    while (head != NULL)
    {
        temp = head->next;
        while (temp != NULL)
        {
            if(temp->number == head->number)
            {
                return false;
            }
            temp = temp->next;
        }
        head = head->next;
    }
    return true;
}
bool check_numeric(char **data,int flag) {
    
    int i = 0;
    int j;
    if(flag == 1)
    {
        i =1;
    }
    while (data[i]) {
        j = 0;
        while (data[i][j]) {
            if(data[i][j] == '-' && j != 0)
                return false;
            if ((data[i][j] < '0' || data[i][j] > '9') && data[i][j] != '-'  && data[i][j] != ' ') {
                
                return(false);
            }
            j++;
        }
        i++;
    }
    return(true);
}
void one_argument_helper(t_input **input,  t_stack **stack_a,bool indicator,int **data)
{
    if(indicator == false)
    {
        free(*input);
        free(*data);
        free_linked_list(*stack_a);
        write(2,"Error\n",5);
        exit(0);
    }
}
void one_argument_helper1(t_input **input,  t_stack **stack_a,bool indicator,int **data)
{
    if(indicator == false)
    {
        free(*input);
        free(*data);
        free_linked_list(*stack_a);
        exit(0);
    }
}
void one_argument(char *argv,t_stack **stack_a)
{
    t_input *input;
    
    int *data ;
    bool error;
    error = true;
    input = malloc(sizeof(t_input));
    error = split_argument(argv,input,&data);
    if(error == false)
    {
        free(input);
        printf("Error1");
        exit(0);
    }
    (*stack_a) = create_list_a(data,input->input_count,0);
    int i = count_list(*stack_a);
    if(i == 1)
    {
        free(input);
        free(data);
        free_linked_list(*stack_a);
        exit(0);
    }
    one_argument_helper1(&input,stack_a,check_if_sorted(*stack_a),&data);
    
    one_argument_helper(&input,stack_a,check_dup(*stack_a),&data);
    free(data);
    free(input);
}
void many_arguments(t_stack **stack_a,char **argv,int argc)
{
    int *data;
    bool error;

    data = malloc((argc-1)*sizeof(int));
    error = create_array_with_input(argv,argc,&data);
        if(error == false)
        {
            free(data);
            write(2,"Error3",6);
            exit(0);
        }
    error = check_numeric(argv,1);
        if(error == false)
        {
            free(data);
            write(2,"Error3",6);
            exit(0);
        }
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
