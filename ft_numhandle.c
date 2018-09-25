/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numhandle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:16:11 by azkeever          #+#    #+#             */
/*   Updated: 2018/09/24 15:52:46 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_numhandle(char c, va_list ap)
{
	char	*str;
	int		i;

	i = 0;
	if (c == 'd' || c == 'i')
	{
		i = va_arg(ap, int);
		str = ft_itoa_base(ft_abs(i), 10);
		i = (i > 0) ? 0 : 1;
	}
	else if (c == 'o')
		str = ft_itoa_base(va_arg(ap, unsigned int), 8);
	else if (c == 'u' || c == 'x')
		str = ft_itoa_base(va_arg(ap, unsigned int), (c == 'x') ? 16 : 10);
	if (c == 'p')
	{
		ft_putstr("0x");
		str = ft_itoa_base(va_arg(ap, unsigned long), 16);
		i += 2;
	}
	i += ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (i);
}
