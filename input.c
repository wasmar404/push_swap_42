/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:24:42 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/01 13:16:50 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long *create_array_with_input(char **input,int count)
{
    long *data;
    int i = 0;
    int j = 1;
    data = malloc((count-1)*sizeof(long));
    
    while (i < count -1)
    {
        data[i] = ft_atoi(input[j]);
        i++;
        j++;
    }
    return (data);
}