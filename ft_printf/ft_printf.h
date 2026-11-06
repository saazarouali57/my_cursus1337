/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazaroua <sazaroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:52:03 by username          #+#    #+#             */
/*   Updated: 2026/11/06 20:18:15 by sazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*------------ library -------------*/
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/*------------ functions ------------*/
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_nbr(int n);
int	ft_print_unsigned_nbr(unsigned int n);
int	ft_print_hex(unsigned int nb, char format);
int	ft_print_adrees(unsigned long long n);
int	ft_printf(const char *s, ...);
#endif
