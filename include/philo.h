/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:25:10 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/22 17:18:43 by anacaro5         ###   ########.fr       */
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

typedef struct s_philo
{
	int			nbr;
	int			meals;
	_Bool		is_dead;
	t_mutex		nbr_of_meals_locker;
	t_mutex		*right_fork;
	t_mutex		*left_fork;
	suseconds_t	last_meal;
	t_state		*philo_state;
	pthread_t	own_thread;

}	t_philo;


typedef struct s_state
{
	int			philos_qty;
	int			x_meals;
	suseconds_t	to_die;
	suseconds_t	to_eat;
	suseconds_t	to_sleep;
	suseconds_t	initial_time;
	_Bool		is_dead;
	t_mutex		death_locker;
	t_mutex		writting_locker;
	pthread_t	manager;
}	t_state;







typedef pthread_mutex_t		t_mutex;


//validate.c
int	validate_argc(int nbr_args);
int	validate_argv(t_state *state, char **argv);

//utils.c
void	ft_putendl_fd(char *s, int fd);
suseconds_t	atol_4time(char *nbr);

#endif