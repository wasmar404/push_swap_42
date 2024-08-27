/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:24:42 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/26 15:38:52 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int *create_array_with_input(char **input,int count)
{
    int *data;
    int i = 0;
    int j = 1;
    data = malloc((count-1)*sizeof(int));
    
    while (i < count -1)
    {
        data[i] = ft_atoi(input[j]);
        i++;
        j++;
    }
    return (data);
}