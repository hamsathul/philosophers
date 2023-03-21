/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:35:16 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/15 22:35:16 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void taking_forks_and_eating(t_input *input)
{
	sem_wait(input->fork_sem);
	sem_wait(input->fork_sem);
	sem_wait(input->write_sem);
	printf("\033[1;32m");
	printf("%ld philosopher %lu has taken a fork\n", \
		ft_time() - input->start_time, input->philo.philo_id + 1);
	printf("\033[0m");
	printf("\033[1;33m");
	printf("%ld philosopher %lu has taken a fork\n", \
		ft_time() - input->start_time, input->philo.philo_id + 1);
	printf("\033[0m");
	sem_post(input->write_sem);
	sem_wait(input->write_sem);
	printf("\033[1;36m");
	printf("%ld philosopher %lu is eating\n", \
		ft_time() - input->start_time, input->philo.philo_id + 1);
	printf("\033[0m");
	sem_post(input->write_sem);
	input->philo.time_of_last_meal = ft_time();
	input->philo.total_nbr_of_meals += 1;
	if (input->philo.total_nbr_of_meals == input->nbr_of_meals)
		sem_post(input->eat_enough);
	ft_usleep(input->time_to_eat);
	sem_post(input->fork_sem);
	sem_post(input->fork_sem);
}

void	sleeping_and_thinking(t_input *input)
{
	sem_wait(input->write_sem);
	printf("\033[1;35m");
	printf("%ld philosopher %lu is sleeping\n", \
		ft_time() - input->start_time, input->philo.philo_id + 1);
	printf("\033[0m");
	sem_post(input->write_sem);
	ft_usleep(input->time_to_sleep);
	sem_wait(input->write_sem);
	printf("\033[1;34m");
	printf("%ld philosopher %lu is thinking\n", \
		ft_time() - input->start_time, input->philo.philo_id + 1);
	printf("\033[0m");
	sem_post(input->write_sem);
}

void	*ft_process(void *input)
{
	t_input	*philo;

	philo = (t_input *)input;
	philo->start_time = ft_time();
	while (1)
	{
		taking_forks_and_eating(philo);
		sleeping_and_thinking(philo);
	}
	return (NULL);
}

void	*eating_checker(void *input)
{
	t_input *philo;
	int		i;

	philo = (t_input *)input;
	i = -1;
	sem_wait(philo->write_sem);
	while (++i < philo->philo_nbr)
	{
		sem_post(philo->write_sem);
		sem_wait(philo->eat_enough);
		sem_wait(philo->write_sem);
	}
	sem_post(philo->stop);
	return (NULL);
}

void	*death_checker(void *input)
{
	t_input	*philo;
	long	time_now;

	philo = (t_input *)input;
	while (1)
	{
		time_now = ft_time();
		if ((time_t)(time_now - philo->philo.time_of_last_meal) > philo->time_to_die)
		{
			sem_wait(philo->write_sem);
			printf("\033[1;31m");
			printf("%ld philosopher %lu died\n", \
				ft_time() - philo->start_time, philo->philo.philo_id + 1);
			printf("\033[0m");
			sem_post(philo->stop);
			free(philo->pid_philo);
			exit(0);
		}
	}
	return (NULL);
}