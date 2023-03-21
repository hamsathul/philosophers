/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:24:53 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/05 21:24:53 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_args(t_input *input, int ac, char **av)
{
	input->philo_nbr = ft_atoi(av[1]);
	input->time_to_die = ft_atoi(av[2]);
	input->time_to_eat = ft_atoi(av[3]);
	input->time_to_sleep = ft_atoi(av[4]);
	input->philo_death = 0;
	if (ac == 6)
		input->philo_nbr_meals = ft_atoi(av[5]);
	if (ac == 5)
	{
		if (input->philo_nbr < 1)
			return (0);
		input->philo_nbr_meals = -1;
	}
	if (ac == 6)
	{
		if (input->philo_nbr_meals < 1)
			return (0);
	}
	return (0);
}

void	init_mutex(t_input *input)
{
	int				nbr_philo;
	pthread_mutex_t	*mutex_philo;

	nbr_philo = input->philo_nbr;
	mutex_philo = malloc(sizeof(pthread_mutex_t) * nbr_philo);
	if (!mutex_philo)
		ft_failure(8);
	while (nbr_philo--)
	{
		if (pthread_mutex_init(&mutex_philo[nbr_philo], NULL) != 0)
			{
				free(mutex_philo);
				failure_and_free(5, input);

			}
			
	}		
	if (pthread_mutex_init(&input->lock_print, NULL) != 0)
		ft_failure(5);
	input->forks = mutex_philo;
}

void	init_threads(t_input *input)
{
	int	nbr_philo;
	pthread_t	*th;
	pthread_t	s_tid;
	nbr_philo = input->philo_nbr;
	th = malloc(sizeof(pthread_t) * nbr_philo);
	if (!th)
		ft_failure(8);
	while (nbr_philo--)
	{
		if (pthread_create(&th[nbr_philo], \
		 NULL,ft_process, (void *)&input->all_philos[nbr_philo] ) != 0 )
		 	{
				free(th);
				failure_and_free(6, input);
			}
	}
		
	if (pthread_create(&s_tid, NULL, ft_monitor, \
		 (void *)input->all_philos) != 0)
		ft_failure(6);
	if (pthread_join(s_tid, NULL) != 0)
		failure_and_free(7, input);
	input->thread_ids = th;
}

void	init_philosophers(t_input *input)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = malloc(sizeof(t_philo) * input->philo_nbr);
	if (!philos)
		ft_failure(8);
	while (i < input->philo_nbr)
	{
		philos[i].philo_id = i;
		philos[i].philo_nbr = input->philo_nbr;
		philos[i].total_nbr_meals = 0;
		philos[i].total_nbr_meals_option = input->philo_nbr_meals;
		philos[i].time_to_eat = input->time_to_eat;
		philos[i].time_to_sleep = input->time_to_sleep;
		philos[i].time_to_die = input->time_to_die;
		philos[i].time_of_last_meal = ft_time();
		philos[i].limit_of_life = input->time_to_die;
		philos[i].stop = 0;
		philos[i].left_fork = \
			&input->forks[philos[i].philo_id];
		philos[i].right_fork = \
			&input->forks[(philos[i].philo_id + 1) % input->philo_nbr];
		philos[i].input = input;
		i++;
	}
	input->all_philos = philos;
}