/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:05:40 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/10 15:15:22 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_node(t_list **stack_a, char *argv)
{
	t_list	*node;
	int		*content;

	content = malloc(sizeof(*content));
	if (!content)
		return (1);
	*content = ft_atoi(argv);
	node = ft_lstnew(content);
	if (!node)
	{
		free(content);
		return (1);
	}
	ft_lstadd_back(stack_a, node);
	return (0);
}
