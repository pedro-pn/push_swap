/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:14:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/10 11:47:32 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*sorted;

	stack_a = NULL;
	stack_b = NULL;
	get_args(&stack_a, argc, argv);
	sorted = sort_array(stack_a, ft_lstsize(stack_a));
	split_stack(&stack_a, &stack_b, sorted, ft_lstsize(stack_a));
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
