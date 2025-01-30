/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:36:43 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/30 18:58:07 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_state	state;
	t_philo	philo[200];
	t_mutex	fork[200];

	if (!is_positive_number(argv) || validate_argc(argc)
		|| validate_argv(&state, argv))
	{
		ft_putendl_fd("Thy choices have been unwise.", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	philo_by_philo(&state, philo, fork);
	create_threads(&state, philo);
	bye_bye(&state, philo);
	return (0);
}
