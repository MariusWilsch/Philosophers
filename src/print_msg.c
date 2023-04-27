/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:31:23 by verdant           #+#    #+#             */
/*   Updated: 2023/04/27 15:33:36 by verdant          ###   ########.fr       */
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

void print_log(t_philo *philo, char *msg, t_philo_state state)
{
	const int64_t start_time = philo->config->start_time;
	
	pthread_mutex_lock(&philo->config->print_lock);
	printf("%lld %d %s\n", get_time() - start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->config->print_lock);
}
