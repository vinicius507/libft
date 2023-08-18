/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:02:26 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/08/18 10:43:53 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file libft.h
 * @author Vinícius Oliveira (vgoncalv)
 * @brief This is my Libft. A general purpose library meant for usage within
 * École 42.
 */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# include <libft/ft_io.h>
# include <libft/ft_lst.h>
# include <libft/ft_string.h>

/**
 * @brief Converts the initial portion of the string `nptr` to an integer.
 * @param nptr The string to be converted.
 * @return The integer representation from `nptr`.
 */
int			ft_atoi(const char *nptr);

/**
 * @brief Converts the initial portion of the string `nptr` to a long long
 * integer.
 * @param nptr The string to be converted.
 * @return The long long integer representation from `nptr`.
 */
long long	ft_atoll(const char *nptr);

/**
 * @brief Converts the initial portion of the string `nptr` to a long double.
 * @param nptr The string to be converted.
 * @return The long double representation from `nptr`.
 */
long double	ft_atold(const char *nptr);

/**
 * @brief Converts an integer value to a string.
 * @param n The integer value to be converted.
 * @return A pointer to the resulting string if successful, otherwise, NULL.
 */
char		*ft_itoa(int n);

/**
 * @brief Converts an long integer value to a string.
 * @param n The long integer value to be converted.
 * @return A pointer to the resulting string if successful, otherwise, NULL.
 */
char		*ft_ltoa(long int n);

/**
 * @brief Converts an long long integer value to a string.
 * @param n The long long integer value to be converted.
 * @return A pointer to the resulting string if successful, otherwise, NULL.
 */
char		*ft_lltoa(long long int n);

/**
 * @brief Converts an long double value to a string.
 * @param n The long double value to be converted.
 * @param precision The precision used for the string representation.
 * @return A pointer to the resulting string if successful, otherwise, NULL.
 */
char		*ft_ldtoa(long double n, size_t precision);

/**
 * @brief Converts an unsigned integer value to a string.
 * @param n The unsigned integer value to be converted.
 * @return A pointer to the resulting string if successful, otherwise, NULL.
 */
char		*ft_uitoa(unsigned int n);

/**
 * @brief Converts an unsigned long integer value to a string.
 * @param n The unsigned long integer value to be converted.
 * @return A pointer to the resulting string if successful, otherwise, NULL.
 */
char		*ft_ultoa(unsigned long int n);

/**
 * @brief Converts an unsigned long long integer value to a string.
 * @param n The unsigned long long integer value to be converted.
 * @return A pointer to the resulting string if successful, otherwise, NULL.
 */
char		*ft_ulltoa(unsigned long long int n);

/**
 * @brief Converts an integer value to a string using the character string
 * `base` as numeric base.
 * @param n The integer value to be converted.
 * @param base A character string representing the numeric base.
 * @return The string form of the integer `n` in its `base` form
 *
 * Example Usage:
 * @code
 * char *str = ft_itoa_base(4, "01");
 * printf("%s\n", str); // Outputs '100'
 * @endcode
 */
char		*ft_itoa_base(int n, char *base);

/**
 * @brief Converts an long integer value to a string using the character string
 * `base` as numeric base.
 * @param n The long integer value to be converted.
 * @param base A character string representing the numeric base.
 * @return The string form of the long integer `n` in its `base` form
 *
 * Example Usage:
 * @code
 * char *str = ft_ltoa_base(4, "01");
 * printf("%s\n", str); // Outputs '100'
 * @endcode
 */
char		*ft_ltoa_base(long int n, char *base);

/**
 * @brief Converts an long long integer value to a string using the character
 * string `base` as numeric base.
 * @param n The long long integer value to be converted.
 * @param base A character string representing the numeric base.
 * @return The string form of the long long integer `n` in its `base` form
 *
 * Example Usage:
 * @code
 * char *str = ft_lltoa_base(4, "01");
 * printf("%s\n", str); // Outputs '100'
 * @endcode
 */
char		*ft_lltoa_base(long long int n, char *base);

/**
 * @brief Converts an unsigned integer value to a string using the character
 * string `base` as numeric base.
 * @param n The unsigned integer value to be converted.
 * @param base A character string representing the numeric base.
 * @return The string form of the unsigned integer `n` in its `base` form
 *
 * Example Usage:
 * @code
 * char *str = ft_uitoa_base(4, "01");
 * printf("%s\n", str); // Outputs '100'
 * @endcode
 */
char		*ft_uitoa_base(unsigned int n, char *base);

/**
 * @brief Converts an unsigned long integer value to a string using the
 * character string `base` as numeric base.
 * @param n The unsigned long integer value to be converted.
 * @param base A character string representing the numeric base.
 * @return The string form of the unsigned long integer `n` in its `base` form
 *
 * Example Usage:
 * @code
 * char *str = ft_ultoa_base(4, "01");
 * printf("%s\n", str); // Outputs '100'
 * @endcode
 */
