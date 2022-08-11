/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:51:37 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/11 14:02:59 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	exec_rules(t_list **stack_a, t_list **stack_b, char *command);
static int	is_sorted(t_list *stack_a, t_list *stack_b);

void	get_rules(t_list **rules)
{
	char	*line;
	t_list	*node;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		node = ft_lstnew(line);
		if (!node)
		{
			free(line);
			error_handle(FALLOC);
		}
		ft_lstadd_back(rules, node);
		line = get_next_line(STDIN_FILENO);
	}
}

int	test_rules(t_list **stack_a, t_list **stack_b, t_list *rules)
{
	char	*command;

	while (rules)
	{
		command = (char *)rules->content;
		if (exec_rules(stack_a, stack_b, command))
			return (NORULE);
		rules = rules->next;
	}
	return (is_sorted(*stack_a, *stack_b));
}

static int	exec_rules(t_list **stack_a, t_list **stack_b, char *command)
{
	if (!ft_strncmp(command, "sa\n", 3) && ft_strlen(command) == 3)
		swap(stack_a);
	else if (!ft_strncmp(command, "sb\n", 3) && ft_strlen(command) == 3)
		swap(stack_b);
	else if (!ft_strncmp(command, "ss\n", 3) && ft_strlen(command) == 3)
		ss(stack_a, stack_b);
	else if (!ft_strncmp(command, "pa\n", 3) && ft_strlen(command) == 3)
		push(stack_a, stack_b);
	else if (!ft_strncmp(command, "pb\n", 3) && ft_strlen(command) == 3)
		push(stack_b, stack_a);
	else if (!ft_strncmp(command, "ra\n", 3) && ft_strlen(command) == 3)
		rotate(stack_a);
	else if (!ft_strncmp(command, "rb\n", 3) && ft_strlen(command) == 3)
		rotate(stack_b);
	else if (!ft_strncmp(command, "rr\n", 3) && ft_strlen(command) == 3)
		rr(stack_a, stack_b);
	else if (!ft_strncmp(command, "rra\n", 4) && ft_strlen(command) == 4)
		reverse_rotate(stack_a);
	else if (!ft_strncmp(command, "rrb\n", 4) && ft_strlen(command) == 4)
		reverse_rotate(stack_b);
	else if (!ft_strncmp(command, "rrr\n", 4) && ft_strlen(command) == 4)
		rrr(stack_a, stack_b);
	else
		return (NORULE);
	return (0);
}

static int	is_sorted(t_list *stack_a, t_list *stack_b)
{
	if (stack_b)
		return (UNSORTED);
	while (stack_a->next)
	{
		if (*(int *)stack_a->content > *(int *)stack_a->next->content)
			return (UNSORTED);
		stack_a = stack_a->next;
	}
	return (SORTED);
}
