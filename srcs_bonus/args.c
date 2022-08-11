/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:40:58 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/11 14:18:15 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_nums(char *str);
static int	check_max(char *str);
static int	check_max_2(char *str, int flag);
static void	check_duplicate(t_list **stack);

void	get_args(t_list **stack_a, int argc, char *argv[])
{
	int		index;
	int		check_code;

	if (argc < 2)
		error_handle(UNSARG);
	index = 1;
	while (argv[index])
	{
		check_code = check_nums(argv[index]);
		if (check_code)
		{
			ft_lstclear(stack_a, free);
			error_handle(check_code);
		}
		if (create_node(stack_a, argv[index]))
		{
			ft_lstclear(stack_a, free);
			return ;
		}
		index++;
	}
	check_duplicate(stack_a);
}

static int	check_nums(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if ((str[index] == '-' || str[index] == '+') && index == 0)
			index++;
		if (!ft_isdigit(str[index]))
			return (NOTDIGIT);
		index++;
	}
	if (check_max(str))
		return (INTOVER);
	return (0);
}

static int	check_max_2(char *str, int flag)
{
	int		n;
	char	*n_back;

	if (flag == 1)
		str--;
	n = ft_atoi(str);
	n_back = ft_itoa(n);
	if (ft_strncmp(str, n_back, ft_strlen(str)))
	{
		free(n_back);
		return (-1);
	}
	free(n_back);
	return (0);
}

static int	check_max(char *str)
{
	int	flag;
	int	str_len;
	int	ret;

	flag = 0;
	if (*str == '-')
		flag = 1;
	if (*str == '-' || *str == '+')
		str++;
	str_len = ft_strlen(str);
	ret = 0;
	if (str_len > 10)
		ret = -1;
	else if (str_len == 10)
		ret = check_max_2(str, flag);
	return (ret);
}

static void	check_duplicate(t_list **stack)
{
	t_list	*temp;
	t_list	*temp_2;

	temp = *stack;
	while (temp)
	{
		temp_2 = temp->next;
		while (temp_2)
		{
			if (*(int *)temp->content == *(int *)temp_2->content)
			{
				ft_lstclear(stack, free);
				error_handle(EDUPLI);
			}
			temp_2 = temp_2->next;
		}
		temp = temp->next;
	}	
}
