/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:36:43 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/31 12:49:13 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_state	state;
	t_philo	philo[200];
	t_mutex	fork[200];

	state = (t_state){0};
	if (not_positive_nbr(argc, argv))
		return (EXIT_FAILURE);
	if (validate_argc(argc))
		return (EXIT_FAILURE);
	if (validate_argv(&state, argv))
	{
		//ft_putendl_fd("Thy choices have been unwise.", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	philo_by_philo(&state, philo, fork);
	create_threads(&state, philo);
	bye_bye(&state, philo);
	return (0);
}

