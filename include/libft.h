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
# include <stdarg.h>

# include <libft/ft_lst.h>

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

/**
 * @brief Calculates the length of a null-terminated character string.
 * @param str A pointer to the start of the character string.
 * @return The length of the string.
 */
size_t		ft_strlen(const char *str);

/**
 * @brief Copies a character string to the heap.
 * @param s The string to be copied.
 * @return A pointer to the duplicate string.
 */
char		*ft_strdup(const char *s);

/**
 * @brief Concatenates two null-terminated character strings.
 * @param s1 The starting character string.
 * @param s2 The ending character string.
 * @return A pointer to the resulting string if successful, otherwise, NULL.
 */
char		*ft_strjoin(const char *s1, const char *s2);

/**
 * @brief Concatenates two null-terminated character strings up to `n`
 * characters.
 * @param s1 The starting character string.
 * @param s2 The ending character string.
 * @return A pointer to the resulting string if successful, otherwise, NULL.
 * @return The allocated joined string
 */
char		*ft_strnjoin(const char *s1, const char *s2, size_t n);

/**
 * @brief Copy a string while ensuring null-termination and size restriction.
 *
 * The `ft_strlcpy` function copies up to `size - 1` characters from the source
 * string to the destination buffer, ensuring null-termination. If the length
 * of the source string is less than `size`, the entire source string is copied.
 * If the length is greater than or equal to `size`, `size - 1` characters are
 * copied, and the destination buffer is null-terminated.
 *
 * @param dest The destination buffer where the copied string will be stored.
 * @param src The source string to be copied.
 * @param size The size of the destination buffer.
 * @return The total length of the source string.
 *
 * @note This function does not ensure null-termination if `size` is zero.
 */
size_t		ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief Concatenate strings while ensuring null-termination and size
 * restriction.
 *
 * The `strlcat` function appends up to `size - strlen(dest) - 1` characters
 * from the source string to the destination buffer, ensuring null-termination.
 * It then adds a null-terminator at the end of the concatenated string. The
 * resulting concatenated string will not exceed the size of the destination
 * buffer.
 *
 * @param dest The destination buffer where the concatenated string will be
 * stored.
 * @param src The source string to be appended.
 * @param size The size of the destination buffer.
 * @return The total length of the concatenated string.
 *
 * @note This function does not ensure null-termination if `size` is zero.
 */
size_t		ft_strlcat(char *dest, const char *src, size_t size);

/**
 * @brief Apply a function to each character of a string, creating a new string.
 * @param s The input string.
 * @param f The function to apply to each character.
 * @return A new dynamically allocated string if successful, otherwise, NULL.

 * Example Usage:
 * @code
 * const char *input = "Hello, world!";
 * char *result = ft_striter(input, ft_toupper); // Results in "HELLO, WORLD!".
 * @endcode
 */
char		*ft_striter(const char *s, int (*f)(int));

/**
 * @brief Apply a function to each character of a string with its index,
 * creating a new string.
 * @param s The input string.
 * @param f The function to apply to each character, taking the character's
 * index as well.
 * @return A new dynamically allocated string, or NULL on memory allocation
 * failure.
 *
 * @note The returned string must be freed using `free` when it's no longer
 * needed.
 *
 * Example Usage:
 * @code
 * // Append the character's index to each character
 * char appendIndex(unsigned int index, char c) {
 *     char result[2];
 *     result[0] = c;
 *     result[1] = '0' + index;
 *     return result;
 * }
 *
 * const char *input = "Hello";
 * char *result = ft_strmapi(input, appendIndex); // Results in "H0e1l2l3o4".
 * @endcode
 */
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/**
 * @brief Compare two strings.
 * @param s1 The first string for comparison.
 * @param s2 The second string for comparison.
 * @return An integer value indicating the comparison result:
 *         - 0 if the strings are equal.
 *         - A negative value if `s1` is lexicographically less than `s2`.
 *         - A positive value if `s1` is lexicographically greater than `s2`.
 */
int			ft_strcmp(const char *s1, const char *s2);

/**
 * @brief Compare a portion of two strings.
 * @param s1 The first string for comparison.
 * @param s2 The second string for comparison.
 * @param n The maximum number of characters to compare.
 * @return An integer value indicating the comparison result:
 *         - 0 if the strings are equal.
 *         - A negative value if `s1` is lexicographically less than `s2`.
 *         - A positive value if `s1` is lexicographically greater than `s2`.
 */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Find the first occurrence of a character in a string.
 * @param s The input string to search.
 * @param c The character to search for.
 * @return A pointer to the first occurrence of `c` in `s`, or NULL if not found.
 */
char		*ft_strchr(const char *s, int c);

/**
 * @brief Find the last occurrence of a character in a string.
 * @param s The input string to search.
 * @param c The character to search for.
 * @return A pointer to the last occurrence of `c` in `s`, or NULL if not found.
 */
char		*ft_strrchr(const char *s, int c);

