/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudocode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:59:15 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/26 18:30:25 by mwilsch          ###   ########.fr       */
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

int main(void)
{
	struct timeval start, end;
	int elapsed;
	gettimeofday(&start, NULL);
	// printf("%d\n", start.tv_usec);


	while (1)
	{
		gettimeofday(&end, NULL);
		elapsed = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
		if (elapsed == (500))
		{
			// printf("%d\t", end.tv_usec - start.tv_usec);
			printf("%d", elapsed);
			break ;
		}
	}
}

