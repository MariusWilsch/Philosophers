/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:58:44 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/26 18:48:19 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_philo	*setdata(t_data **data, char *argv[], t_philo *ph)
{
	(*data)->num_of_ph = atoi(argv[1]) ;
	(*data)->time_to_die = atoi(argv[2]);
	(*data)->time_to_eat = atoi(argv[3]);
	(*data)->time_to_sleep = atoi(argv[4]);
	ph = calloc(sizeof(t_philo) , (*data)->num_of_ph);
	if (!ph || (*data)->num_of_ph == 0 )
		exit(1);
	return (ph);
}

int	main(int argc, char *argv[])
{
	t_philo	*ph;
	t_data	*data = NULL;

	data = calloc(sizeof(t_data), 1); // Change to malloc later
	if (argc != 5 || !data)
		exit(1);
	ph = setdata(&data, argv, ph);
	invite_philosophers(&ph, &data);
}