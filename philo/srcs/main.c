/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:01:58 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/05 20:01:58 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void ft_failure(int errorcode)
// {
// 	if (errorcode == 1)
// 		printf("Please check the number of arguments\n");

// 	exit(errorcode);
// }

static void check_args(int ac, char **av)
{
	size_t	i;

	if (ac < 5 || ac > 6)
		ft_failure(1);		
	i = 1;
	while(av[i])
	{
		if ((!ft_is_digit(av[i])) || (!ft_atoi(av[i])))
			ft_failure(2);			
		i++;
	}
	if (ft_atoi(av[1]) == 1)
		ft_failure(10);
}

int main(int ac, char **av)
{
	t_input	input;

	check_args(ac, av);
	init_args(&input, ac, av);
	init_mutex(&input);
	init_philosophers(&input);
	init_threads(&input);
	end_threads(&input);
	unlock_and_destroy_mutex(&input);
	ft_free(&input);
	return (0);
}