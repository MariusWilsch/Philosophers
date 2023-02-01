/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudocode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:59:15 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/31 16:15:49 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


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

// Connecting philsophers to struct
int i;
for (i = 0; i < 6; i++) {
    philosophers[i].id = i;
    shared_data.philosophers[i] = &philosophers[i];
}

// How does this make a thread wait?
// ---
// Question: How can we make all threads wait until all threads have been
// initialised? 

void	did_intit_go_right()
{
		pthread_mutex_lock(&mutex); // 3.1 Can't lock the mutex until while loop in main thread has finihed 
		// 3.2 if while loop is finished then mutex is locked so thread x can unlock & return
		// 3.3 this will continue for all threads

		// Idea
			// Init start time here - this part will only be executed as soon as the while loop in the main
			// thread is finished

		pthread_mutex_unlock(&mutex); 
		return (ph.data.i < ph.conf.num_of_ph) // This will evalutate to true every time so each thread can be started
}

// Assuming we have this thread func. How can we make the thread pause execution
// until all threads are created?
	// Assuming we have to create 5 threads and we want to pause the execution of the thread_func until
	// all 5 threads are created. How is this possible only using a mutex and no global variables?

void* thread_func(void* arg) {
    int id = *(int*)arg;
    
		// Phase 1
   	// if (ph.data.i < ph.conf.num_of_ph)
		
		if (did_init_go_right(pass local ph)) // Used to pause threads execution
			
    // Phase 2 if (did_init_go_right)
			// eating
				// At end of eating assign start
				// Taking forks
			// sleeping
				// usleep_but_better < time_to_sleep
			// thinking
				// taking forks func if has 2 forks then print message and eat
    return (NULL);
}


// s_philo thread creation
void	invite_philosophers(t_philo *ph, t_data *data)
{
	struct timeval	start;
	t_philo					*temp;
	int							i;
	

	i = 0;
	temp = ph;
	i = 0;
	pthread_mutex_lock(&mutex); // 1. Locking init_mutex
	while (i < (*data)->num_of_ph) // 2. Creating the threads while mutex is locked
	{
		temp[i].id = i;
		temp[i].data = data;
		if (pthread_create(&temp[i].thread, NULL, &philo_routine, &temp[i]) < 0)
			return (pthread_mutex_unlock(&mutex))
		i++;
	}
	i = 0;
	pthread_mutex_unlock(&mutex);
	// while (i < (*data)->num_of_ph)
	// {
	// 	pthread_join(temp[i].thread, NULL);
	// 	i++;
	// }
}

// Making a thread wait
	// but why do I need that?
	// the int is passed as pointer so I only send the address not the variable itself to avoid data races
bool for_later_stuff(int *check_that, pthread_mutex_t *mutex)
{
	int	temp;
	pthread_mutex_lock(mutex);
	temp = (*check_Tat);
	pthread_mutex_unlock(mutex);
	return (true);
}


bool	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philosophers = malloc(sizeof(t_philo) * data->conf->num_of_ph);
	if (!data->philosophers)
		return (false);
	pthread_mutex_lock(&data->mutexes->start);
	while (i < data->conf->num_of_ph)
	{
		data->philosophers[i].conf = data->conf;
		data->philosophers[i].mutexes = data->mutexes;
		data->philosophers[i].id = i;
		if (pthread_create(data->philosophers[i].thread, NULL, &philo_routine, &data->philosophers[i]))
			return (false);
		i++;
	}
	pthread_mutex_unlock(&data->mutexes->start);
	i = 0;
	while (i < data->conf->num_of_ph)
	{
		pthread_join(data->philosophers[i].thread, NULL);
		i++;
	}
	return (false);
}










start.tv_usec / 1000.0 = micros


int	convert_time(struct timeval	*s, struct timeval *e)
{
	return ((e->tv_sec - s->tv_sec) * 1000 + (e->tv_usec - s->tv_usec) / 1000);
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
