/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudocode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:59:15 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/28 14:33:07 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// dying ()
	// start counter
	// counter == time_to_die
	// exit(1); with error message

// Action func()
	// Actions include in order
		// Actions
			// eating
			// sleeping
			// thinking
		// Special
			// dying


// int	main (int argc, char *argv[])
// {
// 	// Struct t_philo
// 	// struct data

// 	// setdata()
// 	// malloc struct of array
// 	// Create threads & mutexes for each index
// 		// Pass them to the global action function
	

// 	// Wait for all threads to complete with pthread_join // Do I need this?
// }



// 






// Timer (Works for only tracking times under 1 sec)

// int main(void)
// {
// 	struct timeval start, end;
// 	int elapsed;
// 	gettimeofday(&start, NULL);
// 	// printf("%d\n", start.tv_usec);


// 	while (1)
// 	{
// 		gettimeofday(&end, NULL);
// 		elapsed = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
// 		if (elapsed == (500))
// 		{
// 			// printf("%d\t", end.tv_usec - start.tv_usec);
// 			printf("%d", elapsed);
// 			break ;
// 		}
// 	}
// }





// The problem I'm facing right now is that:
	// Discription
		// I'm passing one struct at a time to the thread function so I only have access
		// to the member vars of that struct
		// So in the case of the condition being met I want to break out the loop
		// however I also do not want the other threads to continue
	// Idea
		// Mutexes
		// Variables
			// If I pass the data struct or a pointer to the data array inside of my
				// ph struct I could check for a bool being set
		
// One thread to rule them all
	// inside of my ph_routine I only have access to my local ph
	// However If I setup a extra struct which would act as my monitor struct
	// and pass a void * to that monitor struct inside of my ph struct I can check
	// If any philosopher has died

// Can this problem be solved with mutexes as well?

// Okay I got a second opinion from another guy and he also had a similar structure
// No pun inteded

// Now with that in mind I'm facing a new problem. It's to big to understand right now
// So I need to break it down.

// Back to ACP
























// If a have a s_data how do I link each s_philo struct to the s_data struct?
	// When I intialise the array of struct for the philo threads I need a ptr to the s_data struct for at each s_philo[x];
	// SO then I can access the individual s_philo structs from my s_data struct


// Struct Setup

struct s_data {
    int shared_data;
    struct s_philo *philosophers[6];
};

struct s_philo {
    int id;
};

struct s_data shared_data;
struct s_philo philosophers[6];

int i;
for (i = 0; i < 6; i++) {
    philosophers[i].id = i;
    shared_data.philosophers[i] = &philosophers[i];
}

// s_philo thread creation

void	invite_philosophers(t_philo **ph, t_data **data)
{
	struct timeval	start;
	t_philo					*temp;
	int							i;
	

	i = 0;
	temp = (*ph);
	while (i < (*data)->num_of_ph)
	{
		temp[i].number_tag = i;
		i++;
	}
	i = 0;
	while (i < (*data)->num_of_ph)
	{
		gettimeofday(&temp[i].start, NULL);
		temp[i].is_locked = false;
		pthread_mutex_init(&temp[i].lock, NULL);
		if (pthread_create(&temp[i].thread, NULL, &philo_routine, &temp[i]) < 0)
			exit(1);
		i++;
	}
	i = 0;
	while (i < (*data)->num_of_ph)
	{
		pthread_join(temp[i].thread, NULL);
		i++;
	}
}

// Making a thread wait

void* thread_func(void* arg) {
    int id = *(int*)arg;
    // increment the counter
    pthread_mutex_lock(&mutex);
    threads_created++;
    while(threads_created < total_threads) // or Some other condition
		{
        pthread_mutex_unlock(&mutex);
        // wait
        pthread_mutex_lock(&mutex);
    }
    pthread_mutex_unlock(&mutex);
    // continue execution
    //...
    return (NULL);
}

void	*dying_logic(void	*arg)
{
	t_philo	*local_ph = (t_philo *)arg;
	struct timeval end;

	while (true)
	{
		gettimeofday(&end, NULL);
		local_ph->elapsed = convert_time(&local_ph->start, &end);
		if (local_ph->elapsed == 700)
		{
			// printf("At %d --> ph %d died\n",local_ph->elapsed, local_ph->number_tag);
			// exit handled through monitoring_thread
		}
	}
	return (NULL);
}

// Starting the simulation
