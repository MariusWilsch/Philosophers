/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:31:23 by verdant           #+#    #+#             */
/*   Updated: 2023/04/25 18:56:54 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief 
 * 
 * @param str A error message
 * @return false
 * 
 * @note This function is used to print error messages.
 * @note It always returns false.
 */
bool	print_error(char *str)
{
	ft_printf("%s", str);
	return (false);
}

// void print_log(void)