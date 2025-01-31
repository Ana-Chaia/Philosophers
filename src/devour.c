/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   devour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:48:47 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/31 12:27:44 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	even_p_take_f(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_on_terminal(philo, RIGHT_F);
	pthread_mutex_lock(philo->left_fork);
	print_on_terminal(philo, LEFT_F);
}

void	n_even_p_take_f(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_on_terminal(philo, LEFT_F);
	pthread_mutex_lock(philo->right_fork);
	print_on_terminal(philo, RIGHT_F);
}

void	devour(t_philo *philo)
{
	if (philo->state->philos_qty == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_on_terminal(philo, RIGHT_F);
		my_sleep(philo->state->to_die + 11);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	if (philo->nbr % 2 == 0)
		even_p_take_f(philo);
	else
		n_even_p_take_f(philo);
	print_on_terminal(philo, EATING);
	pthread_mutex_lock(&philo->nbr_of_meals_locker);
	philo->last_meal = time_now();
	philo->meals++;
	pthread_mutex_unlock(&philo->nbr_of_meals_locker);
	my_sleep(philo->state->to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
