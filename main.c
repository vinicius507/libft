/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:57:22 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/14 21:44:27 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdint.h>
#include "libft.h"

#define OK_MSG "\e[38;5;42mOK\e[0m"
#define KO_MSG "\e[38;5;168mKO\e[0m, "

void	print_test(const char *function
		, const char *params
		, const uint8_t error
		, const char *error_msg)
{
	const char	*msg;
	char		*status;

	if (error)
	{
		msg = error_msg;
		status = KO_MSG;
	}
	else
	{
		msg = "";
		status = OK_MSG;
	}
	printf("\e[38;5;38m[%s]\e[0m (%s)\n"
		"Result: %s%s\n",
		function,
		params,
		status,
		msg);
}

int	main(void)
{
	char	*params;
	char	*error_msg;

	// NOTE: ft_memset
	int		i;
	int		values[8] = {0, 1, 7, 16, 64, 122, 178, 255};
	t_list	teste;
	t_list	teste2;

	i = 0;
	while (i < 8)
	{
		ft_memset(&teste, values[i], sizeof(t_list));
		memset(&teste2, values[i], sizeof(t_list));
		error_msg = malloc(200);
		params = malloc(64);
		sprintf(params
				, "s = t_list *, c = %d, n = %lu"
				, values[i], sizeof(t_list)); 
		sprintf(error_msg
				, "Expected: { content: %016lx, next: %016lx}, "
				" Got: { content: %016lx, next: %016lx"
				, (unsigned long int)teste2.content, (unsigned long int)teste2.next
				, (unsigned long int)teste.content, (unsigned long int)teste.next);
		print_test("ft_memset"
				, params
				, teste.content != teste2.content
				|| teste.next != teste2.next
				, error_msg);
		free(params);
		free(error_msg);
		i++;
	}
	// NOTE: ft_bzero
	params = malloc(22);
	error_msg = malloc(100);
	ft_bzero(&teste, sizeof(t_list));
	bzero(&teste2, sizeof(t_list));
	sprintf(params
			, "s = t_list *, n = %lu"
			, sizeof(t_list)); 
	sprintf(error_msg
			, "Expected: { content: 0, next: 0}, "
			" Got: { content: %016lx, next: %016lx"
			, (unsigned long int)teste.content, (unsigned long int)teste.next);
	print_test("ft_bzero"
			, params
			, teste.content != teste2.content
			|| teste.next != teste2.next
			, error_msg);
	free(params);
	free(error_msg);
	// NOTE: ft_strlen
	char *str[2] = {"", "This is a string"};
	size_t len;
	size_t ft_len;
	i = 0;
	while (i < 2)
	{
		len = strlen(str[i]);
		ft_len = ft_strlen(str[i]);
		params = malloc(9 + strlen(str[i]));
		error_msg = malloc(100);
		sprintf(params
				, "str = \"%s\""
				, str[i]); 
		sprintf(error_msg
				, "Expected: %lu, Got: %lu"
				, len, ft_len);
		print_test("ft_strlen"
				, params
				, len != ft_len
				, error_msg);
		free(params);
		free(error_msg);
		i++;
	}
	// NOTE: ft_substr
	char *src = "This is a string";
	char *dest;

	dest = ft_substr(src, 0, 4);
	error_msg = malloc(100);
	sprintf(error_msg
			, "Expected: \"This\", Got: %s\n"
			, dest);
	print_test("ft_substr"
			, "src = \"This is a string\", start = 0, len = 4"
			, strcmp("This", dest)
			, error_msg);
	free(error_msg);
	free(dest);
	dest = ft_substr(src, 20, 4);
	print_test("ft_substr"
			, "src = \"This is a string\", start = 20, len = 4"
			, dest != NULL
			, "Expected dest to be a NULL pointer.");
	free(dest);
	src = "";
	dest = ft_substr(src, 0, 4);
	error_msg = malloc(100);
	print_test("ft_substr"
			, "src = \"\", start = 0, len = 4"
			, strcmp("", dest)
			, "Expected dest to be a NULL pointer.");
	free(dest);
	free(error_msg);
	// NOTE: ft_memcpy
	char *src_mem = "abcdefg";
	char *dest_mem;
	char *ft_dest_mem;

	dest_mem = malloc(8);
	ft_dest_mem = malloc(8);
	memcpy(dest_mem, src_mem, 8);
	ft_memcpy(ft_dest_mem, src_mem, 8);
	print_test("ft_memcpy"
			, "dest = char *, src = \"abcdefg\", n = 8"
			, memcmp(ft_dest_mem, dest_mem, 8)
			, "Copied memory sector doesn't match expected result.");
	free(dest_mem);
	free(ft_dest_mem);
	// NOTE: ft_memccpy
	dest_mem = calloc(8, sizeof(char));
	ft_dest_mem = calloc(8, sizeof(char));
	memccpy(dest_mem, src_mem, 'f', 8);
	ft_memccpy(ft_dest_mem, src_mem, 'f', 8);
	print_test("ft_memccpy"
			, "dest = char *, src = \"abcdefg\", c = 'f', n = 8"
			, memcmp(ft_dest_mem, dest_mem, 8)
			, "Copied memory sector doesn't match expected result.");
	free(dest_mem);
	free(ft_dest_mem);
	// NOTE: ft_memmove
	dest_mem = malloc(8);
	ft_dest_mem = malloc(8);
	memmove(dest_mem, src_mem, 8);
	ft_memmove(ft_dest_mem, src_mem, 8);
	print_test("ft_memmove",
			"dest = char *, src = \"abcdefg\", n = 8",
			memcmp(ft_dest_mem, dest_mem, 8),
			"Copied memory sector doesn't match expected result.");
	free(dest_mem);
	free(ft_dest_mem);
	dest_mem = malloc(8);
	ft_dest_mem = malloc(8);
	memcpy(dest_mem, src_mem, 8);
	memcpy(ft_dest_mem, src_mem, 8);
	memmove(dest_mem, dest_mem + 3, 5);
	ft_memmove(ft_dest_mem, ft_dest_mem + 3, 5);
	print_test("ft_memmove",
			"dest = \"abcdefg\", src = \"defg\", n = 8",
			memcmp(ft_dest_mem, dest_mem, 8),
			"Copied memory sector doesn't match expected result.");
	free(dest_mem);
	free(ft_dest_mem);
	// NOTE: ft_memchr
	char	*res;
	char	*ft_res;

	res = memchr(src_mem, 'f', 8);
	ft_res = ft_memchr(src_mem, 'f', 8);
	error_msg = malloc(100);
	sprintf(error_msg,
			"Expected: %p, Got: %p",
			res,
			ft_res);
	print_test("ft_memchr",
			"s = \"abcdefg\", c = 'f', n = 8",
			res != ft_res,
			error_msg);
	free(error_msg);
	// NOTE: ft_memcmp
	dest_mem = malloc(8);
	ft_dest_mem = malloc(8);
	memcpy(dest_mem, src_mem, 8);
	memcpy(ft_dest_mem, src_mem, 8);
	error_msg = malloc(40);
	sprintf(error_msg,
			"Expected: 0, Got: %d",
			ft_memcmp(ft_dest_mem, src_mem, 8));
	print_test("ft_memcmp",
			"s1 = \"abcdefg\", s2 = \"abcdefg\", 8",
			memcmp(dest_mem, src_mem, 8) != ft_memcmp(ft_dest_mem, src_mem, 8),
			error_msg);
	free(error_msg);
	free(dest_mem);
	free(ft_dest_mem);
	dest_mem = strcpy(malloc(8), "abcddfg");
	ft_dest_mem = strcpy(malloc(8), "abcddfg");
	error_msg = malloc(40);
	sprintf(error_msg,
			"Expected: %d, Got: %d",
			memcmp(dest_mem, src_mem, 8),
			ft_memcmp(ft_dest_mem, src_mem, 8));
	print_test("ft_memcmp",
			"s1 = \"abcdefg\", s2 = \"abcdefg\", 8",
			memcmp(dest_mem, src_mem, 8) != ft_memcmp(ft_dest_mem, src_mem, 8),
			error_msg);
	free(error_msg);
	free(dest_mem);
	free(ft_dest_mem);
	return (0);
}
