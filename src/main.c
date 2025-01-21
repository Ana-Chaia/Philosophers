/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:36:43 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/21 20:26:43 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

suseconds_t	atol_4time(const char *nbr)
{
	char		sign;
	suseconds_t	nb;

	while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	sign = 0;
	if (*nbr == '+' || *nbr == '-')
		sign = *nbr++;
	nb = 0;
	while (*nbr >= '0' && *nbr <= '9')
		nb = (nb * 10) + *nbr++ - 48;
	if (sign == '-')
		nb = -nb;
	if (*nbr)
		return (-1);
	return (nb);
}

int	validate_argc(int nbr_args)
{
	//not int???
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
		"        |   |   |   |   Provisions for the mortal coil\n"
		"        |   |   |   The brief sanctuary of dreams\n"
		"        |   |   Time granted for feasting\n"
		"        |   Moments granted 'til death's embrace\n"
		"        Assembly of philosophers gathered\n", STDERR_FILENO);
	return (true);
}
int	validate_argv(t_state *state, char **argv)
{
	state->philos = atol_4time(argv[1]);
	if (state->philos == -1 || state->philos > 200)
		return (true);
	state->to_die = atol_4time(argv[2]);
	if (state->to_die < 10)
		return (true);
	state->to_eat = atol_4time(argv[3]);
	if (state->to_eat < 10)
		return (true);
	state->to_sleep = atol_4time(argv[4]);
	if (state->to_sleep < 10)
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

int	main(int argc, char **argv)
{
	(void)argv;
	
	t_state	state;
	//t_philo	philo[200];   //array de t_philo
	//t_mutex	fork[200];	//array de garfos

	state = (t_state){0};
	if (validate_argc(argc))
		return (EXIT_FAILURE);
	if (validate_argv(&state, argv))
	{
		ft_putendl_fd("Thy choices have been unwise.", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (0);
}


// {
// 	int i = 0;
// 	int x;

// 	if (argc != 2 || (x = atoi(argv[1])) <= 0)
// 	{
// 		printf("Usage: %s <number_of_philosophers>\n", argv[0]);
// 		return (1);
// 	}
// 	pthread_mutex_init(&mutex, NULL);
// 	while (i < 5)
// 	{
// 		if (pthread_create(&philo[i], NULL, &routine, NULL) != 0)
// 			return (1);
// 		printf("Philo %d: thread %d\n", i, i);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 5)
// 	{
// 		if (pthread_join(philo[i], NULL) != 0)
// 		return (1);
// 		printf("Philo %d has eaten\n", i);
// 		i++;
// 	}
// 	printf("Total of %d philosophers have eaten\n", o);
// 	pthread_mutex_destroy(&mutex);
	
// 	return (0);
// }