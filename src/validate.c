/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:37:42 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/31 15:35:32 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_argc(int nbr_args)
{
	if (nbr_args < 2)
		ft_putendl_fd("Two's company, three's a crowd!", STDERR_FILENO);
	else if (nbr_args < 3)
		ft_putendl_fd("When ought I to die?", STDERR_FILENO);
	else if (nbr_args < 4)
		ft_putendl_fd("Must I starve to death?", STDERR_FILENO);
	else if (nbr_args < 5)
		ft_putendl_fd("Sleep's deprivation is but torment!", STDERR_FILENO);
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
	state->philos_qty = atol_4time(argv[1]);
	state->to_die = atol_4time(argv[2]);
	state->to_eat = atol_4time(argv[3]);
	state->to_sleep = atol_4time(argv[4]);
	state->x_meals = -1;
	if (argv[5])
		state->x_meals = atol_4time(argv[5]);
	printf("%d", state->x_meals);
	if ((state->philos_qty <= 0 || state->philos_qty > 200) || state->to_die < 60 || state->to_eat < 60 || state->to_sleep < 60 || (argv[5] && state->x_meals < 0))
	{
		ft_putendl_fd("Thy choices have been unwise.", STDERR_FILENO);
		return (true);
	}	
	return (false);
}

// int	validate_argv(t_state *state, char **argv)
// {
// 	state->philos_qty = atol_4time(argv[1]);
// 	if (state->philos_qty <= -1 || state->philos_qty > 200)
// 		return (true);
// 	state->to_die = atol_4time(argv[2]);
// 	if (state->to_die < 60)
// 		return (true);
// 	state->to_eat = atol_4time(argv[3]);
// 	if (state->to_eat < 60)
// 		return (true);
// 	state->to_sleep = atol_4time(argv[4]);
// 	if (state->to_sleep < 60)
// 		return (true);
// 	if (argv[5])
// 	{
// 		state->x_meals = atol_4time(argv[5]);
// 		if (state->x_meals < 0)
// 			return (true);
// 	}
// 	else
// 	{
// 		state->x_meals = -1;
// 		ft_putendl_fd("Thy choices have been unwise.", STDERR_FILENO);
// 	}
// 	return (false);
// }

int	not_positive_nbr(int argc, char **argv)
{
	int 	i;
	char	*arg;
	
	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		while (*arg >= '0' && *arg <= '9')
			arg++;
		if (*arg != '\0')
		{
			ft_putendl_fd("Wisdom: try positive numbers.", STDERR_FILENO);
			return (true);
		}
		i++;
	}
	return (false);
}
