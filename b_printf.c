/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:42:42 by azkeever          #+#    #+#             */
/*   Updated: 2018/09/22 17:39:42 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_numlen(unsigned long n, int base)
{
	int i;

	i = (!n) ? 1 : 0;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

void	ft_bzero(char *str, int len)
{
	while (str[len])
		str[len--] = 0;
}

int		ft_abs(int n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	return (n);
}

char	*ft_itoa_base(unsigned long n, int base)
{
	char *str;
	char *hex;
	int i;

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

int 	ft_numhandle(char c, va_list ap)
{
	char *str;
	int i;
	
	i = 0;
	if (c == 'd' || c == 'i')
	{
		i = va_arg(ap, int);
		str = ft_itoa_base(ft_abs(i), 10);
		(i > 0) ? (i = 0) : (i = 1);
	}
	else if (c == 'o')
		str = ft_itoa_base(va_arg(ap,unsigned int), 8);
	else if (c == 'u')
		str = ft_itoa_base(va_arg(ap, unsigned int), 10);
	else if (c == 'x')
		str = ft_itoa_base(va_arg(ap, unsigned int), 16);
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

int		b_printf(char *str, ...)
{
	int i;
	int j;
	va_list ap;

	i = 0;
	j = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			j += ft_cvhandle(str[++i], ap);
		else
		{
			ft_putchar(str[i]);
			j++;
		}
		i++;
	}
	return (j);
}

int    main(void)
{
    int    i;
    unsigned int    ui;
    char    str[] = "brian is the man";
    int        nums[] = {0 , 0, 0, 0, 5};
    void    *vp1;
    void    *vp2;

    i = -2422425;
    ui = 3147483647;
    vp1 = str;
    vp2 = nums;
    printf("%d \n", b_printf("%c %s %d %u %p %p %o %x hi \n", 'a', "abc", i, ui, vp1, vp2, ui, ui));
    printf("%d \n", printf("%c %s %d %u %p %p %o %x hi \n", 'a', "abc", i, ui, vp1, vp2, ui, ui));
    return (0);
}
