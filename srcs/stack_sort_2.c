/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:11:05 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/09 21:48:25 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_chunk(t_list **stack_a, t_list **stack_b, int len)
{
	int	*array;
	int	*array_b;

	array = NULL;
	array_b = NULL;
	if (len > 1)
	{
		array = sort_array(*stack_a, ft_lstsize(*stack_a));
		array_b = sort_array(*stack_b, len);
		split_stack(stack_a, stack_b, array, ft_lstsize(*stack_a));
		rev_split_stack(stack_a, stack_b, array_b, len);
		free(array_b);
	}
	else
	{
		if (ft_lstsize(*stack_a) == 2)
		{
			if (*((int *)(*stack_a)->content)
				> *((int *)(*stack_a)->next->content))
				swap(stack_a, "sa");
		}
		push(stack_a, stack_b, "pa");
	}
}

void	rev_sort_chunk(t_list **stack_a, t_list **stack_b, int len, int count)
{
	int *array_a;
	int	*array_b;
	
	array_a = sort_array(*stack_a, count);
	array_b = sort_array(*stack_b, len - count);
	if (count > 2)
		chunck_a(stack_a, stack_b, array_a, count);
	else if (count == 2)
	{
		if (*((int *)(*stack_a)->content) > *((int *)(*stack_a)->next->content))
			swap(stack_a, "sa");
	}
	if (len - count >= 2)
		rev_split_stack(stack_a, stack_b, array_b, len - count);
	if (array_a)
		free(array_a);
	if (array_b)
		free(array_b);
}

int	rev_len_checker(t_list **stack_a, t_list **stack_b, int len)
{
	if (len == 1)
	{
		push(stack_a, stack_b, "pa");
		if (*((int *)(*stack_a)->content) > *((int *)(*stack_a)->next->content))
			swap(stack_a, "sa");
		return (1);
	}
	if (len == 2)
	{
		if (*((int *)(*stack_b)->content) < *((int *)(*stack_b)->next->content))
			swap(stack_b, "sb");
		push(stack_a, stack_b, "pa");
		push(stack_a, stack_b, "pa");
		return (1);
	}
	return (0);
}

int	rev_mid_point(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int	middle;
	int	push_count;
	int	rb_count;

	middle = array[len / 2];
	rb_count = 0;
	push_count = 0;
	while (rev_check_stack(*stack_b, middle))
	{
		if (*((int *)(*stack_b)->content) > middle)
		{
			push(stack_a, stack_b, "pa");
			push_count++;
		}
		else
		{
			rotate(stack_b, "rb");
			rb_count++;
		}
	}
	restore_stack(stack_b, rb_count, "rrb");
	return (push_count);
}

void	restore_stack(t_list **stack, int count, char *rule)
{
	while (count > 0)
	{
		reverse_rotate(stack, rule);
		count--;
	}
}
