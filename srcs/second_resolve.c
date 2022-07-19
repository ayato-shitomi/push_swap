/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_resolve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:57:37 by ashitomi          #+#    #+#             */
/*   Updated: 2022/07/19 11:39:36 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
static void	put(t_program *prg)
{
	int	m = 0;
	char *str;
	write(1, "debug :", ft_strlen("debug :"));
	while (m < (int)prg->stack_a.size)
	{
		str = ft_itoa(prg->stack_a.array[m]);
		write(1, str, ft_strlen(str));
		write(1, " ", 1);
		free(str);
		m++;
	}
	write(1, "\n\n", 2);
}
*/

static void	print_bublesort(int n, t_program *prg)
{
	int	i;
	int	count;

	if (n != 0)
	{
		i = 0;
		while (i < n)
			i = print_pb_rb_with_num(i);
	}
	write(1, "sa\n", 3);
	i = 0;
	count = (int)prg->stack_a.size;
	while (i < count - n + 1)
	{
		if (i != 0)
			print_pbrb();
		i++;
	}
	i = 0;
	while (i < count)
		i = print_pa_ra_with_num(i);
}

int	second_resolve(t_program *prg)
{
	int	n;
	int	tmp;

	prg->instr = NULL;
	while (is_stack_ordered(&prg->stack_a, ZERO) == 1)
	{
		n = 0;
		while (n < (int)prg->stack_a.max_size - 1)
		{
			if (prg->stack_a.array[n] > prg->stack_a.array[n + 1])
			{
				tmp = prg->stack_a.array[n];
				prg->stack_a.array[n] = prg->stack_a.array[n + 1];
				prg->stack_a.array[n + 1] = tmp;
				print_bublesort(n, prg);
			}
			n++;
		}
	}
	return (0);
}

int	print_ins_and_some(t_program *prg, int debug)
{
	print_instructions(prg->instr);
	print_some(debug);
	return (0);
}

void	print_ins_and_some_and_free(t_program *prg, int debug)
{
	(void)debug;
	free_prg(prg);
}

int	instr_null(t_program *prg)
{
	prg->instr = NULL;
	return (0);
}
