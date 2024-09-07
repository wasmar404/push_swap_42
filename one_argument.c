/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:54:10 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/07 16:15:39 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void free_2d_array(char **data);
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
        free_2d_array(split);
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
                free_2d_array(split);
    free(*data);
            return (false);
        }
        (*data)[i] = ftatoi;
        i++;
    }
    input->input_count = i;
    free_2d_array(split);
    return (true);
}
void free_2d_array(char **data)
{
    int i;
    i = 0;
    while(data[i])
    {
        free(data[i]);
        i++;
    }
    free(data);
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
