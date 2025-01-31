/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:36:02 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/31 12:23:58 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	theorize(t_philo *philo)
{
	print_on_terminal(philo, THINK);
	my_sleep((philo->state->to_die
			- philo->state->to_eat - philo->state->to_sleep) - 100);
}
