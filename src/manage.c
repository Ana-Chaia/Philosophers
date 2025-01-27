/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:00:13 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/27 17:48:19 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*manage(void *param)
{
	t_philo	*temp_philo;
	int		i;
	int		meals;

	temp_philo = (t_philo *) param;
	i = 0;
	meals = 0;
	while (i < temp_philo->philo_state->philos_qty)
	{
		if (count_meals_n_check_death(&temp_philo[i], &meals))
			return (temp_philo);
		i++;
	}
	if (meals == temp_philo->philo_state->philos_qty
		* temp_philo->philo_state->x_meals)
		return (temp_philo);
	return (manage(temp_philo));
}

_Bool	count_meals_n_check_death(t_philo *philo, int *meals)
{
	pthread_mutex_lock(&philo->nbr_of_meals_locker);
	if (time_now() - philo->last_meal > philo->philo_state->to_die)
	{
		pthread_mutex_unlock(&philo->nbr_of_meals_locker);
		print_on_terminal(philo, THE_END);
		return (true);
	}
	else
		*meals += philo->meals;
	pthread_mutex_unlock(&philo->nbr_of_meals_locker);
	return (false);
}

void	print_on_terminal(t_philo *philo, char *action)
{
	suseconds_t	time;

	pthread_mutex_lock(&philo->philo_state->writting_locker);
	time = time_now() - philo->philo_state->initial_time;
	pthread_mutex_lock(&philo->philo_state->death_locker);
	if (ft_strcmp(action, THE_END) == 0)
		philo->philo_state->is_dead = true;
	//if (philo->philo_state->is_dead)
	pthread_mutex_unlock(&philo->philo_state->death_locker);
	printf("%ld Philo:%5d  %s\n", time, philo->nbr, action);
	pthread_mutex_unlock(&philo->philo_state->writting_locker);
}
suseconds_t	time_now(void)
{
	struct timeval	secs;

	gettimeofday(&secs, NULL);
	return (secs.tv_sec * 1000 + secs.tv_usec / 1000);
}