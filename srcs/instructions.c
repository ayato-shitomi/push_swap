/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/05/21 20:23:51 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_add_instruction(t_instruction *tmp,
	t_instruction *new, t_instruction **instructions)
{
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (tmp)
	{
		new->prev = tmp;
		tmp->next = new;
	}
	else
		*instructions = new;
}

t_instruction	*add_instruction(t_instruction **instructions, char *line)
{
	t_instruction	*tmp;
	t_instruction	*new;

	new = malloc(sizeof(t_instruction));
	if (!new)
		return (NULL);
	new->line = ft_strdup(line);
	if (!new->line)
	{
		free(new);
		return (NULL);
	}
	new->prev = NULL;
	new->next = NULL;
	tmp = *instructions;
	do_add_instruction(tmp, new, instructions);
	return (new);
}

/* do_add_instruction
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (tmp)
	{
		new->prev = tmp;
		tmp->next = new;
	}
	else
		*instructions = new;
*/

t_instruction	*add_n_instructions(t_instruction **instructions,
	char *line, size_t n)
{
	t_instruction	*start;

	start = NULL;
	if (n > 0)
	{
		start = add_instruction(instructions, line);
		if (!start)
			return (NULL);
		n--;
		while (n > 0)
		{
			if (!(add_instruction(instructions, line)))
			{
				free_instructions(start);
				return (NULL);
			}
			n--;
		}
	}
	return (start);
}

t_instruction	*copy_instructions(t_instruction *instructions)
{
	t_instruction	*new;

	new = NULL;
	while (instructions)
	{
		if (!(add_instruction(&new, instructions->line)))
		{
			free_instructions(new);
			return (NULL);
		}
		instructions = instructions->next;
	}
	return (new);
}

size_t	count_instructions(t_instruction *instr)
{
	size_t	nb;

	nb = 0;
	while (instr)
	{
		nb++;
		instr = instr->next;
	}
	return (nb);
}
