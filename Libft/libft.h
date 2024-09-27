/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:13:59 by ecousill          #+#    #+#             */
/*   Updated: 2024/09/24 12:46:10 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalpha(int c);	//ok
int		ft_isdigit(int c);	//ok
int		ft_isalnum(int c);	//ok
int		ft_isascii(int c);	//ok
int		ft_isprint(int c);	//ok
size_t	ft_strlen(const char *s);	//ok
void	*ft_memset(void *s, int c, size_t n);	//ok
void	ft_bzero(void *s, size_t n); // ok
void	*ft_memcpy(void *dest, const void *src, size_t n); //ok
void	*ft_memmove(void *dest, const void *src, size_t n); //ok
size_t	ft_strlcpy(char *dst, const char *src, size_t size); //ok
size_t	ft_strlcat(char *dst, const char *src, size_t size); //ok
int		ft_toupper(int c); //ok
int		ft_tolower(int c); //ok
char	*ft_strchr(const char *s, int c); //ok
char	*ft_strrchr(const char *s, int c); ///ok
int		ft_strncmp(const char *s1, const char *s2, size_t n); //ok
void	*ft_memchr(const void *s, int c, size_t n); //ok
int		ft_memcmp(const void *s1, const void *s2, size_t n); //ok
char	*ft_strnstr(const char *haystack, const char *needle, size_t len); //ok
int		ft_atoi(const char *nptr); //ok
void	*ft_calloc(size_t count, size_t size); //ok
char	*ft_strdup(const char *s); //ok

char	*ft_substr(char const *s, unsigned int start, size_t len); //ok
char	*ft_strjoin(char const *s1, char const *s2); //ok
char	*ft_strtrim(char const *s1, char const *set); //ok
char	**ft_split(char const *s, char c); //ok
char	*ft_itoa(int n); //ok
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)); //ok
void	ft_striteri(char *s, void (*f)(unsigned int, char*)); //ok
void	ft_putchar_fd(char c, int fd); //ok
void	ft_putstr_fd(char *s, int fd); //ok
void	ft_putendl_fd(char *s, int fd); //ok
void	ft_putnbr_fd(int n, int fd); //ok

t_list	*ft_lstnew(void *content); //ok
void	ft_lstadd_front(t_list **lst, t_list *new); //ok
int		ft_lstsize(t_list *lst); //ok
t_list	*ft_lstlast(t_list *lst); //ok
void	ft_lstadd_back(t_list **lst, t_list *new); //ok
void	ft_lstdelone(t_list *lst, void (*del)(void *)); //ok
void	ft_lstclear(t_list **lst, void (*del)(void *)); //ok
void	ft_lstiter(t_list *lst, void (*f)(void *)); //ok
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)); //ok

#endif
