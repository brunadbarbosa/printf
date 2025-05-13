/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:50:33 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/11 11:09:16 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int			ft_putchar(char c);
int			ft_puthex(unsigned long int n, int cas);
int			ft_putptr(void *s);
int			ft_putnbr(int n);
int			ft_putstr(char *s);
int			ft_printf(const char *format, ...);

#endif