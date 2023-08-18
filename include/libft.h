/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:02:26 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/11/29 12:31:39 by vgoncalv         ###   ########.fr       */
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
# include <libft/ft_mem.h>
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
 * char *str = ft_uitoa_base(4, "01");
 * printf("%s\n", str); // Outputs '100'
 * @endcode
 */
char		*ft_ultoa_base(unsigned long int n, char *base);

/**
 * @brief Converts an unsigned long long integer value to a string using the
 * character string `base` as numeric base.
 * @param n The unsigned long long integer value to be converted.
 * @param base A character string representing the numeric base.
 * @return The string form of the unsigned long long integer `n` in its `base` form
 *
 * Example Usage:
 * @code
 * char *str = ft_uitoa_base(4, "01");
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
int	ft_isalpha(int c);

/**
 * @brief Checks if the given character is a digit character.
 * @param c The character to be checked.
 * @return A non-zero value if it is a digit character.
 */
int	ft_isdigit(int c);

/**
 * @brief Checks if the given character is an alphanumeric character.
 * @param c The character to be checked.
 * @return A non-zero value if it is an alphanumeric character.
 */
int	ft_isalnum(int c);

/**
 * @brief Checks if the given character is an ASCII character.
 * @param c The character to be checked.
 * @return A non-zero value if it is an ASCII character.
 */
int	ft_isascii(int c);

/**
 * @brief Checks if the given character is a printable character.
 * @param c The character to be checked.
 * @return A non-zero value if it is a printable character.
 */
int	ft_isprint(int c);

/**
 * @brief Converts the given character to its lowercase form.
 * @param c The character to be converted.
 * @return The given character lowercase version, if it exists, otherwise
 * it is returned unchanged.
 */
int	ft_tolower(int c);

/**
 * @brief Converts the given character to its uppercase form.
 * @param c The character to be converted.
 * @return The given character uppercase version, if it exists, otherwise
 * it is returned unchanged.
 */
int	ft_toupper(int c);

#endif
