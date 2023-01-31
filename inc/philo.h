/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:47:55 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/31 13:54:34 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_data t_data;

typedef struct s_mutexes
{
	pthread_mutex_t *fork;
	pthread_mutex_t start;
} t_mutex;

typedef struct s_config
{
	int	num_of_ph;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
} t_config;

typedef struct s_philo
{
	pthread_t		thread;
	int					id;
	int					elapsed;
	t_data			*data;
} t_philo;

typedef struct s_data
{
	t_config	*conf;
	t_mutex		*mutexes;
	t_philo		*philosophers;
} t_data;



/*			Init			
- Creating a array of struct
- Assigning a thread and mutex to every index
- Global Actions
*/
// void	invite_philosophers(t_philo **ph, t_data **data);

#endif

/**
 * @brief Utils
 * @note
 * parsing config data
 * @note
 * init mutexes
*/
bool	setdata(t_config *conf, t_mutex *mutexes,t_data *data, char *argv[]);
bool	mutexes_init(t_mutex *mutexes, t_config *conf);