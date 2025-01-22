/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:37:42 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/22 13:38:50 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_argc(int nbr_args)
{
	if (nbr_args < 2)
		ft_putendl_fd("./philo.. what?", STDERR_FILENO);
	else if (nbr_args < 3)
		ft_putendl_fd("Two's company, three's a crowd!", STDERR_FILENO);
	else if (nbr_args < 4)
		ft_putendl_fd("When ought I to die?", STDERR_FILENO);
	else if (nbr_args < 5)
		ft_putendl_fd("Must I starve to death?", STDERR_FILENO);
	else if (nbr_args > 6)
		ft_putendl_fd("Such absurdity knows no bounds!", STDERR_FILENO);
	else
		return (false);
	ft_putendl_fd(
		"\n"
		"PLEASE: X   X   X   X   X\n"
		"        |   |   |   |   |\n"
		"        |   |   |   |   Provisions for the mortal coil (+)\n"
		"        |   |   |   The brief sanctuary of dreams (>60)\n"
		"        |   |   Time granted for feasting (>60)\n"
		"        |   Moments granted 'til death's embrace (>60)\n"
		"        Assembly of philosophers gathered (1-200)\n", STDERR_FILENO);
	return (true);
}

int	validate_argv(t_state *state, char **argv)
{
	state->philos = atol_4time(argv[1]);
	if (state->philos <= -1 || state->philos > 200)
		return (true);
	state->to_die = atol_4time(argv[2]);
	if (state->to_die < 60)
		return (true);
	state->to_eat = atol_4time(argv[3]);
	if (state->to_eat < 60)
		return (true);
	state->to_sleep = atol_4time(argv[4]);
	if (state->to_sleep < 60)
		return (true);
	if (argv[5])
	{
		state->x_meals = atol_4time(argv[5]);
		if (state->x_meals < 0)
			return (true);
	}
	else
		state->x_meals = -1;
	return (false);
}
