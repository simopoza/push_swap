/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 03:43:15 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/30 18:09:15 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_help_atoi(int rus)
{
	(void)rus;
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int					sign;
	long int			rus;
	unsigned long int	i;

	sign = 1;
	rus = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!ft_strncmp(str, "-2147483648", 12))
		return (-2147483648);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		rus = (rus * 10) + (str[i] - 48);
		i++;
		if (rus <= -2147483648 || rus > 2147483647)
			ft_help_atoi(rus);
	}
	return (rus * sign);
}
