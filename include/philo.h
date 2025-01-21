/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:25:10 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/21 20:17:48 by anacaro5         ###   ########.fr       */
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

void	ft_putendl_fd(char *s, int fd);

#endif