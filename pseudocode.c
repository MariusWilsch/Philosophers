/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudocode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:59:15 by mwilsch           #+#    #+#             */
/*   Updated: 2023/04/27 15:32:03 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a struct to hold the shared data
void pick_forks(t_philo *philosopher) {
    pthread_mutex_t *first_fork;
    pthread_mutex_t *second_fork;

    // Determine the order in which to pick up the forks based on the philosopher's ID
    if (philosopher->id % 2 == 0) {
        first_fork = philosopher->l_fork;
        second_fork = philosopher->r_fork;
    } else {
        first_fork = philosopher->r_fork;
        second_fork = philosopher->l_fork;
    }

    // Lock the forks in the correct order
    pthread_mutex_lock(first_fork);
    pthread_mutex_lock(second_fork);
}
