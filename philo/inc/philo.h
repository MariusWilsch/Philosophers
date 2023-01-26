/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:47:55 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/26 18:43:51 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct philo
{
	pthread_t				thread;
	pthread_mutex_t	lock;
	struct timeval	start;
	int							elapsed;
	bool						is_locked;
	int							number_tag; // Delete this later
} t_philo;

typedef struct data
{
	int	num_of_ph;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	// t_philo	*ph;
} t_data;

/*			Init			
- Creating a array of struct
- Assigning a thread and mutex to every index
- Global Actions
*/
void	invite_philosophers(t_philo **ph, t_data **data);

#endif