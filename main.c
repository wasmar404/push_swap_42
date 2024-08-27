/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:04:33 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/27 09:57:58 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
int main(int argc, char **argv)
{
    int *data = create_array_with_input(argv,argc);
    t_stack *stack_a =  create_list_a(data,argc);


   
   free_linked_list(stack_a);
   free(data);
}