/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:36:27 by schaaban          #+#    #+#             */
/*   Updated: 2024/09/13 11:01:34 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(t_stack **head)
{
	t_stack	*temp;
	t_stack	*temp1;

	temp = (*head);
	temp = temp->next;
	temp1 = (*head)->next->next;
	(*head)->next = temp->next;
	temp->next = (*head);
	(*head)->prev = temp;
	temp1->prev = (*head);
	temp->prev = NULL;
	(*head) = temp;
}

void	rotate(t_stack **head)
{
	t_stack	*temp;
	t_stack	*temp1;

	temp1 = (*head)->next;
	temp = *head;
	while ((*head)->next != NULL)
	{
		(*head) = (*head)->next;
	}
	(*head)->next = temp;
	temp->prev = (*head);
	temp->next = NULL;
	temp1->prev = NULL;
	(*head) = temp1;
	temp1 = NULL;
}

void	reverse_rotate(t_stack **head)
{
	t_stack	*first_node;
	t_stack	*new_last;

	first_node = (*head);
	new_last = (*head);
	while (new_last->next != NULL)
	{
		new_last = new_last->next;
	}
	new_last = new_last->prev;
	while ((*head)->next != NULL)
	{
		(*head) = (*head)->next;
	}
	(*head)->next = first_node;
	first_node->prev = (*head);
	(*head)->prev = NULL;
	new_last->next = NULL;
}

void	push(t_stack **send_form, t_stack **send_to)
{
	t_stack	*temp;

	if (*send_form == NULL)
		return ;
	temp = *send_form;
	*send_form = (*send_form)->next;
	if (*send_form != NULL)
	{
		(*send_form)->prev = NULL;
	}
	temp->next = *send_to;
	temp->prev = NULL;
	if (*send_to != NULL)
	{
		(*send_to)->prev = temp;
	}
	*send_to = temp;
}
