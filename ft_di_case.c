/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:53:31 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/20 20:21:39 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_append_di(long long int n, int base, t_pf raw)
{
	int j;

	j = 0;
	if (n == 0 && !raw.flag)
		j += ft_parser('0');
	else if (raw.flag & FLAG_MIN)
		j += ft_parse_after(raw, n, base);
	else if (!(raw.flag & PRECISION))
		j += ft_parse_before(raw, n, base);
	else
		j += ft_parse_between(raw, n, base);
	return (j);
}

int 	ft_di_case(t_pf raw, va_list ap)
{
	if ((raw.spec == 'd' || raw.spec == 'i') && !raw.modif)
		return (ft_append_di((int)va_arg(ap, intmax_t), 10, raw));
	else if ((raw.spec == 'd' || raw.spec == 'i') && raw.modif & LMODIF)
		return (ft_append_di((long)va_arg(ap, intmax_t), 10, raw));
	else if ((raw.spec == 'd' || raw.spec == 'i') && raw.modif & HMODIF)
		return (ft_append_di((short)va_arg(ap, intmax_t), 10, raw));
	else if ((raw.spec == 'd' || raw.spec == 'i') && raw.modif & LLMODIF)
		return (ft_append_di((long long)va_arg(ap, intmax_t), 10, raw));
	else if ((raw.spec == 'd' || raw.spec == 'i') && raw.modif & HHMODIF)
		return (ft_append_di((char)va_arg(ap, intmax_t), 10, raw));
	else
		return (-1);
}
