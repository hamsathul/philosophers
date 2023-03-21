/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:07:37 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/15 21:07:37 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	start_process(t_input *input)
{
	int	i;

	i = 0;
	input->start_time = ft_time();
	while (i < input->philo_nbr)
	{
		input->philo.philo_id = i;
		input->pid_philo[i] = fork();
		if (input->pid_philo[i] == -1)
		{
			while (--i >= 0)
				kill(input->pid_philo[i], SIGKILL);
			ft_failure(8);
		}
		else if (input->pid_philo[i] == 0)
		{
			init_philo(input);
			ft_process(input);
		}
		i++;
	}
	sem_wait(input->stop);
}

void kill_process(t_input *input)
{
	int	i;

	i = 0;
	while( i < input->philo_nbr)
	{
		kill(input->pid_philo[i], SIGKILL);
		i++;
	}
	free(input->pid_philo);
}

void	check_args(int ac, char **av)
{
	size_t	i;

	if (ac < 5 || ac > 6)
		ft_failure(2);		
	i = 1;
	while(av[i])
	{
		if ((!ft_is_digit(av[i])) || (!ft_atoi(av[i])))
			ft_failure(3);			
		i++;
	}
	if (ft_atoi(av[1]) == 1)
		ft_failure(4);
}
int	main(int ac, char **av)
{
	t_input	input;

	check_args(ac, av);
	init_args(&input, ac, av);
	start_process(&input);
	kill_process(&input);
}