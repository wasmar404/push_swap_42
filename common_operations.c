/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:53:31 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/07 19:05:01 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rrr(t_stack **head_a, t_stack **head_b)
{
	rra(head_a, 0);
	rrb(head_b, 0);
	write(1, "rrr\n", 4);
}

void	rr(t_stack **head_a, t_stack **head_b)
{
	ra(head_a, 0);
	rb(head_b, 0);
	write(1, "rr\n", 3);
}
