/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:43:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/14 00:58:04 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Applies midpoint algorithm in the chunks of stack_a without losing the start
configuration.*/
int	mid_point_2(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int	middle;
	int	push_count;
	int	ra_count;

	ra_count = 0;
	middle = array[len / 2];
	push_count = 0;
	while (check_stack(*stack_a, middle, LESS))
	{
		if (*((int *)(*stack_a)->content) < middle)
		{
			push(stack_b, stack_a, "pb");
			push_count++;
		}
		else if (*((int *)ft_lstlast(*stack_a)->content) < middle)
			reverse_rotate(stack_a, "rra");
		else
		{
			rotate(stack_a, "ra");
			ra_count++;
		}
	}
	restore_stack(stack_a, ra_count, "rra");
	return (push_count);
}

/* Checks if the stack_a is all sorted.*/
int	is_sorted(t_list *stack_a, t_list *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a->next)
	{
		if (*(int *)stack_a->content > *(int *)stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

/* Sorts last three or less elements of stack_a.*/
int	check_len(t_list **stack_a, int len)
{
	if (len > 3)
		return (0);
	while (!is_sorted(*stack_a, NULL))
	{
		if (*((int *)(*stack_a)->content)
			> *((int *)(*stack_a)->next->content))
			swap(stack_a, "sa");
		else
			reverse_rotate(stack_a, "rra");
	}
	return (1);
}
