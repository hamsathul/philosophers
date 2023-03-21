/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:15:43 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/15 21:15:43 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	init_philo(t_input *input)
{
	input->philo.time_of_last_meal = ft_time();
	if (pthread_create(&input->thread_id, NULL, &death_checker, input))
	{
		ft_failure(7);
		sem_post(input->stop);
	}
	pthread_detach(input->thread_id);
}

static void	init_thread(t_input *input)
{
	if (input->nbr_of_meals)
	{
		if (pthread_create(&input->thread_id, NULL, &eating_checker, input))
			ft_failure(7);
		pthread_detach(input->thread_id);
	}
}

static void	init_semaphore(t_input *input)
{	
	sem_unlink("fork_sem");
	sem_unlink("write_sem");
	sem_unlink("stop");
	sem_unlink("eat_enough");
	input->fork_sem = sem_open("fork_sem", O_CREAT | \
		O_EXCL, S_IRWXU, input->philo_nbr);
	input->write_sem = sem_open("write_sem", O_CREAT | O_EXCL, S_IRWXU, 1);
	input->stop = sem_open("stop", O_CREAT | O_EXCL, S_IRWXU, 0);
	if (input->nbr_of_meals)
		input->eat_enough = sem_open("eat_enough", O_CREAT | O_EXCL, S_IRWXU, 0);
}

void	init_args(t_input *input, int ac, char **av)
{
	memset(input, 0, sizeof(t_input));
	input->philo_nbr = ft_atoi(av[1]);
	input->time_to_die = ft_atoi(av[2]);
	input->time_to_eat = ft_atoi(av[3]);
	input->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		input->nbr_of_meals = ft_atoi(av[5]);
	input->pid_philo = malloc(sizeof(pid_t) * input->philo_nbr);
	if (!input->pid_philo)
		ft_failure(6);
	if (ac == 5)
	{
		if (input->philo_nbr < 1)
			ft_failure(5);
		input->nbr_of_meals = -1;
	}
	if (ac == 6)
	{
		if (input->nbr_of_meals < 1)
			ft_failure(6);
	}
	memset(input->pid_philo, 0, sizeof(pid_t) * input->philo_nbr);
	init_semaphore(input);
	init_thread(input);	
}