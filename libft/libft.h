/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:26:47 by ibonifac          #+#    #+#             */
/*   Updated: 2018/02/07 14:26:53 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <wchar.h>
# include <limits.h>
# include <locale.h>

typedef struct	s_list
{
	void			*content;
	unsigned int	content_size;
	struct s_list	*next;
}				t_list;

int				ft_sqrt(int nb);
unsigned long	ft_strlcat(char *dest, char const *src, unsigned long n);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char			*ft_strtrim(char const *s);
char			*ft_strsub(char const *s, unsigned int start, unsigned long
				len);
int				ft_strnequ(char const *s1, char const *s2, unsigned long n);
char			*ft_strmap(char const *s, char (*f)(char));
void			ft_strdel(char **as);
char			*ft_strrchr(const char *s, int c);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strnew(unsigned long size);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putendl(char const *str);
void			*ft_memalloc(unsigned long size);
void			ft_memdel(void **ap);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *str, int fd);
char			*ft_strnstr(const char *s1, const char *s2, unsigned long n);
char			*ft_strchr(const char *s, int c);
void			*ft_memset(void *b, int c, unsigned long len);
int				ft_atoi(const char *str);
void			ft_putchar(char c);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strcpy(char *dst, const char *src);
unsigned long	ft_strlen(const char *str);
char			*ft_strncpy(char *dst, const char *src, unsigned long n);
void			ft_bzero(void *s, unsigned long n);
void			ft_putstr(char const *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(char *src);
int				ft_strncmp(const char *s1, const char *s2, unsigned long n);
char			*ft_strstr(const char *source, const char *search);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strncat(char *dest, const char *src, unsigned long n);
int				ft_memcmp(const void *s1, const void *s2, unsigned long n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			*ft_memccpy(void *dest, const void *src, int c, unsigned long
				n);
int				ft_memcmp(const void *s1, const void *s2, unsigned long n);
void			*ft_memcpy(void *dest, const void *src, unsigned long n);
void			*ft_memchr(const void *s, int c, unsigned long n);
void			*ft_memmove(void *dest, const void *src, unsigned long len);
void			ft_lstadd(t_list **alst, t_list *newlst);
void			ft_lstdel(t_list **alst, void (*del)(void *, unsigned long));
void			ft_lstdelone(t_list **alst, void (*del)(void *, unsigned long));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_div_mod(int a, int b, int *div, int *mod);
void			ft_swap(int *a, int *b);
int				ft_sqrt(int nb);
char			*ft_strrev(char *str);
void			ft_exit(char *str);
t_list			*ft_lstmap(t_list *lst, t_list*(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, unsigned long content_size);
char			*ft_strupcase(char *str);
char			*ft_strjoin_nfree(char *s1, char *s2, int option);
char			*ft_strsub_nfree(char *s1, unsigned int start, size_t len,
				int option);
char			*ft_strdup_nfree(char *src, int option);

#endif
