/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:27:56 by verdant           #+#    #+#             */
/*   Updated: 2023/05/02 15:28:19 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	leaks(void)
// {
// 	system("leaks -q philo");
// }

// Test code for parser.c
// void init_test(t_config *config, t_philo *philos)
// {
// 	printf("Config:\n");
// 	printf("number_of_philosophers: %lld\n", config->num_philos);
// 	printf("time_to_die: %lld\n", config->time_to_die);
// 	printf("time_to_eat: %lld\n", config->time_to_eat);
// 	printf("time_to_sleep: %lld\n", config->time_to_sleep);
// 	printf("must_eat_count: %lld\n", config->n_must_eat);
// 	printf("\n");

// 	printf("Philosophers:\n");
// 	for (int i = 0; i < config->num_philos; i++)
// 	{
// 		printf("id: %d\n", philos[i].id);
// 		printf("last_meal_time: %d\n", philos[i].last_eaten);
// 		printf("meals_eaten: %d\n", philos[i].meals_eaten);
// 		printf("left_fork: %p\n", philos[i].l_fork);
// 		printf("right_fork: %p\n", philos[i].r_fork);
// 		printf("config: %p\n", philos[i].config);
// 		printf("\n");
// 	}
// }

// Test code for time.c
// void	test_time(void)
// {
// 		int64_t start_time = get_time();
//     printf("Starting time: %lld ms\n", start_time);

//     // Sleep for 2 seconds
//     usleep_but_better(50);

//     int64_t end_time = get_time();
//     printf("Ending time: %lld ms\n", end_time);

//     int64_t elapsed_time = time_diff(end_time, start_time);
//     printf("Elapsed time: %lld ms\n", elapsed_time);
// }
