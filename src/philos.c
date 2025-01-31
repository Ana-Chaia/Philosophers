/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:20:35 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/31 15:24:50 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_by_philo(t_state *state, t_philo *philo, t_mutex *fork)
{
	int	i;

	pthread_mutex_init(&state->writting_locker, NULL);
	pthread_mutex_init(&state->death_locker, NULL);
	state->is_dead = false;
	i = 0;
	while (i < state->philos_qty)
	{
		philo[i].nbr = i + 1;
		philo[i].meals = 0;
		philo[i].is_dead = false;
		pthread_mutex_init(&philo[i].nbr_of_meals_locker, NULL);
		philo[i].right_fork = &fork[i];
		pthread_mutex_init(philo[i].right_fork, NULL);
		if (i == state->philos_qty - 1)
			philo[i].left_fork = &fork[0];
		else
			philo[i].left_fork = &fork[i + 1];
		philo[i].state = state;
		state->initial_time = time_now();
		philo[i].last_meal = state->initial_time;
		i++;
	}
}

void	create_threads(t_state *state, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_create(&state->manager, NULL, manage, philo);
	while (i < state->philos_qty)
	{
		pthread_create(&philo[i].own_thread, NULL, routine, &philo[i]);
		i += 2;
	}
	//usleep(242);
	i = 1;
	while (i < state->philos_qty)
	{
		pthread_create(&philo[i].own_thread, NULL, routine, &philo[i]);
		i += 2;
	}
	while (i < state->philos_qty)
	{
		pthread_join(philo[i].own_thread, NULL);
		i++;
	}
	pthread_join(state->manager, NULL);
}
