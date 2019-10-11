/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/19 12:49:44 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/13 11:15:16 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"
# define WRONG_FLAGS -1
# define OK 1
# define END 0
# define MODULO -2

typedef struct					s_flags
{
	char						*conv;
	char						**flags;
	int							nb_arg;
	int							*i_modu;
	char						*line_arg;
	int							len_arg;
	int							len_format;
	int							sctch;
}								t_flags;

typedef struct					s_arg
{
	char						*flags;
	int							width;
	int							preci;
	char						*size;
	char						*content;
	char						type;
	int							c_i;
	struct s_arg				*next;
}								t_arg;

char							*di_cpy(char *buff, char *tmp, int ret);
int								clear_arg(t_arg *arg, int sig);
void							del_arg(t_arg *arg, int sig);
char							*join_c(char	*str, char c);
int								check_flags(const char *format, int
		i, t_flags *info);
void							count_arg(const char *format, t_flags *info);
t_flags							*ft_fill_list(void);
int								ft_printf(const char *format, ...);
int								ft_check_arg(const char	*format,
		t_flags *info, t_arg *arg);
t_arg							*fill_t_arg(t_flags *info, t_arg *arg);
int								chkflag(const char *format, t_flags *info,
		int i, t_arg *arg);
int								del_info(t_flags *info);
int								end(t_flags *info, t_arg *arg, int sig);
char							*test(t_arg *arg, t_flags *info, va_list ap);
char							*s_malloc_content(t_arg *arg, va_list ap);
char							*s_fill_content(t_arg *arg, va_list ap);
char							*s_fill_content2(char *buff, char *tmp,
		t_arg *arg, int ret);
char							*c_fill_content(t_arg *arg, va_list ap,
	t_flags *info);
char							*di_preci_malloc(t_arg *arg,
		char *tmp, int ret);
char							*di_fill_content(t_arg *arg,
		va_list ap, t_flags *info);
char							*di_flags(va_list ap,
		t_arg *arg, t_flags *info);
char							*di_width_malloc(char *tmp,
		t_arg *arg, int ret, char *buff);
char							*di_regular_flags(char *buff,
		char *tmp, t_arg *arg, int ret);
char							*di_plus_malloc(char *tmp, t_arg *arg);
int								new_format(char *nformat, t_arg *arg
	, t_flags *info, int y);
char							*init_nformat(const char *format,
		t_flags *info);
char							*concat_format(char	*nformat,
		t_flags *info, int i, int r);
char							*cat_format(char *nformat, t_arg *arg, int i);
char							*modul_fill_content(t_arg *arg, va_list ap);
char							*clear_nformat(char *nformat, int i);
char							*choose_ur_tmp(t_arg *arg, long long i);
char							*xxo_flags(va_list ap,
		t_arg *arg, t_flags *info);
char							*xxo_fill_content(t_flags *info,
		t_arg *arg, va_list ap);
char							*hashtag_flags(int i, char *tmp, t_arg *arg);
char							*xxo_preci_malloc(t_arg *arg,
		char *tmp, int i);
char							*xxo_width_malloc(t_arg
		*arg, char *tmp, int ret);
char							*u_fill_content(t_flags *info,
		t_arg *arg, va_list ap);
char							*u_flags(va_list ap, t_arg *arg, t_flags *info);
char							*u_preci_malloc(t_arg *arg, char *tmp, int ret);
char							*u_width_malloc(t_arg *arg, char *tmp, int ret);
char							*p_fill_content(t_arg *arg, va_list ap);
char							*p_va_arg(t_arg *arg, va_list ap);
char							*c_or_p(t_arg *arg, va_list ap, t_flags *info);
int								free_nformat(char *nformat, t_arg *arg,
	t_flags *info);
char							*last_check(char *buff, t_arg *arg);
char							*neg_value_xxo(char *tmp, t_arg *arg);
char							*neg_xx(char *tmp, t_arg *arg, int i);
char							*hashtag_width_neg_malloc(t_arg *arg,
	char *tmp, int ret);
char							*neg_xx_scotch(t_arg *arg);
char							*choosestr(t_arg *arg);
char							*c_width_malloc(int c, t_arg *arg);
char							*tmp_null(t_arg *arg);
char							scotch(t_arg *arg, char c, char b);
char							*real_last_check(char *buff);
int								count_len(char *nformat, t_arg *arg
	, t_flags *info);
char							*f_fill_content(t_arg *arg, va_list ap);
int								retrn(char *nformat);
char							*p_zero_flags(t_arg *arg, char *str,
	char *tmp, int ret);

typedef void			(*t_action[4])(char*);

#endif
