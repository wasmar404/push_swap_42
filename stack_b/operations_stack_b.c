/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:40:07 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/07 19:15:58 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	pb(t_stack **head_a, t_stack **head_b)
{
	push(head_a, head_b);
	write(1, "pb\n", 3);
}

void	sb(t_stack **head, int flag)
{
	swap(head);
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	rb(t_stack **head, int flag)
{
	rotate(head);
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rrb(t_stack **head, int flag)
{
	reverse_rotate(head);
	if (flag == 1)
		write(1, "rrb\n", 4);
}
