/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:25:10 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/22 13:40:18 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
#include <sys/time.h>

typedef struct s_state
{
	int	philos;
	int	to_die;
	int	to_eat;
	int	to_sleep;
	int	x_meals;

}	t_state;





typedef struct s_philo
{
	int x;
	
} t_philo;


typedef pthread_mutex_t		t_mutex;


//validate.c
int	validate_argc(int nbr_args);
int	validate_argv(t_state *state, char **argv);

//utils.c
void	ft_putendl_fd(char *s, int fd);
suseconds_t	atol_4time(char *nbr);

#endif