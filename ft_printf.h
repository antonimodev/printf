/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:14:22 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/09 11:39:21 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

void	ft_putchar_pf(va_list args);
void	ft_putstr_pf(va_list args);
void	ft_putptr_pf(va_list args);
void	ft_putnbr_pf(va_list args);
void	ft_putunsnbr_pf(va_list args);
void	ft_putminushex_pf(va_list args);
void	ft_putmayushex_pf(va_list args);
void	ft_aux_pf(char const *format, int *i, va_list args);
int		ft_printf(char const *format, ...);

#endif