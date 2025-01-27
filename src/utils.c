/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:04:03 by anacaro5          #+#    #+#             */
/*   Updated: 2025/01/27 17:34:00 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	write (fd, s, len);
	write (fd, "\n", 1);
}

suseconds_t	atol_4time(char *nbr)
{
	char		sign;
	suseconds_t	nb;

	while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	sign = 0;
	if (*nbr == '+' || *nbr == '-')
		sign = *nbr++;
	nb = 0;
	while (*nbr >= '0' && *nbr <= '9')
		nb = (nb * 10) + *nbr++ - 48;
	if (sign == '-')
		nb = -nb;
	if (*nbr)
		return (false);
	return (nb);
}
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
