/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 19:16:42 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/20 20:26:58 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int		ft_intlen(intmax_t nbr, int base)
{
	int	i;

	i = (nbr < 0) ? 2 : 1;
	nbr = (nbr < 0) ? -nbr : nbr;
	if (nbr == 0)
		return (0);
	while (nbr /= base)
		i++;
	return (i);
}

unsigned int		ft_rawlen(intmax_t nbr)
{
	int	i;

	i = 1;
	nbr = (nbr < 0) ? -nbr : nbr;
	while (nbr /= 10)
		i++;
	return (i);
}

unsigned int		ft_uintlen(intmax_t nbr, int base)
{
	int	i;

	i = 1;
	nbr = (nbr < 0) ? -nbr : nbr;
	if (nbr == 0)
		return (0);
	while (nbr /= base)
		i++;
	return (i);
}

int ft_parser(char c)
{
	if (!c)
		return (-1);
	write(1, &c, 1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	ret;

	i = 0;
	ret = 0;
	if (str)
	{
		while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
			i++;
		while (str[i] <= '9' && str[i] >= '0')
		{
			ret *= 10;
			ret += str[i++] - '0';
		}
	}
	return (ret);
}

int	ft_nbr_upp(long long int n, int base, t_pf raw)
{
	char	*radix;
	uintmax_t	nbr;
	int		j;

	radix = "0123456789ABCDEF";
	j = 0;
	nbr = (n < 0) ? -n : n;
	if (nbr >= (uintmax_t)base)
	{
		ft_nbr_upp(nbr / base, base, raw);
		ft_nbr_upp(nbr % base, base, raw);
	}
	else
	{
		write(1, &radix[nbr], 1);
		j++;
	}
	return (j);
}
