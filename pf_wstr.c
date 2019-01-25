/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putwchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:33:51 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/25 21:57:44 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "ft_printf.h"

size_t	ft_wclen(wchar_t c)
{
	if (c <= 0x07F)
		return (1);
	if (c <= 0x7FF)
		return (2);
	if (c <= 0xFFFF)
		return (3);
	if (c <= 0x10FFFF)
		return (4);
	return (0);
}

size_t	ft_wslen(wchar_t *sc)
{
	size_t i;

	i = 0;
	while (sc[i])
		i += 1;
	return (i);
}

size_t	ft_wctomb(char *str, wchar_t c)
{
	if (c <= 0x7FF)
	{
		str[0] = 0xC0;
		return 2;
	}
	else if (c <= 0xFFFF)
	{
		str[0] = 0xE0;
		return 3;
	}
	else if (c <= 0x1FFFFF)
	{
		str[0] = 0xF0;
		return 4;
	}
	return (0);
}

size_t	ft_putwchar(wchar_t c)
{
	char	*result;
	int		bytes;
	int		ct;

	if (!(result = (char*)malloc(sizeof(char) * ft_wclen(c))))
		return (NULL);
	if (ft_wclen(c) == 1)
	{
		write(1, &c, 1);
		free(result);
		return (1);
	}
	bytes = ft_wctomb(result, c);
	ct = ft_wclen(c);
	while (--ct > 0)
	{
		result[ct] = 0x80 | (c & 0x3F);
		c = c >> 6;
	}
	result[0] = result[0] | c;
	write(1, result, bytes);
	free(result);
	return (bytes);
}

size_t	ft_putwstr(wchar_t *sc)
{
	size_t	i;

	i = 0;
	if (!sc)
		return (NULL);
	while (sc[i])
		ft_putwchar(sc[i++]);
	return (i);
}
