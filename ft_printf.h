/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:53:43 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/19 17:58:28 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <wchar.h>
#include <stdio.h> // test phase
#include <unistd.h>
#include <float.h>
#include <stdlib.h>
#include <stdarg.h>

# define FLAG_HT 2
# define FLAG_Z 4
# define FLAG_MIN 8
# define FLAG_PLS 16
# define FLAG_SP 32
# define PRECISION 64

# define LMODIF 2
# define HMODIF 4
# define LLMODIF 8
# define HHMODIF 16

typedef struct	s_pf
{
	int			flag;
	int 		field;
	int			precision;
	int			modif;
	char		spec;
}				t_pf;


#endif
