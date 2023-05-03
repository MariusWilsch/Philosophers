/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:09:27 by verdant           #+#    #+#             */
/*   Updated: 2023/05/02 15:29:53 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_config *c, int n_philos)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		if (n_philos != 1 && pthread_join(c->philos_arr[i].thread, NULL) != 0)
			printf("Error joining thread\n");
		pthread_mutex_destroy(&c->forks_arr[i]);
		i++;
	}
	free(c->forks_arr);
	pthread_mutex_destroy(&c->print_lock);
	pthread_mutex_destroy(&c->meal_lock);
	free(c->philos_arr);
}

/**
 * @brief Main function
 * 
 * @note To Test init of structs // init_test(&config, config.philos_arr);
 * @note To Test time.c // test_time();
 * @note To Test leaks // atexit(leaks);
 */
int	main(int argc, char *argv[])
{
	t_config	config;

	if (!init_structs(argc, argv, &config))
		return (EXIT_FAILURE);
	start_dinner(&config, config.philos_arr, config.num_philos);
	cleanup(&config, config.num_philos);
	return (EXIT_SUCCESS);
}
