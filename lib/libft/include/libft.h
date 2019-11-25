/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:34:03 by viwade            #+#    #+#             */
/*   Updated: 2019/11/11 10:01:56 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "libft_include.h"
# include "libft_macros.h"
# include "libft_structs.h"

/*
**		STANDARD OUTPUT
*/

int				ft_printf(const char *format, ...);
int				ft_vprintf(const char *format, va_list ap);
FT_VOID			ft_putchar(int c);
FT_VOID			ft_putchar_fd(char c, int fd);
FT_VOID			ft_putwchar(unsigned int wc);
FT_SIZE			write_utf8(unsigned int wc);
FT_SIZE			write_utf8_fd(unsigned int wc, int fd);
FT_SIZE			print_utf8(unsigned int *int32_str);
FT_SIZE			print_utf8_n(unsigned int *int32_str, FT_SIZE length);
FT_STR			encode_utf8(int *wc);
FT_STR			encode_utf8_w(int *l_str, size_t bytes_allowed);
FT_VOID			ft_putstr(char const *s);
FT_VOID			ft_putstr_fd(char const *s, int fd);
FT_VOID			ft_putendl(char const *s);
FT_VOID			ft_putendl_fd(char const *s, int fd);
FT_VOID			ft_putnbr(long long int number);
FT_VOID			ft_putnbr_fd(long long int number, int file_descriptor);
FT_VOID			ft_putnbr_u(unsigned int number);
FT_VOID			print_float(float n, FT_SIZE precision);
FT_VOID			print_double(ld_t value, unsigned int precision);
FT_STR			infinite_double(ld_t value, ull_t precision);
FT_SIZE			write_infinite_double(ld_t value, ull_t precision);

/*
**	I am probably categorizing the ft_strtoi and ft_strtol very incorrectly.
**	The intention is to convert an array of chars into an array of ints/longs.
**	The functions do that. The names may be inappropriate.
*/

uint32_t		*ft_strtoi(char *str);
ull_t			*ft_strtol(char *str);
int				*str_utf8(wchar_t *l_str);
long long int	ft_power(long long int_base, int int_power);

/*
**		MEMORY SET
*/

