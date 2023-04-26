/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:09:27 by verdant           #+#    #+#             */
/*   Updated: 2023/04/26 09:28:33 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void leaks(void)
{
	system("leaks -q philo");
}


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
	// t_philo		*philo;
	
	init_structs(argc, argv, &config);
	// ft_printf("num_philos: %d", config.num_philos);
	// cleanup();
	// atexit(leaks);
}