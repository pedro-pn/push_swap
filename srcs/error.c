/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:18:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/10 17:26:48 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handle(int code)
{
	if (code != UNSARG)
		write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	check_error(t_list **stack_a, t_list **stack_b, int *array)
{
	if (array && *stack_a)
		return (0);
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	stack_a = NULL;
	stack_b = NULL;
	return (1);
}
