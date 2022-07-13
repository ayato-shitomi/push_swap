/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/05/21 20:23:51 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	counting stack size
*/

size_t	count_stack_size(int argc, char *argv[])
{
	size_t	size;
	size_t	i;
	size_t	j;

	size = 0;
	i = 0;
	j = 0;
	while (i < (size_t)argc - 1)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((j == 0 || argv[i][j - 1] == ' ') && argv[i][j] != ' ')
				size++;
			j++;
		}
		i++;
	}
	return (size);
}

/*
	check if stack is ordered
	order ZERO means normal order
	order ONE means reverse order
*/

int	is_stack_ordered(t_stack *stack, int order)
{
	size_t	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (order == ZERO && stack->array[i] >= stack->array[i + 1])
			return (1);
		else if (order == ONE && stack->array[i] <= stack->array[i + 1])
			return (1);
		i++;
	}
	return (0);
}
