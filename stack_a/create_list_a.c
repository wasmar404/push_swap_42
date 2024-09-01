/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:13:37 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/01 13:12:24 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_stack *create_list_a(long *input, int count)
{
    t_stack *first_node;
    t_stack *new_node;
    t_stack *head;
    
    int i = 1;
    first_node = create_new_node(input[0]);
    head = first_node;
    while (i < count-1)
    {
        new_node = create_new_node(input[i]);
        head ->next = new_node;
        new_node ->prev = head;
        head = head ->next;
        i++;
    }
    return_pointer_to_first(&head);
    return (head);
}
