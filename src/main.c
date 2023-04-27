/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:09:27 by verdant           #+#    #+#             */
/*   Updated: 2023/04/27 12:42:47 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void leaks(void)
{
	system("leaks -q philo");
}

// void init_test(t_config *config, t_philo *philos)
// {
// 	ft_printf("Config:\n");
// 	ft_printf("number_of_philosophers: %d\n", config->num_philos);
// 	ft_printf("time_to_die: %d\n", config->time_to_die);
// 	ft_printf("time_to_eat: %d\n", config->time_to_eat);
// 	ft_printf("time_to_sleep: %d\n", config->time_to_sleep);
// 	ft_printf("must_eat_count: %d\n", config->n_must_eat);
// 	ft_printf("\n");
	
// 	ft_printf("Philosophers:\n");
// 	for (int i = 0; i < config->num_philos; i++)
// 	{
// 		ft_printf("id: %d\n", philos[i].thread_id);
// 		ft_printf("last_meal_time: %d\n", philos[i].last_eaten);
// 		ft_printf("meals_eaten: %d\n", philos[i].meals_eaten);
// 		ft_printf("left_fork: %p\n", philos[i].l_fork);
// 		ft_printf("right_fork: %p\n", philos[i].r_fork);
// 		ft_printf("config: %p\n", philos[i].config);
// 		ft_printf("\n");
// 	}
// }

// Test code for time.c
		// int64_t start_time = get_time();
    // printf("Starting time: %lld ms\n", start_time);

    // // Sleep for 2 seconds
    // usleep_but_better(50);

    // int64_t end_time = get_time();
    // printf("Ending time: %lld ms\n", end_time);

    // int64_t elapsed_time = time_diff(end_time, start_time);
    // printf("Elapsed time: %lld ms\n", elapsed_time);



void cleanup(t_config *config, int n_philos)
{
	int i;

	i = 0;
	while (i < n_philos)
	{
		if (pthread_join(config->philos_arr[i].thread, NULL) != 0)
			ft_printf("Error joining thread\n");
		pthread_mutex_destroy(&config->forks_arr[i]);
		i++;
	}
	free(config->forks_arr);
	pthread_mutex_destroy(&config->print_lock);
	pthread_mutex_destroy(&config->meal_lock);
	free(config->philos_arr);
}




/**
 * @brief 
 * 
 * 
 * @note Testing intialization of structs // init_test(&config, config.philos_arr);
 */
int	main(int argc, char *argv[])
{
	t_config	config;
	
	if (!init_structs(argc, argv, &config))
		return (EXIT_FAILURE);
	start_dinner(&config, config.philos_arr, config.num_philos);
	cleanup(&config, config.num_philos);
	// atexit(leaks);
	return (EXIT_SUCCESS);
}
