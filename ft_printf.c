/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:16:45 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/20 20:27:06 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf		ft_initialize_fmt(void)
{
	t_pf	raw;

	raw.flag = 0;
	raw.field = 0;
	raw.precision = 0;
	raw.modif = 0;
	raw.spec = '\0';
	return (raw);
}

t_pf	ft_get_struct_info(const char *format, int i)
{
	t_pf	raw;

	raw = ft_initialize_fmt();
	while (ft_is_prefix(format[i]))
			raw.flag |= ft_prefix(format[i++]);
	if (format[i] >= '1' && format[i] <= '9')
		raw.field = ft_atoi(format + i);
	i = (raw.field) ? i + ft_rawlen(raw.field) : i;
	if (format[i] == '.')
	{
		i++;
		raw.flag += PRECISION;
		if (format[i] >= '0' && format[i] <= '9')
			{
				raw.precision = ft_atoi(format + i);
				i += ft_rawlen(raw.precision, 10);
			}
	}
	raw.modif = ft_modif(format[i], format[i + 1], format[i + 2], &i);
	raw.spec = format[i];
	return (raw);
}

int		ft_printf_wrapper(t_pf raw, va_list ap)
{
	if (raw.spec == 'c' || raw.spec == 's' || raw.spec == 'p')
		return (ft_csp_case(raw, ap));
	else if (raw.spec == 'd' || raw.spec == 'i')// || raw.spec == 'o' ||
		//		raw.spec == 'u' || raw.spec == 'x' || raw.spec == 'X')
		 return (ft_di_case(raw, ap));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_pf	fmt;
	int	i;
	int	j;

	i = 0;
	j = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			fmt = ft_get_struct_info(format, i);
			i += ft_interpretable(format, i) + 1;
			if (j > (j += ft_printf_wrapper(fmt, ap)))
					return (-1);
			//			if (j <= (j += ft_printf_wrapper(fmt, ap)))
			//					i += ft_interpretable(format, i) + 1;
		}
		else
		{
			write(1, &format[i++], 1);
			j++;
		}
	}
	va_end(ap);
	return (j);
}
