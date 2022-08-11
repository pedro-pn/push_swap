/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:37:36 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/11 14:08:17 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*rules;
	int		status;

	stack_a = NULL;
	stack_b = NULL;
	rules = NULL;
	get_args(&stack_a, argc, argv);
	get_rules(&rules);
	status = test_rules(&stack_a, &stack_b, rules);
	if (status == SORTED)
		ft_printf("OK\n");
	else if (status == UNSORTED)
		ft_printf("KO\n");
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	ft_lstclear(&rules, free);
	if (status == NORULE)
		error_handle(NORULE);
	return (0);
}
