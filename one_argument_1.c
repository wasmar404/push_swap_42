/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_argument_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:05:44 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/07 18:19:28 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"
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