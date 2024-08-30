/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:40:07 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/30 05:23:54 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void sa(t_stack **head,int flag)
{
    swap(head);
    if(flag == 1)
        write(1,"sa\n",3);
}
void pa(t_stack **head_a, t_stack **head_b)
{
    push(head_a,head_b);
    write(1,"pa\n",3);
}
void ra(t_stack **head,int flag)
{
    rotate(head);
    if(flag == 1)
        write(1,"ra\n",3);
}
void rra(t_stack **head,int flag)
{
    reverse_rotate(head);
    if(flag == 1)
        write(1,"rra\n",4);
}
