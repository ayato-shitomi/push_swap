/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/05/21 20:23:51 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_header(void)
{
	ft_putstr_fd(" ________  ___  ___  ________  ___  ___  ", 1);
	ft_putstr_fd("________  ___       __   ________  ________   \n", 1);
	ft_putstr_fd("|\\   __  \\|\\  \\|\\  \\|\\   ____\\|\\  \\|\\  ", 1);
	ft_putstr_fd("\\|\\   ____\\|\\  \\     |\\  \\|\\   __  \\|\\   __  \\  \n", 1);
	ft_putstr_fd("\\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\___|\\ \\  \\\\\\  ", 1);
	ft_putstr_fd("\\ \\  \\___|\\ \\  \\    \\ \\  \\ \\  \\|\\  \\ \\  \\|\\  \\ \n", 1);
	ft_putstr_fd(" \\ \\   ____\\ \\  \\\\\\  \\ \\_____  \\ \\   __  \\ \\_____  \\ ", 1);
	ft_putstr_fd("\\  \\  __\\ \\  \\ \\   __  \\ \\   ____\\\n", 1);
	ft_putstr_fd("  \\ \\  \\___|\\ \\  \\\\\\  \\|____|\\  \\ \\  \\ \\  \\|____|\\ ", 1);
	ft_putstr_fd(" \\ \\  \\|\\__\\_\\  \\ \\  \\ \\  \\ \\  \\___|\n", 1);
	ft_putstr_fd("   \\ \\__\\    \\ \\_______\\____\\_\\  \\ \\__\\ \\__", 1);
	ft_putstr_fd("\\____\\_\\  \\ \\____________\\ \\__\\ \\__\\ \\__\\   \n", 1);
	ft_putstr_fd("    \\|__|     \\|_______|\\_________\\|__|\\|__|\\_______", 1);
	ft_putstr_fd("__\\|____________|\\|__|\\|__|\\|__|   \n", 1);
	ft_putstr_fd("                       \\|_________|        \\|_", 1);
	ft_putstr_fd("________|                                \n", 1);
}

int	usage(void)
{
	ft_putstr_fd("Error\n", 1);
	print_header();
	ft_putstr_fd("Usage:\n", 1);
	ft_putstr_fd("	./push_swap <numbers which you want to sort>\n", 1);
	return (0);
}

int	ft_put_err_return_one(void)
{
	ft_putstr_fd("Error\n", 1);
	return (1);
}

void	print_instruction(t_instruction *instr)
{
	write(1, instr->line, ft_strlen(instr->line));
	write(1, "\n", 1);
}

void	print_instructions(t_instruction *instr)
{
	while (instr)
	{
		print_instruction(instr);
		instr = instr->next;
	}
}
