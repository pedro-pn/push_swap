/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:38:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/11 14:17:43 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

# define UNSARG 1
# define NOTDIGIT 2
# define INTOVER 3
# define EDUPLI 4
# define FALLOC 5
# define NORULE 6
# define SORTED 7
# define UNSORTED 8

void	get_args(t_list **stack_a, int argc, char *argv[]);
int		create_node(t_list **stack_a, char *argv);
void	get_rules(t_list **rules);
int		test_rules(t_list **stack_a, t_list **stack_b, t_list *rules);
void	error_handle(int code);
void	swap(t_list **stack);
void	push(t_list **dest, t_list **src);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif
