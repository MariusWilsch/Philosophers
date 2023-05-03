/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:13:46 by verdant           #+#    #+#             */
/*   Updated: 2023/05/02 15:34:41 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Get the current time in milliseconds
 * 
 * @note I will get the current time by using gettimeofday()
 * 
 */
int64_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int64_t	time_diff(int64_t present, int64_t past)
{
	return (present - past);
}

/**
 * @brief Sleep for a given amount of milliseconds
 *  * 
 */
void	usleep_but_better(int64_t sleep_time)
{
	int64_t				sleep_start;

	sleep_start = get_time();
	while (1)
	{
		if (time_diff(get_time(), sleep_start) >= sleep_time)
			return ;
		usleep(300);
	}
}
