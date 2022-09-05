/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:02:26 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/05 15:22:48 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* Converts the initial portion of the string `nptr` to an `int`. */
int			ft_atoi(const char *nptr);

/* Converts the initial portion of the string `nptr` to an `int`. */
long long	ft_atoll(const char *nptr);

/* Converts the initial portion of the string `nptr` to a `long double`. */
long double	ft_atold(const char *nptr);

/* Allocates and returns a string representing the integer received as an
 * argument. */
char		*ft_itoa(int n);

/* Allocates and returns a string representing the long integer received as an
 * argument. */
char		*ft_ltoa(long int n);

/* Allocates and returns a string representing the long long integer received
* as an argument. */
char		*ft_lltoa(long long int n);

/* Allocates and returns a string representing the long double received as an
 * argument up to a certain precision. */
char		*ft_ldtoa(long double n, size_t precision);

/* Allocates and returns a string representing the unsigned integer received as
 * an argument. */
char		*ft_uitoa(unsigned int n);

/* Allocates and returns a string representing the unsigned long integer
 * received as an argument. */
char		*ft_ultoa(unsigned long int n);

/* Allocates and returns a string representing the unsigned long long integer
 * received as an argument. */
char		*ft_ulltoa(unsigned long long int n);

/* Allocates and returns a string representing the integer received as an
 * argument in a specific base. */
char		*ft_itoa_base(int n, char *base);

/* Allocates and returns a string representing the long integer received as an
 * argument in a specific base. */
char		*ft_ltoa_base(long int n, char *base);

/* Allocates and returns a string representing the long long integer received
* as an argument in a specific base. */
char		*ft_lltoa_base(long long int n, char *base);

/* Allocates and returns a string representing the unsigned integer received as
 * an argument in a specific base. */
char		*ft_uitoa_base(unsigned int n, char *base);

/* Allocates and returns a string representing the unsigned long integer
 * received as an argument in a specific base. */
char		*ft_ultoa_base(unsigned long int n, char *base);

/* Allocates and returns a string representing the unsigned long long integer
 * received as an argument in a specific base. */
char		*ft_ulltoa_base(unsigned long long int n, char *base);

/* Allocates and returns a new element. The variable `content` is initialized
 * with the value of the parameter `content`. The variable `next` is
 * initialized to NULL. */
t_list		*ft_lstnew(void *content);

/* Adds the element `new` at the beginning of the list. */
void		ft_lstadd_front(t_list **lst, t_list *new);

/* Counts the number of elements in a list. */
int			ft_lstsize(t_list *lst);

/* Returns the last element of the list. */
t_list		*ft_lstlast(t_list *lst);

/* Adds the element `new` at the end of the list. */
void		ft_lstadd_back(t_list **lst, t_list *new);

/* Takes as parameter an element and frees the memory of the element's content
 * using the function `del` as a parameter and free the element. The memory of
 * `next` is not be freed. */
void		ft_lstdelone(t_list *lst, void (*del)(void *));

/* Deletes and frees the given element and every successor of that element,
 * using the function `del`. Finally, the pointer to the list is set to NULL.
 * */
void		ft_lstclear(t_list **lst, void (*del)(void *));

/* Iterates the list `lst` and applies the function `f` to the content of each
 * element. */
void		ft_lstiter(t_list *lst, void (*f)(void *));

/* Iterates the list `lst` and applies the function `f` to the content of each
 * element. Creates a new list resulting of the successive applications of the
 * function `f`. The `del` function is used to delete the content of an element
 * if needed. */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* Returns the absolute value of a number. */
uint		ft_abs(int n);

#endif
