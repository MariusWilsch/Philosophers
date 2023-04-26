/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:23:53 by verdant           #+#    #+#             */
/*   Updated: 2023/04/26 12:37:56 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/**
 * @brief 
 * 
 * @param config Configuration struct
 * @param n_philos Number of philosophers
 * 
 * @note config->philos_arr is array of t_philo structs which is dynamically allocated
 */
bool	philos_init(t_config *config, int n_philos)
{
	int	i;

	i = 0;
	config->philos_arr = malloc(sizeof(t_philo) * n_philos);
	if (!config->philos_arr)
	{
		free(config->forks_arr);
		return (print_error("Philos: Malloc failed\n"));
	}
	while (i < n_philos)
	{
		config->philos_arr[i].thread_id = i;
		config->philos_arr[i].last_eaten = 0;
		config->philos_arr[i].meals_eaten = 0;
		config->philos_arr[i].l_fork = &config->forks_arr[i];
		config->philos_arr[i].r_fork = &config->forks_arr[(i + 1) % n_philos];
		config->philos_arr[i].config = config;
		i++;
	}
	return (true);
}


/**
 * @brief 
 * 
 * @param config Configuration struct
 * @param n_forks_needed Number of forks needed
 *
 * @note config->forks_arr is array of pthread_mutex_t structs which is dynamically allocated
 */
bool	forks_init(t_config *config, int n_forks_needed)
{
	int	i;

	i = 0;
	config->forks_arr = malloc(sizeof(pthread_mutex_t) * n_forks_needed);
	if (!config->forks_arr)
		return (print_error("Forks: Malloc failed\n"));
	while (i < n_forks_needed)
	{
		if (pthread_mutex_init(&config->forks_arr[i], NULL) != 0)
		{
			free(config->forks_arr);
			return (print_error("Forks: Mutex init failed\n"));
		}
		i++;
	}
	return (true);
}


/**
 * @brief 
 * 
 * @param config Configuration struct to be filled
 * 
 * @note Config is declared on the stack in main, so it is passed by value
 * @note config->print is declared on the stack as well
 */
bool	config_init(int argc, char *argv[], t_config *config)
{
	t_config *t;

	t = config;
	if (argc < 5 || argc > 6)
		return (print_error("Invalid Usage, try: <num_ph> <t_die> <t_eat> <t_eat> (t_must_eat)\n"));
	config->num_philos = ft_atoi(argv[1]);
	config->time_to_die = ft_atoi(argv[2]);
	config->time_to_eat = ft_atoi(argv[3]);
	config->time_to_sleep = ft_atoi(argv[4]);
	config->n_must_eat = -1;
	config->start_time = 0;
	config->dead = false;
	if (pthread_mutex_init(&config->print, NULL) != 0)
		return (print_error("Config: Mutex init failed\n"));
	if (argc == 6)
		config->n_must_eat = ft_atoi(argv[5]);
	if (t->num_philos <= 0 || t->num_philos > 200)
		return (print_error("Config: Invalid number of philosophers\n"));
	if (t->time_to_die < 0 || t->time_to_eat < 0 || t->time_to_sleep < 0)
		return (print_error("Config: Invalid time\n"));
	if (argc == 6 && t->n_must_eat < 0)
		return (print_error("Config: Invalid number of meals\n"));
	return (true);
}

/**
 * @brief 
 * 
 * @param argc Number of arguments
 * @param argv Array of arguments
 * 
 * @note config is declared on the stack in main, so it is passed by value
 */
bool	init_structs(int argc, char *argv[], t_config *config)
{
	if (!config_init(argc, argv, config))
		return (false);
	if (!forks_init(config, config->num_philos))
		return (false);
	if (!philos_init(config, config->num_philos))
		return (false);
	return (true);
}
