/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:18:07 by azkeever          #+#    #+#             */
/*   Updated: 2018/09/24 15:44:52 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_base(unsigned long n, int base)
{
	char	*str;
	char	*hex;
	int		i;

	i = ft_numlen(n, base);
	hex = "0123456789abcdef";
	str = (char *)malloc(sizeof(char) * (i + 1));
	ft_bzero(str, i + 1);
	str[0] = '0';
	str[i] = '\0';
	while (n)
	{
		str[--i] = hex[n % base];
		n /= base;
	}
	return (str);
}
