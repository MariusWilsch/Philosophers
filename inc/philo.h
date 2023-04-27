/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:47:55 by mwilsch           #+#    #+#             */
/*   Updated: 2023/04/27 15:33:04 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

typedef struct s_config t_config; 

typedef enum e_philo_state
{
	PHILO_TAKEN_FORK,
	PHILO_STATE_EATING,
	PHILO_STATE_SLEEPING,
	PHILO_STATE_THINKING,
	PHILO_STATE_DEAD,
}	t_philo_state;


/**
 * @brief Philosopher struct
 * 
 * @param id The thread id
 * @param last_eaten The last time the philosopher ate
 * @param meals_eaten The number of times the philosopher has eaten
 * @param l_fork The left fork, which is his own fork
 * @param r_fork The right fork, which is the next philosopher's fork
 * @param config The configuration struct
 */
typedef struct s_philo {
	int								id;
	int64_t						last_eaten;
	int								meals_eaten;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	t_config					*config;
	pthread_t					thread;
} t_philo;


/**
 * @brief Configuration struct
 * 
 * @param num_philos The number of philosophers
 * @param time_to_die The time to die in milliseconds
 * @param time_to_eat The time to eat in milliseconds
 * @param time_to_sleep The time to sleep in milliseconds
 * @param n_must_eat The number of times each philosopher must eat
 * @param start_time The time the simulation started in milliseconds
 * @param dead Whether or not a philosopher has died
 * @param print_lock The mutex for printing
 * @param meal_lock The mutex for the updating the last_eaten variable
 * @param forks_arr An array of mutexes for the forks_arr
 * @param philo_arr An array of struct of philosophers
 */
typedef struct s_config {
	int								num_philos;
	int64_t						time_to_die;
	int64_t						time_to_eat;
	int64_t						time_to_sleep;
	int								n_must_eat;
	int64_t						start_time;
	bool							dead;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		*forks_arr;
	t_philo						*philos_arr;
} t_config;


/*			Main				*/

void leaks(void);

/*			Print			*/

bool	print_error(char *str);
void	print_log(t_philo *philo, char *msg, t_philo_state state);

/*			Parser			*/

bool	config_init(int argc, char *argv[], t_config *config);
bool	init_structs(int argc, char *argv[], t_config *config);

/*			Time				*/

int64_t	time_diff(int64_t present, int64_t past);
int64_t	get_time(void);
void		usleep_but_better(int64_t sleep_time);

/*			Dinner			*/

bool	start_dinner(t_config *config, t_philo *philos , int n_philos);

/*			Actions			*/

void eating(t_philo *philo);
bool sleeping(t_philo *philo);
bool thinking(t_philo *philo);

#endif