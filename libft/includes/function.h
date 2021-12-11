/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:24:55 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 14:25:06 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

/* MATH */

int		__abs(int x);
long	__labs(long x);
int		__max(int x, int y);
int		__min(int x, int y);
int64_t	__llabs(int64_t x);
long	__random(int len_max);

/* CHAR */

int		__isacii(int c);
int		__isalnum(int c);
int		__isalpha(int c);
int		__isdigit(int c);
int		__isprint(int c);
int		__tolower(int c);
int		__toupper(int c);
int		__is_charset(char c, char *set);

/* LIST */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		__lstsize(t_list *lst);
t_list	*__lstlast(t_list *lst);
t_list	*__lstnew(void *content);
void	__lstadd_back(t_list **alst, t_list *new);
void	__lstiter(t_list *lst, void (*f)(void *));
void	__lstadd_front(t_list **alst, t_list *new);
void	__lstclear(t_list **lst, void (*del)(void*));
void	__lstdelone(t_list *lst, void (*del)(void*));
t_list	*__lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* MEM */

void	__clean(void);
int8_t	__free(void	*addr);
void	__bzero(void *b, size_t len);
void	*__calloc(size_t count, size_t size);
void	*__malloc(size_t count, size_t size);
void	*__memset(void *b, int c, size_t len);
void	*__memchr(const void *s, int c, size_t n);
void	*__memcpy(void *dst, const void *src, size_t n);
int		__memcmp(const void *s1, const void *s2, size_t n);
void	*__memmove(void *dst, const void *src, size_t len);
void	*__memccpy(void *dst, const void *src, int c, size_t n);

/* PRINT */

void	__putnbr(int n, int fd);
void	__putchar(char c, int fd);
void	__putstr(char *s, int fd);
void	__putendl(char *s, int fd);
void	__putaddr(void *addr, int fd);
void	__putnstr(char *str, int fd, size_t len);

/* STDLIB */

char	*__itoa(int64_t n);
int		__nbrlen(int64_t nbr);
int		__atoi(const char *str);
long	__atol(const char *str);
int64_t	__atoll(const char *str);
int		__nbrlen_base(int64_t nbr, char *base);

/* STRING */

char	*__strdup(const char *src);
size_t	__strlen(const char *str);
char	*__strchr(const char *s, int c);
char	*__strrchr(const char *s, int c);
char	**__split(char const *str, char c);
char	*__strcat(const char *s1, const char *s2);
char	*__strjoin(char const *s1, char const *s2);
char	*__strtrim(const char *s1, const char *set);
int		__strncmp(const char *s1, const char *s2, size_t n);
void	__striteri(char *s, void (*f)(unsigned int, char*));
size_t	__strlcat(char *dest, const char *src, size_t size);
size_t	__strlcpy(char *dest, const char *src, size_t size);
char	*__strmapi(char const *s, char (*f)(unsigned int, char));
char	*__substr(char const *s, unsigned int start, size_t len);
char	*__strnstr(const char *haystack, const char *needle, size_t len);

#endif