char		*ft_ultoa_base(unsigned long int n, char *base);

/**
 * @brief Converts an unsigned long long integer value to a string using the
 * character string `base` as numeric base.
 * @param n The unsigned long long integer value to be converted.
 * @param base A character string representing the numeric base.
 * @return The string form of the unsigned long long integer `n` in its
 * `base` form.
 *
 * Example Usage:
 * @code
 * char *str = ft_ulloa_base(4, "01");
 * printf("%s\n", str); // Outputs '100'
 * @endcode
 */
char		*ft_ulltoa_base(unsigned long long int n, char *base);

/**
 * @brief Returns the absolute value of an integer.
 * @param n The integer to retrieve the absolute value from.
 * @return The absolute value from the integer `n`.
 */
uint		ft_abs(int n);

/**
 * @brief Checks if the given character is an alphabetic character.
 * @param c The character to be checked.
 * @return A non-zero value if it is an alphabetic character.
 */
int			ft_isalpha(int c);

/**
 * @brief Checks if the given character is a digit character.
 * @param c The character to be checked.
 * @return A non-zero value if it is a digit character.
 */
int			ft_isdigit(int c);

/**
 * @brief Checks if the given character is an alphanumeric character.
 * @param c The character to be checked.
 * @return A non-zero value if it is an alphanumeric character.
 */
int			ft_isalnum(int c);

/**
 * @brief Checks if the given character is an ASCII character.
 * @param c The character to be checked.
 * @return A non-zero value if it is an ASCII character.
 */
int			ft_isascii(int c);

/**
 * @brief Checks if the given character is a printable character.
 * @param c The character to be checked.
 * @return A non-zero value if it is a printable character.
 */
int			ft_isprint(int c);

/**
 * @brief Converts the given character to its lowercase form.
 * @param c The character to be converted.
 * @return The given character lowercase version, if it exists, otherwise
 * it is returned unchanged.
 */
int			ft_tolower(int c);

/**
 * @brief Converts the given character to its uppercase form.
 * @param c The character to be converted.
 * @return The given character uppercase version, if it exists, otherwise
 * it is returned unchanged.
 */
int			ft_toupper(int c);

/**
 * @brief Allocates memory for an array of `nmemb` elements of `size` bytes each
 * and returns a pointer to the allocated memory.
 * @param nmemb The number of elements to allocate memory to.
 * @param size The number of bytes to allocate for each member.
 * @return A pointer to the allocated memory, if successful, otherwise NULL.
 */
void		*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Sets `n` bytes of memory region `s` to the character `c`.
 * @param s A pointer to the start of the memory region.
 * @param c The value to be set for all bytes of the memory region.
 * @param n The number of bytes to be modified.
 * @return A pointer to the start of the memory region.
 */
void		*ft_memset(void *s, int c, size_t n);

/**
 * @brief Sets `n` bytes of memory region `s` to 0.
 * @param s A pointer to the start of the memory region.
 * @param n The number of bytes to be zeroed.
 * @return A pointer to the start of the memory region.
 */
void		ft_bzero(void *s, size_t n);

/**
 * @brief Copies `n` bytes of from memory area `src` to memory area `dest`.
 * @param dest The destination memory area.
 * @param src The source memory area.
 * @param n The number of bytes to be copied.
 * @return A pointer to the copied area.
 */
void		*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies up to `n` bytes of from memory area `src` to memory area
 * `dest`, stopping when the character `c` is found.
 * @param dest The destination memory area.
 * @param src The source memory area.
 * @param c The stopping character.
 * @param n The maximum number of bytes to be copied.
 * @return A pointer to the copied area.
 */
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);

/**
 * @brief Copies `n` bytes from `src` to `dest`. The memory areas may
 * overlap.
 * @param dest The destination memory area.
 * @param src The source memory area.
 * @param n The number of bytes to be copied.
 * @return A pointer to dest
 */
void		*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Scans a memory area for a byte `c`.
 * @param s A pointer to the memory area. .
 * @param c The target byte. Is is interpreted as an `unsigned char `.
 * @param n The size of the memory area to be scanned.
 * @return A pointer to the byte, if found, else, `NULL`.
 *
 * @note The sequence of bytes that compose `s` are interpreted as
 * unsigned characters.
 */
void		*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first `n` bytes of two memory areas.
 * @param s1 The first memory area.
 * @param s2 The second memory area.
 * @param n The number of bytes to be compared
 * @return For a non-zero value, it is the difference between the first pair
 * of bytes that differ in `s1` and `s2`
 */
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Joins two memory sections.
 * @param m1 A pointer to the first memory section.
 * @param m2 A pointer to the second memory section.
 * @param size1 The size of the first memory section.
 * @param size2 The size of the second memory section.
 * @return A pointer to the resulting memory section.
 */
void		*ft_memjoin(const void *m1, const void *m2,
				size_t size1, size_t size2);

#endif
