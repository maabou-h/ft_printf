/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:32:33 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/20 19:50:19 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_before(t_pf raw, long long n, int base)
{
	int i;
	int j;
  int k;

	i = 0;
	j = 0;
  k = (raw.flag & FLAG_SP || raw.flag & FLAG_PLS) ? 1 : 0;
	k = (raw.flag & PRECISION) ? k + 1 : k;
	if (raw.flag & FLAG_Z)
	{
		if (n < 0)
		{
			j += ft_parser('-');
			n = -n;
		}
		else if (raw.flag & FLAG_PLS && n >= 0)
			j += ft_parser('+');
		else if (raw.flag & FLAG_SP && n >= 0)
			j += ft_parser(' ');
		while (raw.field-- > ft_intlen(n, base) + j)
			i += ft_parser('0');
	}
	else
	{
		while (raw.field-- > ft_uintlen(n, base) + k)
			i += ft_parser(' ');
		if (n < 0)
		{
			j += ft_parser('-');
			n = -n;
		}
		else if (raw.flag & FLAG_PLS && n >= 0)
			j += ft_parser('+');
		else if (raw.flag & FLAG_SP && n >= 0)
			j += ft_parser(' ');
	}
	if (n > 0)
		ft_nbr_upp(n, base, raw);
	j += ft_uintlen(n, base);
	return (j + i);
}

int	ft_parse_between(t_pf raw, long long n, int base)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = (raw.precision > ft_intlen(n, base)) ? raw.field - raw.precision : raw.field - ft_intlen(n, base);
	if (n < 0)
		k--;
	if (k < 0)
		k = 0;
	if (raw.flag & PRECISION && raw.precision == 0 && n < 0)
		k++;
	while (k-- > ((raw.flag & FLAG_PLS || raw.flag & FLAG_SP) && n >= 0))
		j += ft_parser(' ');
	if (n < 0)
	{
		j += ft_parser('-');
		n = -n;
	}
	else if (raw.flag & FLAG_PLS && n >= 0)
		j += ft_parser('+');
	else if (raw.flag & FLAG_SP && n >= 0)
		j += ft_parser(' ');
	while (raw.precision-- > ft_uintlen(n, base))
		i += ft_parser('0');
	if (n > 0)
		ft_nbr_upp(n, base, raw);
	j += ft_uintlen(n, base);
	return (j + i);
}

int	ft_parse_after(t_pf raw, long long n, int base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (n < 0)
	{
		j += ft_parser('-');
		n = -n;
	}
	else if (raw.flag & FLAG_PLS && n >= 0)
		j += ft_parser('+');
	else if (raw.flag & FLAG_SP && n >= 0)
		j += ft_parser(' ');
	if (raw.flag & PRECISION)
		while (raw.precision-- > ft_intlen(n, base))
			j += ft_parser('0');
	if (n > 0)
		ft_nbr_upp(n, base, raw);
	j += ft_uintlen(n, base);
	while (raw.field-- > j)
		i += ft_parser(' ');
	return (j + i);
}
