/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 21:59:21 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:59:24 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include "../libft/libft.h"

char	*ft_get_num(const char *c, void *val);
char	*ft_get_str(const char *c, void *val);
char	*ft_itoa(int n);
char	*ft_gethex(unsigned int i, int up);
char	*ft_getptr(unsigned long ptr);
char	*ft_reverse(char *str);
char	*ft_strdup(const char *s1);
char	*ft_tostr(char c);
char	*ft_utoa(unsigned int n);
int		ft_asterisk_count(const char *c);
int		ft_atoi(const char *str);
int		ft_contains(const char *arr, char *c, int len);
int		ft_filter_var(int x, char *c);
int		ft_isalpha(int c);
int		ft_isflag(int c);
int		ft_isnum(int c);
int		ft_print_c(char *str, int prc, char flag, int size);
int		ft_print_num(char *str, int prc, char flag, int size);
int		ft_print_p(char *str, int prc, char flag, int size);
int		ft_print_str(char *str, int prc, char flag, int size);
int		ft_print_type(const char *c, int size, int prc, void *val);
int		ft_print_xchar(char c, int count);
int		ft_printf(const char *input, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putstrl(char *s, int max);

#endif
