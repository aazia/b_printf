/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 14:22:36 by azkeever          #+#    #+#             */
/*   Updated: 2018/09/18 16:30:56 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strdup(const char *s1)
{
	char	*d;

	d = (char *)malloc(ft_strlen(s1) + 1);
	if (d == NULL)
		return (NULL);
	ft_strcpy(d, s1);
	return (d);
}
