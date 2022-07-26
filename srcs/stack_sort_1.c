/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:34:29 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/14 23:34:26 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mid_point(t_list **stack_a, t_list **stack_b, int *array, int len);

/* Starts the sorting applying midpoint algorithm in the numbers in the stack_a
passing them to the stack_b.*/
void	sort_stack(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int	push_count;

	if (check_error(stack_a, stack_b, array) || is_sorted(*stack_a, *stack_b))
	{
		if (array)
			free(array);
		return ;
	}
	if (check_len(stack_a, len))
	{
		if (array)
			free(array);
		return ;
	}
	push_count = mid_point(stack_a, stack_b, array, len);
	free(array);
	array = NULL;
	sort_chunk(stack_a, stack_b, push_count);
}

/* Passes the numbers from the stack_b to the stack_a recursively using the
midpoint algorithm*/
void	r_sort_stack(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int	push_count;

	if (check_error(stack_a, stack_b, array))
		return ;
	if (r_len_checker(stack_a, stack_b, len))
		return ;
	push_count = r_mid_point(stack_a, stack_b, array, len);
	sort_chunk_2(stack_a, stack_b, push_count, len - push_count);
}

/* Applies the midpoint algorithm recursively in the numbers in the stack_a*/
void	sort_chunk_a(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int	push_count;

	if (check_error(stack_a, stack_b, array))
		return ;
	push_count = mid_point_2(stack_a, stack_b, array, len);
	sort_chunk_2(stack_a, stack_b, len - push_count, push_count);
}

/* Verifies if there're still numbers less or greater than the middle value in
the stack.*/
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

/* Passes all values less than the middle value of the stack_a to the stack_b*/
static int	mid_point(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int		push_count;
	int		middle;

	push_count = 0;
	middle = array[len / 2];
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
			rotate(stack_a, "ra");
	}
	return (push_count);
}
