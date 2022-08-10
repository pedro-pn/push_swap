/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:34:29 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/10 11:34:56 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int mid_point(t_list **stack_a, t_list **stack_b, int *array, int len);

void split_stack(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int	middle;
	int	push_count;

	middle = array[len / 2];
	push_count = mid_point(stack_a, stack_b, array, len);
	free(array);
	array = NULL;
	sort_chunk(stack_a, stack_b, push_count);
}

void	rev_split_stack(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int	push_count;
	int	*array_a;
	int	*array_b;

	array_a = NULL;
	array_b = NULL;
	if (rev_len_checker(stack_a, stack_b, len))
		return ;
	push_count = rev_mid_point(stack_a, stack_b, array, len);
	sort_chunk_2(stack_a, stack_b, push_count, len - push_count);
}

void	chunck_a(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int	push_count;

	push_count = mid_point_2(stack_a, stack_b, array, len);
	sort_chunk_2(stack_a, stack_b, len - push_count, push_count);
}

int	check_stack(t_list *stack, int middle, int op)
{
	while (stack != NULL)
	{
		if (*((int *)stack->content) < middle && op == LESS)
			return (1);
		if (*((int *)stack->content) > middle && op == GREATER)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int mid_point(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int	push_count;
	int	middle;

	push_count = 0;
	middle = array[len / 2];
	while (check_stack(*stack_a, middle, LESS))
	{
		if (*((int *)(*stack_a)->content) < middle)
		{
			push(stack_b, stack_a, "pb");
			push_count++;
		}
		else
			rotate(stack_a, "ra");
	}
	return (push_count);
}