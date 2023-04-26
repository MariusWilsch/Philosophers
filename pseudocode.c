/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudocode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:59:15 by mwilsch           #+#    #+#             */
/*   Updated: 2023/04/24 11:16:38 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a struct to hold the shared data
typedef struct {
    int value;
    pthread_mutex_t mutex;
} SharedData;

void *thread_func(void *arg) {
    SharedData *shared_data = (SharedData *) arg;

    // Lock the mutex to ensure exclusive access to the shared data
    pthread_mutex_lock(&shared_data->mutex);

    // Modify the shared data
    shared_data->value += 1;

    // Unlock the mutex to release exclusive access to the shared data
    pthread_mutex_unlock(&shared_data->mutex);

    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Initialize the shared data
    SharedData shared_data = {
        .value = 0,
        .mutex = PTHREAD_MUTEX_INITIALIZER
    };

    // Create a new thread and pass a pointer to the shared data as an argument
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_func, (void *) &shared_data);

    // Lock the mutex to ensure exclusive access to the shared data
    pthread_mutex_lock(&shared_data.mutex);

    // Modify the shared data
    shared_data.value += 2;

    // Unlock the mutex to release exclusive access to the shared data
    pthread_mutex_unlock(&shared_data.mutex);

    // Wait for the new thread to finish
    pthread_join(thread_id, NULL);

    // Print the final value of the shared data
    printf("Shared data value: %d\n", shared_data.value);

    return 0;
}
