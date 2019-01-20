/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:57:18 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/19 19:30:31 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



size_t		ft_is_prefix(char c)
{
	if (c == '#' || c == '0' || c == '+' || c == '-' || c == ' ')
		return (1);
	else
		return (0);
}

size_t		ft_is_spec(char c)
{
	if (c == 'd' || c =='i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' ||
			c == 'b' || c == 'c' || c == 's' || c == 'p' || c == 'f')
		return (1);
	else
		return (0);
}

size_t		ft_interpretable(char const *format, int pos)
{
	size_t	j;

	j = 0;
	if (!format)
		exit(-1);
	while (!ft_is_spec(format[pos++]))
		j++;
	return (j);
}

int		ft_prefix(char spec)
{
	if (spec == '#')
		return (FLAG_HT);
	else if (spec == '0')
		return (FLAG_Z);
	else if (spec == '-')
		return (FLAG_MIN);
	else if (spec == '+')
		return (FLAG_PLS);
	else if (spec == ' ')
		return (FLAG_SP);
	else
		return (0);
}

int		ft_modif(char c, char d, char e, int *i)
{
	if (c == 'l' && (ft_is_spec(d)))
	{
		*i += 1;
		return (LMODIF);
	}
	else if (c == 'h' && (ft_is_spec(d)))
	{
		*i += 1;
		return (HMODIF);
	}
	else if (c == 'l' && d == 'l' && (ft_is_spec(e)))
	{
		*i += 2;
		return (LLMODIF);
	}
	else if (c == 'h' && d == 'h' && (ft_is_spec(e)))
	{
		*i += 2;
		return (HHMODIF);
	}
	else
		return (0);
}
