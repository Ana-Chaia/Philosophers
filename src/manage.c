/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:00:13 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/30 19:13:37 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*manage(void *param)
{
	t_philo	*temp_philo;
	int		i;
	int		meals;

	temp_philo = (t_philo *)param;
	i = -1;
	meals = 0;
	while (++i < temp_philo->state->philos_qty)
	{
		if (count_meals_n_check_death(&temp_philo[i], &meals))
			return (param);
	}
	if (meals == temp_philo->state->philos_qty
		* temp_philo->state->x_meals)
		return (param);
	usleep(200);
	return (manage(param));
}

_Bool	count_meals_n_check_death(t_philo *philo, int *meals)
{
	pthread_mutex_lock(&philo->nbr_of_meals_locker);
	if (time_now() - philo->last_meal > philo->state->to_die)
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

	pthread_mutex_lock(&philo->state->writting_locker);
	time = time_now() - philo->state->initial_time;
	pthread_mutex_lock(&philo->state->death_locker);
	if (philo->state->is_dead)
	{
		pthread_mutex_unlock(&philo->state->death_locker);
		pthread_mutex_unlock(&philo->state->writting_locker);
		return ;
	}
	if (*action == *THE_END)
		philo->state->is_dead = true;
	pthread_mutex_unlock(&philo->state->death_locker);
	printf("%ld Philo n.%d  %s\n", time, philo->nbr, action);
	pthread_mutex_unlock(&philo->state->writting_locker);
}

suseconds_t	time_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
