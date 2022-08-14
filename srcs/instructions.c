/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:03:33 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/14 00:36:33 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** The functions declared here turned out not being used by the sorting
 * algorithm implemented. I've decided to keep them as they are part of the
 * project's subject and can be useful in case of any changes in the sorting
 * algorithm.
 * */

/* Swaps first two elements of stack_a and stack_b at the same time.*/
void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, NULL);
	swap(stack_b, NULL);
	ft_printf("ss\n");
}

/* Shifts up all numbers of stack_a and stack_b.*/
void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, NULL);
	rotate(stack_b, NULL);
	ft_printf("rr\n");
}

/* Shifts down all numbers of stack_a and stack_b.*/
void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, NULL);
	reverse_rotate(stack_b, NULL);
	ft_printf("rrr\n");
}
