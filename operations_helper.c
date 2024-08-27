/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:36:27 by schaaban          #+#    #+#             */
/*   Updated: 2024/08/27 09:42:56 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void swap(t_stack **head)
{
    t_stack *temp;
    t_stack *temp1;
    temp = (*head);
    temp = temp -> next;
     temp1 = (*head) -> next -> next;
    (*head) -> next = temp -> next;
    temp -> next = (*head);
    (*head) -> prev = temp;
    temp1 -> prev = (*head);
    temp -> prev = NULL;
    (*head) = temp;
}
void rotate(t_stack **head)
{
    t_stack *temp;
    t_stack *temp1;
    temp1 = (*head) -> next;
    temp = *head;
    while((*head) -> next != NULL)
    {
        (*head) = (*head) -> next;
    }
    (*head) -> next = temp;
    temp -> prev = (*head);
    temp -> next = NULL;
    temp1 -> prev = NULL;
    (*head) = temp1;
    temp1 = NULL;
}
void reverse_rotate(t_stack **head)
{
    t_stack *first_node = (*head);
    t_stack *new_last = (*head);
    while (new_last ->next != NULL)
    {
        new_last = new_last ->next;
    }
    new_last = new_last ->prev;
    while((*head) ->next != NULL)
    {
        (*head) = (*head)->next;
    }
    (*head)->next=first_node;
    first_node->prev=(*head);
    (*head)->prev=NULL;
    new_last ->next =NULL;
}


void push(t_stack **send_form , t_stack **send_to)
{
t_stack *temp;
    temp = (*send_form);
    if((*send_form) == NULL)
        return ;
    (*send_form) = (*send_form) -> next;
    (*send_form) -> prev = NULL;
    temp->next = *send_to;
    temp -> prev = NULL;
    (*send_form) = temp;
}


