/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:09:27 by verdant           #+#    #+#             */
/*   Updated: 2023/04/26 12:31:36 by verdant          ###   ########.fr       */
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



void cleanup(t_config *config, int n_philos)
{
	int i;

	i = 0;
	while (i < n_philos)
	{
		pthread_mutex_destroy(&config->forks_arr[i]);
		i++;
	}
	free(config->philos_arr);
	free(config->forks_arr);
}


// init_test(&config, config.philos_arr);

/**
 * @brief 
 * 
 * @note I need to think if I want to implement a standard for myself of how I parse my input
 * @note Do I want to use a double pointer and return a bool or do I want to return a pointer?
 * @note Maybe ask chatgpt and copy and paste my code and ask him what he thinks
 */
int	main(int argc, char *argv[])
{
	t_config	config;
	
	if (!init_structs(argc, argv, &config))
		return (EXIT_FAILURE);
	cleanup(&config, config.num_philos);
	atexit(leaks);
	return (EXIT_SUCCESS);
}