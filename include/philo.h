/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:25:10 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/30 19:12:46 by anacaro5         ###   ########.fr       */
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
# include <sys/time.h>

# define THE_END "\033[0;91mDEATH TORE US APART\033[0m"
# define RIGHT_F "has taken the right fork"
# define LEFT_F "has taken the left fork"
# define EATING "is feasting on a banquet!!"
# define SLEEP "ZZzzzZzzZZZZZzzzz"
# define THINK "is thinking about the world"  

typedef pthread_mutex_t		t_mutex;

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

typedef struct s_philo
{
	int			nbr;
	int			meals;
	_Bool		is_dead;
	t_mutex		nbr_of_meals_locker;
	t_mutex		*right_fork;
	t_mutex		*left_fork;
	suseconds_t	last_meal;
	t_state		*state;
	pthread_t	own_thread;

}	t_philo;

//main.c
int			main(int argc, char **argv);

//manage.c
void		*manage(void *param);
_Bool		count_meals_n_check_death(t_philo *philo, int *meals);
void		print_on_terminal(t_philo *philo, char *action);
suseconds_t	time_now(void);

//philos.c
void		philo_by_philo(t_state *state, t_philo *philo, t_mutex *fork);
void		create_threads(t_state *state, t_philo *philo);

//rest.c
void		rest(t_philo *philo);

//theorize.c
void		theorize(t_philo *philo);

//devour.c
void		devour(t_philo *philo);

//routine.c
void		*routine(void *arg);
_Bool		is_dead(t_philo *philo);
_Bool		is_fed(t_philo *philo);

//utils.c
void		ft_putendl_fd(char *s, int fd);
suseconds_t	atol_4time(char *nbr);
int			ft_strcmp(char *s1, char *s2);
void		my_sleep(suseconds_t milliseconds);
void		bye_bye(t_state *state, t_philo *philo);

//validate.c
int			validate_argc(int nbr_args);
int			validate_argv(t_state *state, char **argv);
int			is_positive_number(char **argv);

#endif