/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:33:55 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/10 11:59:57 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_puthex(unsigned long int n, int cas)
{
    char    *base;
    int     i;

    i = 0;
    if (cas)
        base = "0123456789ABCDEF";
    else
        base = "0123456789abcdef";
    if (n > 15)
        i = i + ft_puthex((n / 16), cas);
    i = i + ft_putchar(base[n % 16]);
    return (i);
}

int ft_putptr(void *s)
{
    if (!s)
        return (ft_putstr("(nil)"));
    return (ft_putstr("0x") + ft_puthex((unsigned long)s, 0));
}

int	ft_putnbr(long int n)
{
    int i;

    i = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		i = i + ft_putchar('-');
		n = n * (-1);
	}
	if (n > 9)
		i = i + ft_putnbr(n / 10);
	i = i + ft_putchar((n % 10) + 48);
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
    return (i);
}

static int  ft_check(char format, va_list args)
{  
    if (format == '%')
       return (ft_putchar('%'));
    else if (format == 'd' || format == 's')
        return (ft_putnbr(va_arg(args, int)));
    else if(format == 'u')
        return (ft_putnbr(va_arg(args, unsigned int)));
    else if(format == 'x')
        return (ft_puthex(va_arg(args, unsigned int), 0));
    else if(format == 'X')
        return (ft_puthex(va_arg(args, unsigned int), 1));
    else if (format == 's')
        return (ft_putstr(va_arg(args, char *)));
    else if (format == 'c')
        return (ft_putchar(va_arg(args, char)));
    else if(format == 'p')
        return (ft_putptr(va_arg(args, void *)));
    else
        return (0);
}

int ft_validate(char format)
{
    char    *check;
    int     i;
    
    check = "cspdiuxX%";
    i = 0;
    while (check[i])
    {
        if (format == check[i])
            return (1);
        i++;
    }
    return (0);
}

int ft_printf(const char *format, ...)
{
    va_list args; 
    int     i;
    int     count;

    va_start(args, format);
    count = 0;
    i = 0;
    if(!format)
        return (0);
    while (format[i])
    {
        if(format[i] == '%' && ft_validate(format[i + 1]))
        {
            i++; 
            count = count + ft_check(format[i], args);
        }
        else
            count = count + ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (count);
}

/*#include <stdio.h>
int main()
{
    int a;
    //int b;
    a =    printf("Meu char: %c %d\n", 3, 't');
   // b = ft_printf("Meu char: %c\n", 't');

    printf("%d \n", a);
}*/