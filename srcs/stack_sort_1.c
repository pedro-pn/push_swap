/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:34:29 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/08 14:48:23 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_stack(t_list *stack, int middle);

void split_stack(t_list **stack_a, t_list **stack_b, int *array, int argc)
{
	int	middle;

	middle = array[(argc - 1) / 2];
	while (check_stack(*stack_a, middle))
	{
		if (*((int *)(*stack_a)->content) < middle)
			push(stack_b, stack_a, "pb");
		else
			rotate(stack_a, "ra");
	}
}

static int	check_stack(t_list *stack, int middle)
{
	while (stack != NULL)
	{
		if (*((int *)stack->content) < middle)
			return (1);
		stack = stack->next;
	}
	return (0);
}
