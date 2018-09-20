/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:24:15 by azkeever          #+#    #+#             */
/*   Updated: 2018/09/20 12:32:03 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		ft_abs(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	return ((unsigned long)(nb));
}

void	ft_bzero(void *s, size_t n)
{
	char *ptr;

	ptr = s;
	while (n-- != 0)
	{
		*(ptr++) = 0;
	}
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_numsize(unsigned long nbr, int base)
{
	int count;

	count = (!nbr) ? 1 : 0;
	while (nbr != 0)
	{
		nbr /= base;
		count++;
	}
	return (count);
}

char	*ft_itoa(unsigned int base, unsigned long nbr)
{
	char *str;
	char *tab;
	int	nb;
	int nb2;

	nb = ft_numsize(nbr, base);
	nb2 = nb;
	str = (char *)malloc(sizeof(char) * (nb + 1));
	ft_bzero(str, nb + 1);
	str[0] = '0';
	tab = "0123456789abcdef";
	while (nbr != 0)
	{
		str[--nb] = tab[nbr % base];
		nbr /=base;
	}
	str[nb2] = '\0';
	return (str);
}

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
	else if (c == 'c')
	{
		i++;
		ft_putchar(va_arg(ap, int));
	}
	else
	{
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
	int i;
	va_list ap;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
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

int    main(void)
{
    int    i;
    unsigned int    ui;
    char    str[] = "brian is the man";
    int        nums[] = {1 , 2, 3, 4, 5};
    void    *vp1;
    void    *vp2;

    i = 2147483647;
    ui = 3147483647;
    vp1 = str;
    vp2 = nums;
    printf("%d \n", b_printf("%c %s %d %u %p %p %o %x hi \n", 'a', "abc", i, ui, vp1, vp2, ui, ui));
    printf("%d \n", printf("%c %s %d %u %p %p %o %x hi \n", 'a', "abc", i, ui, vp1, vp2, ui, ui));
    return (0);
}
