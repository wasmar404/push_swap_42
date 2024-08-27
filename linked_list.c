/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:05:23 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/27 09:42:59 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * Create a new node and return it.
 * Set the number to the value given as a parameter.
 * Set the prev and next pointers to NULL.
 */
t_stack *create_new_node(int number)
{
    t_stack *new_node;

    new_node = malloc(sizeof(t_stack));
    new_node ->number = number;
    new_node ->next = NULL;
    new_node ->prev = NULL;
}

/*
*/

void return_pointer_to_first(t_stack **node)
{
    while((*node)->prev != NULL)
    {
        (*node) = (*node)->prev;
    }
}

/*
*/
void free_linked_list(t_stack *node)
{
    t_stack *temp;

    while(node != NULL)
    {
        temp = node ->next;
        free(node);
        node = temp;
    }
}
/*
*/
void print_stack(t_stack *head)
{
    while(head != NULL)
    {
        printf("%d ", head->number);
            head = head ->next;  
    }
}

int count_list(t_stack *temp)
{   int i;
    i = 0;
    while(temp  != NULL)
    {   
        i++;
        temp = temp->next;
    }
    return(i);
}

