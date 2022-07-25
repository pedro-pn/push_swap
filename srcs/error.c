/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:18:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/25 17:11:51 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handle(int code)
{
	if (code == UNSARG)
		write(STDERR_FILENO, "Insuficient number of arguments\n", 32);
	else if (code == INTOVER)
		write(STDERR_FILENO, "Int overflow detected!\n", 23);
	else if (code == NOTDIGIT)
		write(STDERR_FILENO, "Only integers are valid!\n", 25);
	exit(EXIT_FAILURE);
}
