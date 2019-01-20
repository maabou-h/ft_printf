/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csp_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 19:16:50 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/20 16:02:07 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	ft_putchar(unsigned char c, t_pf raw)
{
	if (raw.flag & FLAG_MIN)
		write(1, &c, sizeof(c));
	while (raw.field-- > 1)
		write(1, " ", 1);
	if (!(raw.flag & FLAG_MIN))
		write(1, &c, sizeof(c));
	return (1);
}

int	ft_putstr(char const *s, t_pf raw)
{
	int i;
	int j;
	int k;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	j = 0;
	k = (raw.precision) ? raw.precision : ft_strlen(s);
	i = raw.field - k;
	if (raw.flag & FLAG_MIN)
		write(1, s, k);
	while (i-- > 0)
	{
		write(1, " ", 1);
		j++;
	}
	if (!(raw.flag & FLAG_MIN))
		write(1, s, k);
	return (k + j);
}

int		ft_csp_case(t_pf raw, va_list ap)
{
	if (raw.spec == 'c' && !raw.precision && !raw.flag)
		return (ft_putchar((unsigned char)va_arg(ap, int), raw));
	else if (raw.spec == 's')
		return (ft_putstr(va_arg(ap, char*), raw));
	else if (raw.spec == 'p')
	{
		write(1, "0x", 2);
		return (ft_nbr_upp((long long)va_arg(ap, void*), 16, raw) + 2);
	}
	else
		exit(0);
	return (0);
}
