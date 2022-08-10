/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:34:29 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/09 21:53:16 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_split_stack(t_list **stack_a, t_list **stack_b, int *array, int len);
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
	rev_sort_chunk(stack_a, stack_b, len, push_count);
}

void	chunck_a(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int	push_count;
	int	*array_b;
	int	*array_a;
	
	array_a = NULL;
	array_b = NULL;
	push_count = mid_point_2(stack_a, stack_b, array, len);
	array_a = sort_array(*stack_a, len - push_count);
	if (len - push_count > 2)
		chunck_a(stack_a, stack_b, array_a, len - push_count);
	if (len - push_count == 2)
	{
		if (*((int *)(*stack_a)->content) > *((int *)(*stack_a)->next->content))
			swap(stack_a, "sa");
	}
	array_b = sort_array(*stack_b, push_count);
	rev_split_stack(stack_a, stack_b, array_b, push_count);
	if (array_a)
		free(array_a);
	if (array_b)
		free(array_b);
	array_a = NULL;
	array_b = NULL;
}

int	check_stack(t_list *stack, int middle)
{
	while (stack != NULL)
	{
		if (*((int *)stack->content) < middle)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	rev_check_stack(t_list *stack, int middle)
{
		while (stack != NULL)
	{
		if (*((int *)stack->content) > middle)
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
	while (check_stack(*stack_a, middle))
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