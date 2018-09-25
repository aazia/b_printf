/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cvhandle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:15:33 by azkeever          #+#    #+#             */
/*   Updated: 2018/09/24 14:35:44 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_cvhandle(char c, va_list ap)
{
	char *str;

	str = NULL;
	if (c == 'c' || c == '%')
	{
		(c == 'c') ? ft_putchar(va_arg(ap, int)) : ft_putchar('%');
		return (1);
	}
	else if (c == 's')
	{
		str = va_arg(ap, char *);
		ft_putstr(str);
		return (ft_strlen(str));
	}
	else
		return (ft_numhandle(c, ap));
	return (0);
}
