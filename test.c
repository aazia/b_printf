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
