/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/25 15:16:40 by apilate           #+#    #+#             */
/*   Updated: 2014/05/04 18:44:43 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>

char					*ft_strerror(int errnum);
void					ft_perror(const char *s);

# ifndef MAX
#  define MAX(a, b) ((a) > (b) ? (a) : (b))
# endif

# ifndef MIN
#  define MIN(a, b) ((a) < (b) ? (a) : (b))
# endif

# define FT_PRINTF_HANDLERS 13

# define FT_PRINTF_FLAG_LJUSTIFY 0x01
# define FT_PRINTF_FLAG_SIGN 0x02
# define FT_PRINTF_FLAG_NOSIGN 0x04
# define FT_PRINTF_FLAG_PREFIX 0x08
# define FT_PRINTF_FLAG_LPAD 0x10

# define FT_PRINTF_LENGTH_NONE 0
# define FT_PRINTF_LENGTH_HH 1
# define FT_PRINTF_LENGTH_H 2
# define FT_PRINTF_LENGTH_L 3
# define FT_PRINTF_LENGTH_LL 4

# define PSPEC t_ftprintf_fmt_spec

typedef struct			s_ftprintf_fmt_spec
{
	int		flags;
	int		width;
	int		precision;
	int		length;
	char	specifier;
}						t_ftprintf_fmt_spec;

typedef struct			s_ftprintf_handler
{
	char	c;
	int		(*handler)(va_list args, PSPEC *spec, int params);
	int		param;
}						t_ftprintf_handler;

# define READ_SIZE	4096

typedef struct			s_reader
{
	char	buf[READ_SIZE];
	int		index;
	int		size;
	int		fd;
	int		to_return;
}						t_reader;

typedef struct			s_buffer
{
	char	*buf;
	int		index;
	int		size;

}						t_buffer;

int						get_next_line(const int fd, char **line);
int						ft_printf(const char *fmt, ...);
t_ftprintf_handler		*ft_printf_handlers(void);
unsigned long long int	ft_printf_unsigned_value(va_list args, PSPEC *spec);
long long int			ft_printf_signed_value(va_list args, PSPEC *spec);
int						ft_printf_flags(const char **fmt);
int						ft_printf_width(const char **fmt, va_list args);
int						ft_printf_precision(const char **fmt, va_list args);
int						ft_printf_length(const char **fmt, va_list args);
int						ft_printf_char_handler(va_list args, PSPEC *spec,
	int params);
int						ft_printf_string_handler(va_list args, PSPEC *spec,
	int params);
int						ft_printf_int_handler(va_list args, PSPEC *spec,
	int params);
int						ft_printf_uint_handler(va_list args, PSPEC *spec,
	int params);
int						ft_printf_percent_handler(va_list args, PSPEC *spec,
	int params);
void					ft_bzero(void *s, size_t n);
char					*ft_itoa(int nb);
void					*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *s1, const void *s2, size_t n);
void					*ft_memmove(void *s1, const void *s2, size_t n);
void					*ft_memset(void *b, int c, size_t len);
int						ft_putchar(char c);
int						ft_putnbr(int n);
int						ft_putstr(char const *str);
char					*ft_strrev(char *src);
char					*ft_strcat(char *s1, char *s2);
char					*ft_strchr(const char *s, int c);
int						ft_strcmp(char *s1, char *s2);
char					*ft_strcpy(char *s1, const char *s2);
char					*ft_strdup(const char *s1);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
int						ft_strlen(const char *s);
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *dest, char *src, int n);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(char *str, char *to_find);
void					ft_swap(int *a, int *b);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_isupper(int c);
int						ft_islower(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
	char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s,
	unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
int						ft_putendl(char const *s);
int						ft_putchar_fd(char c, int fd);
int						ft_putstr_fd(char const *s, int fd);
int						ft_putendl_fd(char const *s, int fd);
int						ft_putnbr_fd(int n, int fd);
void					ft_fillspace(char c, int length);
int						ft_checkbase(char *base);
void					*ft_malloc(size_t size);
void					*ft_calloc(size_t n, size_t size);
void					*ft_realloc(void *p, size_t size);
void					ft_free(void *p);
void					ft_show_alloc_mem(void);

#endif
