/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:13:37 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/07 19:02:44 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_stack	*create_list_a(int *input, int count, int flag)
{
	t_stack	*first_node;
	t_stack	*new_node;
	t_stack	*head;
	int		i;

	i = 1;
	first_node = create_new_node(input[0]);
	head = first_node;
	if (flag == 1)
		count = count - 1;
	while (i < count)
	{
		new_node = create_new_node(input[i]);
		head->next = new_node;
		new_node->prev = head;
		head = head->next;
		i++;
	}
	return_pointer_to_first(&head);
	return (head);
}
