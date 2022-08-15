/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:11:05 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/14 23:36:11 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Applies the sorting algorithm in the leftover values of stack_a and calls
the reverse sorting algorithm to the numbers passed to stack_b.*/ 
void	sort_chunk(t_list **stack_a, t_list **stack_b, int len)
{
	int	*chunk_a;
	int	*chunk_b;

	chunk_a = NULL;
	chunk_b = NULL;
	if (len > 1)
	{
		chunk_a = sort_array(*stack_a, ft_lstsize(*stack_a));
		chunk_b = sort_array(*stack_b, len);
		sort_stack(stack_a, stack_b, chunk_a, ft_lstsize(*stack_a));
		r_sort_stack(stack_a, stack_b, chunk_b, len);
		if (chunk_b)
			free(chunk_b);
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

/* Applies the sorting algorithm in the leftover values of stack_a/b and calls
the sorting algorithm to the numbers passed to stack_b/a.*/ 
void	sort_chunk_2(t_list **stack_a, t_list **stack_b, int rest, int count)
{
	int	*chunk_a;
	int	*chunk_b;

	chunk_a = sort_array(*stack_a, rest);
	chunk_b = sort_array(*stack_b, count);
	if (rest > 2)
		sort_chunk_a(stack_a, stack_b, chunk_a, rest);
	if (rest == 2)
	{
		if (*((int *)(*stack_a)->content) > *((int *)(*stack_a)->next->content))
			swap(stack_a, "sa");
	}
	r_sort_stack(stack_a, stack_b, chunk_b, count);
	if (chunk_a)
		free(chunk_a);
	if (chunk_b)
		free(chunk_b);
}

/* Checks if the total numbers to apply midpoint algorithm is less than 3. If so
sort them and returns 1, sinalizing to rev_sort_stack that midpoint is not
necessary*/
int	r_len_checker(t_list **stack_a, t_list **stack_b, int len)
{
	if (len == 1)
	{
		push(stack_a, stack_b, "pa");
		if (*((int *)(*stack_a)->content) > *((int *)(*stack_a)->next->content))
			swap(stack_a, "sa");
		return (1);
	}
	else if (len == 2)
	{
		if (*((int *)(*stack_b)->content) < *((int *)(*stack_b)->next->content))
			swap(stack_b, "sb");
		push(stack_a, stack_b, "pa");
		push(stack_a, stack_b, "pa");
		return (1);
	}
	return (0);
}

/* Applies midpoint algorithm in the chunks of stack_b without losing the start
configuration.*/
int	r_mid_point(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int	middle;
	int	push_count;
	int	rb_count;

	middle = array[len / 2];
	rb_count = 0;
	push_count = 0;
	while (check_stack(*stack_b, middle, GREATER))
	{
		if (*((int *)(*stack_b)->content) > middle)
		{
			push(stack_a, stack_b, "pa");
			push_count++;
		}
		else if (*((int *)ft_lstlast(*stack_b)->content) > middle)
			reverse_rotate(stack_b, "rrb");
		else
		{
			rotate(stack_b, "rb");
			rb_count++;
		}
	}
	if (!(ft_lstsize(*stack_b) <= len))
		restore_stack(stack_b, rb_count, "rrb");
	return (push_count);
}

/* Undo rotations in stack to maintain the original configuration.*/
void	restore_stack(t_list **stack, int count, char *rule)
{
	while (count > 0)
	{
		reverse_rotate(stack, rule);
		count--;
	}
}
