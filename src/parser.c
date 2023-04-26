/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:23:53 by verdant           #+#    #+#             */
/*   Updated: 2023/04/26 09:32:21 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


bool	forks_init(t_config *config, int n_forks_needed)
{
	int	i;

	i = 0;
	config->forks = malloc(sizeof(pthread_mutex_t) * n_forks_needed);
	if (!config->forks)
		return (print_error("Forks: Malloc failed\n"));
	while (i < n_forks_needed)
	{
		if (pthread_mutex_init(&config->forks[i], NULL) != 0)
			return (print_error("Forks: Mutex init failed\n"));
		i++;
	}
	// 
	return (true);
}


/**
 * @brief 
 * 
 * @note I don't know if I'm making this unnecessarily complicated by using a double pointer 
 * and trying to return the config struct. I'm doing this because I want to be able to directly
 * check if everything was initialized correctly in the main function
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
	return (true);
}

bool	init_structs(int argc, char *argv[], t_config *config)
{
	// if (!philo)
	
	if (!forks_init(config, config->num_philos))
		return (false);
	if (!config_init(argc, argv, config))
		return (false);
	return (true);
}
