/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:36:43 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/29 17:02:34 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	(void)argv;

	t_state	state;
	t_philo	philo[200];
	t_mutex	fork[200];
	int i;
	char	*arg;

	i = 1;
	arg = argv[i];
	state = (t_state){0};
	while (i < argc)
	{
		arg = argv[i];
		while (*arg >= '0' && *arg <= '9')
			arg++;
		if (*arg != '\0')
		{
			ft_putendl_fd("Wisdom: try positive numbers.", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (validate_argc(argc))
		return (EXIT_FAILURE);
	if (validate_argv(&state, argv))
	{
		ft_putendl_fd("Thy choices have been unwise.", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	philo_by_philo(&state, philo, fork);
	create_threads(&state, philo);
	bye_bye(&state, philo);
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