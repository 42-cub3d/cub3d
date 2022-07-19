/* ************************************************************************** */
/**//**//*****//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#ifndef LIBFT_H

# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif
# define FT_DEL 0
# define FT_NEW 1
# define FT_ADD 2

typedef struct s_gnl_list
{
	struct s_gnl_list	*next;
	char				*save_line;
	int					fd;
	ssize_t				read_size;
}						t_gnl_list;

typedef struct s_split_info
{
	char		**sv_temp;
	char		*pos;
	char		*s_temp;
	size_t		size;
	size_t		cur;
}				t_split_info;

typedef struct s_itoa_info
{
	char	*temp;
	size_t	len;
	int		n_backup;
}			t_itoa_info;

typedef struct s_list
{
	struct s_list	*next;
	void			*content;
}					t_list;

/*		ft_libc_ctype_syntax.c
**==============================================================================
*/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

/*		ft_libc_ctype_convert.c
**==============================================================================
*/
int		ft_toupper(int c);
int		ft_tolower(int c);

/*		ft_libc_string_util.c
**==============================================================================
*/
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *s1);

/*		ft_libc_string_cpy.c
**==============================================================================
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/*		ft_libc_string_locate_and_compare.c
**==============================================================================
*/
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*		ft_libc_stdlib.c
**==============================================================================
*/
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);

/*		ft_util_io.c
**==============================================================================
*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*		ft_util_string.c
**==============================================================================
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

/*		ft_util_string_sub.c
**==============================================================================
*/
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*		Bonus part
**==============================================================================
*/
/*		ft_list_lib.c
**==============================================================================
*/
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

/*		ft_list_lib_util.c
**==============================================================================
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*		get_next_line.c
**==============================================================================
*/
char	*get_next_line(int fd);
int		ft_strchr_find_nl(char *s);
char	*ft_free(char **s1, char **s2, int keyword);


#endif
