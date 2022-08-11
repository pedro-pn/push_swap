/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:44:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/11 13:44:08 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_handle(int code)
{
	if (code != UNSARG)
		write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
