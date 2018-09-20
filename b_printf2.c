/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 22:03:37 by azkeever          #+#    #+#             */
/*   Updated: 2018/09/19 23:30:35 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		cvhandle(char c, va_list ap)
{
	char *str;
	int i;

	i = 0;
	if (c == 's')
		str = va_arg(ap, char *);
	else if (c == 'd' || c =='i')
		str = ft_itoa(10, ft_abs(va_arg(ap, int)));
	else if (c == 'p')
		str = ft_itoa(16, va_arg(ap, unsigned long));
	else if (c == 'o')
		str = ft_itoa(8, va_arg(ap,  unsigned int));
	else if (c == 'u')
		str = ft_itoa(10, va_arg(ap, unsigned int));
	else if (c == 'x')
		str = ft_itoa(16, va_arg(ap,  unsigned int));
	else
	{
		if (c == 'c')
			ft_putchar(va_arg(ap, int)):
		else
			ft_putchar('%');
		i++;
	}
	if (c != 'c')
	{
		if (c == 'p')
		{
			i += 2;
			ft_putstr("0x");
		}
		ft_putstr(str);
		i += ft_strlen(str);
		if (c != 's')
			free(str);
	}
	return (i);
}

int		b_printf(char *str, ...)
{
	int		i;
	va_list	ap;
	int		j;

	i = 0;
	j = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			j += cvhandle(str[++i], ap);
		}
		else
		{
			ft_putchar(str[i]);
			j++;
		}
		i++;
	}
	return (j);
}
