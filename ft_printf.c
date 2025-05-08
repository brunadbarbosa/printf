/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:33:55 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/08 09:41:35 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void    ft_printchar(char c, int *count)
{
    write(1, &c, 1);
    *count += 1;
}

ft_check (char format, va_list args, int *count)
{
    
}

ft_validate(char format)
{
    char    check;
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
            ft_printchar(ft_check(format[i], args, &count););
        }
        else
            ft_printchar(format[i], &count);
        i++;
    }
    return (count);
}

/*#include <stdio.h>
int main()
{
    int a;
    int b;
    a =    printf("Meu char: %c\n", 't');
    b = ft_printf("Meu char: %c\n", 't');

    printf("%d %d\n", a, b);
}*/