/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:09:19 by azkeever          #+#    #+#             */
/*   Updated: 2018/09/24 15:45:06 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		*ft_memset(void *b, int c, size_t len);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isdigit(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_bzero(char *str, int len);
int			ft_numlen(unsigned long n, int base);
int			ft_numhandle(char c, va_list ap);
int			ft_cvhandle(char c, va_list ap);
int			b_printf(char *str, ...);
char		*ft_itoa_base(unsigned long n, int base);
int			ft_abs(int n);
#endif