FT_VOID			ft_free(void *ap);
FT_VOID			*ft_memset(FT_VOIDP b, int c, FT_SIZE len);
FT_VOID			ft_bzero(FT_VOIDP s, FT_SIZE n);
FT_VOID			*ft_memcpy(FT_VOIDP dst, const FT_VOIDP src, FT_SIZE n);
FT_VOID			*ft_memccpy(FT_VOIDP dst, const FT_VOIDP src, int c, FT_SIZE n);
FT_VOID			*ft_memmove(FT_VOIDP dst, const FT_VOIDP src, FT_SIZE n);
FT_VOID			*ft_memchr(const FT_VOIDP s, int c, FT_SIZE n);
char			ft_cmp(size_t a, size_t b);
int				ft_memcmp(const FT_VOIDP s1, const FT_VOIDP s2, FT_SIZE n);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, FT_SIZE len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, FT_SIZE n);
FT_SIZE			ft_strlcat(char *dst, const char *src, FT_SIZE dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(
					const char *haystack,
					const char *needle,
					FT_SIZE len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, FT_SIZE n);
char			*splice_str(char *source, char *fragment, size_t ndx);
char			*search_and_splice(char *source, char *needle, char *fragment);
char			*ft_strcapitalize(char *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isuppercase(char c);

int				ft_toupper(int c);
int				ft_tolower(int c);
FT_VOID			ft_strtoupper(char **str);
FT_VOID			ft_strtolower(char **str);
FT_STR			ft_strlowercase(char *s);
FT_VOID			*ft_memalloc(FT_SIZE size);
FT_VOID			ft_memdel(FT_VOIDP *ap);

char			*ft_strnew(FT_SIZE size);
FT_VOID			ft_strdel(char **as);
FT_VOID			ft_strclr(char *s);
FT_VOID			ft_striter(char *s, FT_VOID (*f)(char *));
FT_VOID			ft_striteri(char *s, FT_VOID (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, FT_SIZE n);
char			*ft_strsub(char const *s, FT_SIZE start, FT_SIZE len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *string);
char			*ft_strtrimc(char const *string, char c);
char			*ft_strclean(char const *string, char c);
char			*ft_strclean_free(char const *string, char c);
char			**ft_strsplit(char const *s, char c);
t_str			*tstr_new(char *s);
t_str			*tstr_dup(char *s);
t_str			*tstr_dup_free(char *s);
void			tstr_free(t_str *s);
void			ft_delimit(const char **s, int c);

t_list			*ft_lstnew(FT_VOID const *content, FT_SIZE content_size);
FT_VOID			ft_lstdelone(t_list **alst, FT_VOID (*del)(FT_VOIDP, FT_SIZE));
FT_VOID			ft_lstdel(t_list **alst, FT_VOID (*del)(FT_VOIDP, FT_SIZE));
FT_VOID			ft_lstadd(t_list **alst, t_list *newnode);
FT_VOID			ft_lstiter(t_list *lst, FT_VOID (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

FT_VOID			print_bits(int octal);
FT_VOID			print_64bits(ull_t octal);
FT_VOID			print_64bits_recursive(ull_t octal);
FT_VOID			print_hex(unsigned long long int c);
FT_VOID			print_memory(const FT_VOIDP addr, FT_SIZE size);
unsigned char	swap_bits(unsigned char octet);
unsigned char	reverse_bits(unsigned char octet);
void			ft_swap(char *a, char *b);
void			ft_memswap(const void *a, const void *b);

int				ft_astrcmp(char **s1, char **s2);
FT_VOID			ft_del(FT_VOIDP ap, FT_SIZE len);
FT_VOID			ft_lstpush(t_list **list, t_list *new);
FT_VOID			ft_lstpop(t_list **list);
FT_VOID			**ft_lst2arr(t_list *lst);
FT_VOID			ft_error(const char *message);
char			*ft_append(const char *s1, const char *s2, int mode);
char			*ft_strjoin_free(char const *s1, char const *s2);

/*
**	Write to Standard Output
*/

/*
**	FILE I/O
*/

int				get_next_line(const int fd, char **line);

/*
**	Length Getters
*/

FT_SIZE			ft_strlen(const char *s);
int64_t			ft_wstrlen(wchar_t *s);
FT_SIZE			ft_lstrlen(const wchar_t *s);
FT_SIZE			ft_intlen(ull_t value);
int64_t			ft_intlen_base(ull_t value, int base);
int64_t			ft_lstlen(t_list *lst);
int64_t			ft_arrlen(char **ar);

/*
**	String Modifiers
*/

char			*ft_basename(char *path);

/*
**	Conversion
*/

int				ft_atoi(const char *str);
ull_t			ft_hextol(char *s);
ull_t			ft_octtol(char *s);
FT_STR			ft_itoa(ll_t value);
FT_STR			ft_itoa_unsigned(ull_t value);
FT_STR			ft_itoa_base(ull_t value, int base);

/*
**	Length Getters
*/

int				ft_iswhitespace(int c);
size_t			len_interval(void const *s, size_t interval);
size_t			slen(const char *s, size_t maxsize);

/*
**	Math
*/

ld_t			ft_sqrt(long double n);
ld_t			ft_sqroot(long double n);

/*
**	Queue
*/

t_queue			*ft_queue(void);
void			*ft_dequeue(t_queue *queue);
void			ft_enqueue(t_queue *queue, void *content);
void			ft_queue_last(t_queue *queue, void *content);
void			ft_queue_del(t_queue *queue);
void			ft_node_insert(t_node *node, t_queue *queue);

/*
**	Stack
*/

t_stack			*ft_stack(void);
void			*ft_stack_peek(t_stack *stack);
void			*ft_stack_pop(t_stack *stack);
void			ft_stack_push(t_stack *stack, void *content);
void			ft_stack_del(t_stack *stack);

/*
**	Length Getters
*/

/*
**	Length Getters
*/

#endif
