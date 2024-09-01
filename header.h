/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:04:37 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/01 13:13:31 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
typedef struct t_stack
{
    int number;
    int median;
    int cost;
    int position;
    struct t_stack *next;
    struct t_stack *prev;
    struct t_stack *target;
}t_stack;

//t_stack
t_stack *create_new_node(int number);
t_stack *create_list_a(long *input, int count);
void add_cost_of_a_and_b(t_stack *stack_a, t_stack **stack_b);
int count_list(t_stack *temp);
///////////////////////////////
void find_cost(t_stack *head);
//voidlinked_list.c
void set_target_of_a(t_stack *stack_a, t_stack *stack_b);
void free_linked_list(t_stack *node);
void return_pointer_to_first(t_stack **node);
void print_stack(t_stack *head);

void swap(t_stack **head);
void rotate(t_stack **head);
void reverse_rotate(t_stack **head);
void push(t_stack **send_form , t_stack **send_to);
/////////////////////
t_stack *find_cheapest_node(t_stack *head);
//int

long *create_array_with_input(char **input,int count);
long	ft_atoi(char *nptr);
///////////////////////

void sa(t_stack **head,int flag);
void pa(t_stack **head_a, t_stack **head_b);
void ra(t_stack **head,int flag);
void rra(t_stack **head,int flag);
void rrb(t_stack **head,int flag);
void rb(t_stack **head,int flag);
void sb(t_stack **head,int flag);
void pb(t_stack **head_a, t_stack **head_b);
void rr(t_stack **head_a, t_stack **head_b);
void rrr(t_stack **head_a,t_stack **head_b);
#endif