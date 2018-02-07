/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 22:14:30 by ibonifac          #+#    #+#             */
/*   Updated: 2018/02/06 12:16:13 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

typedef enum		e_size
{
	NONE, HH, H, LL, L, J, Z
}					t_size;

typedef struct		s_join
{
	char			*str;
	int				size;
	int				instruct;
	struct s_join	*next;
}					t_join;

# define NOTHING	0
# define SHARP		1
# define F_ZERO		2
# define PLUS		4
# define MINUS		8
# define SPACE		16
# define PRECISION	32
# define S			64
# define S_CAP		128
# define P			256
# define D			512
# define D_CAP		1024
# define I			2048
# define O			4096
# define O_CAP		8192
# define U			16384
# define U_CAP		32768
# define X			65536
# define X_CAP		131072
# define C			262144
# define C_CAP		524288
# define MODULO		1048576

typedef struct		s_flags
{
	int				length_modif;
	int				sharp;
	int				zero;
	int				plus;
	int				minus;
	int				space;
	int				field_width;
	int				precision;
	int				precision_value;
	int				length;
	char			*sign;
}					t_flags;

typedef struct		s_split_tool
{
	intmax_t	i;
	size_t		start;
	size_t		len;
}					t_split_tool;

int					ft_printf(const char *format, ...);
int					check_the_line(const char *format);
int					first_step(const char *format, t_split_tool *tool,
					t_join *lst, va_list arg);
void				make_the_list(const char *format, t_split_tool *tool,
					t_join *lst);
short				is_instruct(int c);
t_join				*new_lst(void);
t_join				*sort_str(const char *format, t_split_tool *tool,
					t_join *lst);
void				free_the_lst(t_join *lst);
t_flags				*check_all_flags(t_join *lst, t_split_tool *tool,
					t_flags *flags);
t_join				*make_the_conv_begin(t_join *lst, t_split_tool *tool,
					t_flags *flags, va_list arg);
t_flags				init_flags(void);
t_split_tool		init_tool(void);
char				*itoa_base(intmax_t n, intmax_t base);
intmax_t			set_signed(t_flags *flags, va_list arg);
uintmax_t			set_unsigned(t_flags *flags, va_list arg);
t_join				*conv_set(t_join *lst, t_flags *flags, va_list arg);
t_join				*type_dui(t_flags *flags, uintmax_t num, t_join *lst);
t_join				*type_o(t_flags *flags, uintmax_t num, t_join *lst);
t_join				*type_xp(t_flags *flags, uintmax_t num, t_join *lst);
t_join				*type_x_cap(t_flags *flags, uintmax_t num, t_join *lst);
t_join				*type_c(t_flags *flags, t_join *lst, char c);
t_join				*type_s(t_flags *flags, t_join *lst, char *s);
t_join				*type_wc(t_flags *flags, t_join *lst, wint_t wc);
t_join				*type_ws(t_flags *flags, t_join *lst, wchar_t *ws,
					int size);
t_join				*print_wstr(t_flags *flags, t_join *lst, wchar_t *wstr);
char				*replace_str(char *dst, char *src, int option);
char				*space_x_num(t_flags *flags, char *str);
char				*set_space(int len, int min, char *tmp);
char				*set_zero_left(int len, int min, char *tmp);
int					o_len(int option, int add);
void				check_wchar(t_join *lst, wint_t wint);
char				*ft_itoa_base(uintmax_t n, uintmax_t base);
intmax_t			set_sign(t_flags *flags, intmax_t nb);
int					is_escapable(int c);
#endif
