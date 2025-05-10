/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:33:55 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/09 18:11:18 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int    ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
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

static int  ft_check(char format, va_list args, int *count)
{  
    if (format == '%')
       return (ft_putchar('%'));
    else if (format == 'd' || format == 's')
    {
        *count++;
        return (ft_putnbr(va_arg(args, int)));
    }
    else if(format == 'u')
    {
        *count++;
        return (ft_putnbr(va_arg(args, unsigned int)));
    }
    else if(format == 'x')
    {
        *count++;
        return (ft_puthex(va_arg(args, unsigned int), 0));
    }
    else if(format == 'X')
    {
        *count++;
        return (ft_puthex(va_arg(args, unsigned int), 1));
    } 
    else if (format == 's')
    {
        *count++;
        return (ft_putstr(va_arg(args, char *)));
    }
    else if (format == 'c')
        return (ft_putchar(va_arg(args, char)));
    else if(format == 'p')
    {
        count++;
        return (ft_putptr(va_arg(args, void *)));
    }
    else
        return (0);
}

ft_validate(char format)
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
            ft_check(format[i], args, &count);
        }
        else
            ft_printchar(format[i], &count);
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