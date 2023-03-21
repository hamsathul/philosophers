/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:46:42 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/15 20:46:42 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <pthread.h>
# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>
# include "philo_bonus.h"

typedef struct s_philo
{
	pthread_t	thread_id;
	sem_t		*actions;
	size_t		philo_id;
	size_t		total_nbr_of_meals;
	size_t		time_of_last_meal;
	int			nbr_of_meals;
}	t_philo;

typedef struct s_input
{
	pthread_t	thread_id;
	pid_t		*pid_philo;
	sem_t		*write_sem;
	sem_t		*fork_sem;
	sem_t		*stop;
	sem_t		*eat_enough;
	int			philo_nbr;
	time_t		start_time;
	time_t		time_to_die;
	time_t		time_to_eat;
	time_t		time_to_sleep;
	size_t		nbr_of_meals;
	t_philo		philo;
}	t_input;

void	ft_failure(int errorcode);
long	ft_time(void);
void	ft_usleep(int ms);
int		ft_atoi(const char *str);
int		ft_is_digit(char *str);
void	init_philo(t_input *input);
void	init_args(t_input *input, int ac, char **av);
void	start_process(t_input *input);
void	kill_process(t_input *input);
void	*ft_process(void *input);
void	*eating_checker(void *input);
void	*death_checker(void *input);

#endif