/**
 * @brief Find the first occurrence of a substring within a limited portion of
 * a string.
 * @param big The input string to search within.
 * @param little The substring to search for.
 * @param len The maximum number of characters to search within.
 * @return A pointer to the start of the substring in `big`, or NULL if not
 * found.
 */
char		*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Trim specified characters from the beginning and end of a string.
 * @param str The input string to be trimmed.
 * @param set The set of characters to be trimmed from `str`.
 * @return The allocated trimmed string.
 */
char		*ft_strtrim(const char *str, const char *set);

/**
 * @brief Extract a substring from a string.
 * @param s The input string to extract the substring from.
 * @param start The starting index of the substring.
 * @param len The length of the substring.
 * @return The allocated substring.
 */
char		*ft_substr(const char *s, unsigned int start, size_t len);

/**
 * @brief Split a string into an array of substrings using a delimiter.
 * @param s The input string to be split.
 * @param c The delimiter character.
 * @return A null-terminated array of split substrings.
 */
char		**ft_split(const char *s, char c);

/**
 * @brief Write a character to the standard output (STDOUT).
 * @param c The character to be written.
 */
void		ft_putchar(char c);

/**
 * @brief Write a character to a file descriptor.
 * @param c The character to be written.
 * @param fd The file descriptor to be written to.
 */
void		ft_putchar_fd(char c, int fd);

/**
 * @brief Write a character string to the standard output (STDOUT).
 * @param s The character string to be written.
 */
void		ft_putstr(char *s);

/**
 * @brief Write a character string to the standard output (STDOUT).
 * @param s The character string to be written.
 * @param fd The file descriptor to be written to.
 */
void		ft_putstr_fd(char *s, int fd);

/**
 * @brief Write a string followed by a newline to a specified file descriptor.
 * @param s The string to be written.
 * @param fd The file descriptor to write to.
 */
void		ft_putendl_fd(char *s, int fd);

/**
 * @brief Write an integer to the standard output (STDOUT).
 * @param n The integer to be written.
 */
void		ft_putnbr(int s);

/**
 * @brief Write an integer to a specified file descriptor.
 * @param n The integer to be written.
 * @param fd The file descriptor to write to.
 */
void		ft_putnbr_fd(int s, int fd);

/**
 * @brief Retrieve the next line from a file descriptor.
 * @param fd The file descriptor to read from.
 * @return A pointer to an allocated string if successful, otherwise, NULL.
 */
char		*get_next_line(int fd);

/**
 * @brief Formatted printing to the standard output.
 * @param str The format string to be printed.
 * @param ... Additional arguments to be formatted and printed.
 * @return The number of characters printed (excluding the null-terminator)
 * or a negative value on error.
 */
int			ft_printf(const char *str, ...);

/**
 * @brief Formatted printing to the standard output using a va_list.
 * @param format The format string to be printed.
 * @param ap The va_list containing additional arguments.
 * @return The number of characters printed (excluding the null-terminator)
 * or a negative value on error.
 */
int			ft_vprintf(const char *format, va_list ap);

/**
 * @brief Formatted printing to a specified file descriptor.
 * @param fd The file descriptor to write to.
 * @param format The format string to be printed.
 * @param ... Additional arguments to be formatted and printed.
 * @return The number of characters printed (excluding the null-terminator)
 * or a negative value on error.
 */
int			ft_dprintf(int fd, const char *format, ...);

/**
 * @brief Formatted printing to a specified file descriptor using a va_list.
 * @param fd The file descriptor to write to.
 * @param format The format string to be printed.
 * @param ap The va_list containing additional arguments.
 * @return The number of characters printed (excluding the null-terminator)
 * or a negative value on error.
 */
int			ft_vdprintf(int fd, const char *format, va_list ap);

/**
 * @brief Formatted printing to a character buffer.
 * @param buf The character buffer to store the formatted string.
 * @param format The format string to be printed.
 * @param ... Additional arguments to be formatted and printed.
 * @return The number of characters that would have been printed (excluding the
 * null-terminator) if enough space was available.
 */
int			ft_sprintf(char *buf, const char *format, ...);

/**
 * @brief Formatted printing to a character buffer using a va_list.
 * @param buf The character buffer to store the formatted string.
 * @param format The format string to be printed.
 * @param ap The va_list containing additional arguments.
 * @return The number of characters that would have been printed (excluding the
 * null-terminator) if enough space was available.
 */
int			ft_vsprintf(char *buf, const char *format, va_list ap);

/**
 * @brief Allocate and format a string using a va_list.
 * @param buf A pointer to the allocated string.
 * @param format The format string to be printed.
 * @param ap The va_list containing additional arguments.
 * @return The number of characters printed (excluding the null-terminator)
 * or a negative value on error.
 */
int			ft_vasprintf(char **buf, const char *format, va_list ap);

/**
 * @brief Allocate and format a string.
 * @param buf A pointer to the allocated string.
 * @param format The format string to be printed.
 * @param ... Additional arguments to be formatted and printed.
 * @return The number of characters printed (excluding the null-terminator)
 * or a negative value on error.
 */
int			ft_asprintf(char **buf, const char *format, ...);

#endif
