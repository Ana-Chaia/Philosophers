/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:00:52 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/29 17:20:31 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


_Bool	is_fed(t_philo *philo)
{
	_Bool	flag;

	flag = false;
	pthread_mutex_lock(&philo->nbr_of_meals_locker);
	if (philo->state->x_meals == philo->meals)
		flag = true;
	pthread_mutex_unlock(&philo->nbr_of_meals_locker);
	return (flag);
}

_Bool	is_dead(t_philo *philo)
{
	_Bool	flag;

	flag = false;
	pthread_mutex_lock(&philo->state->death_locker);
	if (philo->state->is_dead)
		flag = true;
	pthread_mutex_unlock(&philo->state->death_locker);
	return (flag);
}


void	*routine(void *arg)
{
	t_philo	*the_philo;

	the_philo = (t_philo *)arg;
	devour(the_philo);
	rest(the_philo);
	theorize(the_philo);
	if (is_fed(the_philo) || is_dead(the_philo))
		return (arg);
	return (routine(arg));
}
