/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:16:54 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/25 18:22:09 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_nums(char *str);
static int	check_max(char *str);
static int	check_max_2(char *str, int flag);

void	get_args(t_list **stack_a, int argc, char *argv[])
{
	int		index;
	int		check_code;
	int		*content;
	t_list	*node;

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
		content = malloc(sizeof(*content));
		*content = ft_atoi(argv[index]);
		node = ft_lstnew(content);
		ft_lstadd_back(stack_a, node);
		index++;
	}
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
