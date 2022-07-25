/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:14:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/25 18:28:40 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
//	t_list	*stack_b;

	stack_a = NULL;
	get_args(&stack_a, argc, argv);
	ft_printf("nmemb: %d\n", ft_lstsize(stack_a));
	ft_lstclear(&stack_a, free);
	return (0);
}
