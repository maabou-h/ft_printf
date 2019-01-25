/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:32:33 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/24 19:11:51 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_before_x(t_pf *raw, uintmax_t n, int base)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = (raw->fl & F_H) ? 2 : 0;
	if (raw->fl & F_Z)
	{
		(raw->fl & F_H && n > 0) ? j += ft_parser('0') : 0;
		(raw->fl & F_H && n > 0) ? j += ft_parser('x') : 0;
		while (raw->fi-- > ft_rawlen(n, base) + j)
			i += ft_parser('0');
	}
	else
	{
		while (raw->fi-- > ft_rawlen(n, base) + k)
			i += ft_parser(' ');
		(raw->fl & F_H && n > 0) ? j += ft_parser('0') : 0;
		(raw->fl & F_H && n > 0) ? j += ft_parser('x') : 0;
	}
	j += ft_nbr_uns(n, base, raw, "0123456789abcdef");
	return (j + i);
}

int	ft_parse_between_x(t_pf *raw, uintmax_t n, int base)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = (raw->pr > ft_intlen(n, base)) ? raw->fi - raw->pr : raw->fi -
		ft_intlen(n, base);
	if (k < 0)
		k = 0;
	k = (raw->fl & F_H && n > 0) ? k + 2 : k;
	while (k--)
		j += ft_parser(' ');
	if (raw->fl & F_H && n > 0)
	{
		j += ft_parser('0');
		j += ft_parser('x');
	}
	while (raw->pr-- > ft_rawlen(n, base))
		i += ft_parser('0');
	if (n == 0 && raw->pr == -1 && (raw->fl & P_A))
		return (j + i);
	j += ft_nbr_uns(n, base, raw, "0123456789abcdef");
	return (j + i);
}

int	ft_parse_after_x(t_pf *raw, uintmax_t n, int base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (raw->fl & F_H && n > 0)
	{
		j += ft_parser('0');
		j += ft_parser('x');
	}
	if (raw->fl & P_A)
	{
		while (raw->pr-- > ft_rawlen(n, base))
			j += ft_parser('0');
	}
	j += ft_nbr_uns(n, base, raw, "0123456789abcdef");
	while (raw->fi-- > j)
		i += ft_parser(' ');
	return (j + i);
}