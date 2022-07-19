/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_resolve_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:39:36 by ashitomi          #+#    #+#             */
/*   Updated: 2022/07/19 11:39:36 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_pbrb(void)
{
	write(1, "pb\n", 3);
	write(1, "rb\n", 3);
}

int	print_pb_rb_with_num(int i)
{
	write(1, "pb\n", 3);
	if (i != 0)
		write(1, "rb\n", 3);
	return (i + 1);
}

int	print_pa_ra_with_num(int i)
{
	write(1, "pa\n", 3);
	if (i != 0)
		write(1, "ra\n", 3);
	return (i + 1);
}
