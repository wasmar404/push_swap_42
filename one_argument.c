/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:54:10 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/07 18:20:10 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
bool split_argument_helper(char *argv,char ***split)
{
        char *charset;
        charset = " \t\v";
        (*split) = ft_split(argv, charset);
        if(split == NULL)
         return(false);
     bool errorr = check_numeric(*split,0);
   if(errorr == false)
   {
        free_2d_array(*split);
    return false;
   }

return true;
}
int count_input(char **data)
{
    int i;
    i = 0;
    while (data[i])
    {
        i++;
    }
    return i;
    
}
bool split_argument_helper_1(char **split,int **data)
{
    int i = 0;
    int error = 0;
    int ftatoi = 0;
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
    return true;  
}
bool split_argument(char *argv, t_input *input, int **data)
{
    int i;
    int error = 0;
    int ftatoi = 0;
    char **split;
    if(split_argument_helper(argv,&split) == false)
        return (false);
    *data = (int *)malloc(sizeof(int) * (count_input(split)));
    if (!data)
        return NULL;
    i = 0;
    if(!split_argument_helper_1(split,data))
        return false;
    input->input_count = i;
    free_2d_array(split);
    return (true);
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
