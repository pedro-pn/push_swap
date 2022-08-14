/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:18:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/14 00:31:06 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Exit program and prints error message to STDOUT.*/
void	error_handle(int code)
{
	if (code != UNSARG)
		write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/* Checks if the array variable is properly allocated. If not, it frees the
memory to exit the program.*/
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
