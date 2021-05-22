#include <stdio.h>
#ifdef __linux__
#include <bsd/string.h>
#endif
#ifdef __apple__
#include <string.h>
#endif
#include <strings.h>
#include <ctype.h>
#include <stdint.h>
#include <limits.h>
#include "libft.h"

#define OK_MSG "\e[38;5;42mOK\e[0m"
#define KO_MSG "\e[38;5;168mKO\e[0m, "

void	ft_test(const char *function
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

char	mapi_t1(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (toupper(c));
	return (tolower(c));
}

char	mapi_t2(unsigned int i, char c)
{
	if (i % 2)
		return (toupper(c));
	return (tolower(c));
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
		ft_test("ft_memset"
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
	ft_test("ft_bzero"
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
		ft_test("ft_strlen"
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
	ft_test("ft_substr"
		, "src = \"This is a string\", start = 0, len = 4"
		, strcmp("This", dest)
		, error_msg);
	free(error_msg);
	free(dest);

	src = "";
	dest = ft_substr(src, 0, 4);
	ft_test("ft_substr"
		, "src = \"\", start = 0, len = 4"
		, strcmp("", dest)
		, "Expected dest to be a NULL pointer.");
	free(dest);

	src = "tripouille";
	dest = ft_substr(src, 100, 1);
	error_msg = malloc(100);
	sprintf(error_msg
		, "Expected: \"\", Got: \"%s\"\n"
		, dest);
	ft_test("ft_substr"
		, "src = \"tripouille\", start = 100, len = 1"
		, strcmp("", dest)
		, error_msg);
	free(dest);
	free(error_msg);

	dest = ft_substr(src, 1, 1);
	error_msg = malloc(100);
	sprintf(error_msg
		, "Expected: \"r\", Got: \"%s\"\n"
		, dest);
	ft_test("ft_substr"
		, "src = \"tripouille\", start = 1, len = 1"
		, strcmp("r", dest)
		, error_msg);
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
	ft_test("ft_memcpy"
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
	ft_test("ft_memccpy"
		, "dest = char *, src = \"abcdefg\", c = 'f', n = 8"
		, memcmp(ft_dest_mem, dest_mem, 8)
		, "Copied memory sector doesn't match expected result.");
	free(dest_mem);
	free(ft_dest_mem);

	void *ptr;
	void *ft_ptr;

	ft_dest_mem = calloc(8, sizeof(char));
	ptr = memccpy(ft_dest_mem, src_mem, 'f', 8);
	ft_ptr = ft_memccpy(ft_dest_mem, src_mem, 'f', 8);
	ft_test("ft_memccpy"
		, "dest = char *, src = \"abcdefg\", c = 'f', n = 8"
		, ptr != ft_ptr 
		, "Copied memory sector doesn't match expected result.");
	free(ft_dest_mem);

	// NOTE: ft_memmove
	dest_mem = malloc(8);
	ft_dest_mem = malloc(8);
	memmove(dest_mem, src_mem, 8);
	ft_memmove(ft_dest_mem, src_mem, 8);
	ft_test("ft_memmove",
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
	ft_test("ft_memmove",
		"dest = \"abcdefg\", src = \"defg\", n = 8",
		memcmp(ft_dest_mem, dest_mem, 8),
		"Copied memory sector doesn't match expected result.");
	free(dest_mem);
	free(ft_dest_mem);

	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};
	ft_memmove(sResult + 1, sResult, 2);
	ft_test("ft_memmove",
		"dest = src + 1, src = { 67, 68, 67, 69, 0, 45 }, n = 8",
		memcmp(sResult, sResult2, 7),
		"Copied memory sector doesn't match expected result.");
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
	ft_test("ft_memchr",
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
	ft_test("ft_memcmp",
		"s1 = \"abcdefg\", s2 = \"abcdefg\", n = 8",
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
	ft_test("ft_memcmp",
		"s1 = \"abcdefg\", s2 = \"abcdefg\", n = 8",
		memcmp(dest_mem, src_mem, 8) != ft_memcmp(ft_dest_mem, src_mem, 8),
		error_msg);
	free(error_msg);
	free(dest_mem);
	free(ft_dest_mem);

	char s[] = { -128, 0, 127, 0 };
	char spy[] = { -128, 0, 127, 0 };
	error_msg = malloc(40);
	sprintf(error_msg,
		"Expected: %d, Got: %d",
		memcmp(s, spy, 4),
		ft_memcmp(s, spy, 4));
	ft_test("ft_memcmp",
		"s1 = { -128, 0, 127, 0 }, s2 = { -128, 0, 127, 0 }, n = 4",
		memcmp(s, spy, 4) != ft_memcmp(s, spy, 4),
		error_msg);
	free(error_msg);

	char s1[] = { -128, 0, 127, 0 };
	char spy1[] = { 0, 0, 127, 0 };
	error_msg = malloc(40);
	sprintf(error_msg,
		"Expected: %d, Got: %d",
		memcmp(s1, spy1, 0),
		ft_memcmp(s1, spy1, 0));
	ft_test("ft_memcmp",
		"s1 = { -128, 0, 127, 0 }, s2 = { 0, 0, 127, 0 }, n = 0",
		memcmp(s1, spy1, 0) != ft_memcmp(s1, spy1, 0),
		error_msg);
	free(error_msg);
	// NOTE: ft_strlcpy
	char	*ft_dest;

	src = "alo galera";
	dest = malloc(8);
	ft_dest = malloc(8);
	error_msg = malloc(40);
	len = strlcpy(dest, src, 8);
	ft_len = ft_strlcpy(ft_dest, src, 8);
	sprintf(error_msg,
		"Expected: %lu, Got: %lu",
		len, ft_len);

	ft_test("ft_strlcpy",
		"dest = char *, src = \"alo galera\", size = 8",
		len != ft_len,
		error_msg);
	free(dest);
	free(ft_dest);
	free(error_msg);

	src = "alo galera";
	dest = malloc(8);
	ft_dest = malloc(8);
	error_msg = malloc(40);
	len = strlcpy(dest, src, 0);
	ft_len = ft_strlcpy(ft_dest, src, 0);
	sprintf(error_msg,
		"Expected: %lu, Got: %lu",
		len, ft_len);

	ft_test("ft_strlcpy",
		"dest = char *, src = \"alo galera\", size = 0",
		len != ft_len,
		error_msg);
	free(dest);
	free(ft_dest);
	free(error_msg);
	// NOTE: ft_strlcat
	dest = strcpy(malloc(32), "abcdefg");
	ft_dest = strcpy(malloc(32), "abcdefg");
	len = strlcat(dest, src, 0);
	ft_len = ft_strlcat(ft_dest, src, 0);
	ft_test("ft_strlcat",
		"dest = \"abcdefg\", src = \"alo galera\", size = 0",
		len != ft_len,
		"Returned Size is wrong.");
	ft_test("ft_strlcat",
		"dest = \"abcdefg\", src = \"alo galera\", size = 0",
		strcmp(dest, ft_dest),
		"String is not as expected");
	free(dest);
	free(ft_dest);
	dest = strcpy(malloc(32), "abcdefg");
	ft_dest = strcpy(malloc(32), "abcdefg");
	len = strlcat(dest, src, 6);
	ft_len = ft_strlcat(ft_dest, src, 6);
	ft_test("ft_strlcat",
		"dest = \"abcdefg\", src = \"alo galera\", size = 0",
		len != ft_len,
		"Returned Size is wrong.");
	ft_test("ft_strlcat",
		"dest = \"abcdefg\", src = \"alo galera\", size = 0",
		strcmp(dest, ft_dest),
		"String is not as expected");
	free(dest);
	free(ft_dest);
	dest = strcpy(malloc(32), "abcdefg");
	ft_dest = strcpy(malloc(32), "abcdefg");
	len = strlcat(dest, src, 16);
	ft_len = ft_strlcat(ft_dest, src, 16);
	ft_test("ft_strlcat",
		"dest = \"abcdefg\", src = \"alo galera\", size = 0",
		len != ft_len,
		"Returned Size is wrong.");
	ft_test("ft_strlcat",
		"dest = \"abcdefg\", src = \"alo galera\", size = 0",
		strcmp(dest, ft_dest),
		"String is not as expected");
	free(dest);
	free(ft_dest);
	dest = strcpy(malloc(32), "abcdefg");
	ft_dest = strcpy(malloc(32), "abcdefg");
	len = strlcat(dest, src, 30);
	ft_len = ft_strlcat(ft_dest, src, 30);
	ft_test("ft_strlcat",
		"dest = \"abcdefg\", src = \"alo galera\", size = 0",
		len != ft_len,
		"Returned Size is wrong.");
	ft_test("ft_strlcat",
		"dest = \"abcdefg\", src = \"alo galera\", size = 0",
		strcmp(dest, ft_dest),
		"String is not as expected");
	free(dest);
	free(ft_dest);

	// NOTE: ft_strchr
	src = "abcdefghijklmnoprstuvzwyz";
	dest = strchr(src, 'n');
	ft_dest = ft_strchr(src, 'n');
	ft_test("ft_strchr",
		"s = \"abcdefghijklmnoprstuvzwyz\", c = 'n'",
		dest != ft_dest,
		"Return value is wrong.");
	dest = strchr(src, '\0');
	ft_dest = ft_strchr(src, '\0');
	ft_test("ft_strchr",
		"s = \"abcdefghijklmnoprstuvzwyz\", c = '\\0'",
		dest != ft_dest,
		"Return value is wrong.");
	src = "abcdefghijklmmoprstuvzwyz";
	dest = strchr(src, 'n');
	ft_dest = ft_strchr(src, 'n');
	ft_test("ft_strchr",
		"s = \"abcdefghijklmnoprstuvzwyz\", c = 'n'",
		dest != ft_dest,
		"Return value is wrong.");
	src = "";
	dest = strchr(src, 'n');
	ft_dest = ft_strchr(src, 'n');
	ft_test("ft_strchr",
		"s = \"\", c = 'n'",
		dest != ft_dest,
		"Return value is wrong.");

	// NOTE: ft_strrchr
	src = "aaabbbccdeeefffggghhjkkkkkl";
	dest = strchr(src, 'f');
	ft_dest = strchr(src, 'f');
	ft_test("ft_strrchr",
		"s = \"aaabbbccdeeefffggghhjkkkkkl\", c = 'f'",
		dest != ft_dest,
		"Return value is wrong.");
	src = "aaabbbccdeeefffggghhjkkkkkl";
	dest = strchr(src, '\0');
	ft_dest = strchr(src, '\0');
	ft_test("ft_strrchr",
		"s = \"aaabbbccdeeefffggghhjkkkkkl\", c = '\\0'",
		dest != ft_dest,
		"Return value is wrong.");
	src = "aaabbbccdeeefffggghhjkkkkkl";
	dest = strchr(src, 'f');
	ft_dest = strchr(src, 'f');
	ft_test("ft_strrchr",
		"s = \"\", c = 'f'",
		dest != ft_dest,
		"Return value is wrong.");
	// NOTE: ft_strnstr
	src = "alo galera do forro";
	dest = strnstr(src, "alo", 4);
	ft_dest = ft_strnstr(src, "alo", 4);
	ft_test("ft_strnstr",
		"big = \"alo galera do forro\", little \"alo\", len = 4",
		dest != ft_dest,
		"Return value is wrong.");
	dest = strnstr(src, "alo", 2);
	ft_dest = ft_strnstr(src, "alo", 2);
	ft_test("ft_strnstr",
		"big = \"alo galera do forro\", little \"alo\", len = 2",
		dest != ft_dest,
		"Return value is wrong.");
	dest = strnstr(src, "", 2);
	ft_dest = ft_strnstr(src, "", 2);
	ft_test("ft_strnstr",
		"big = \"alo galera do forro\", little \"\", len = 2",
		dest != ft_dest,
		"Return value is wrong.");
	dest = strnstr(src, "", 0);
	ft_dest = ft_strnstr(src, "", 0);
	ft_test("ft_strnstr",
		"big = \"alo galera do forro\", little \"\", len = 0",
		dest != ft_dest,
		"Return value is wrong.");
	src = "";
	dest = strnstr(src, "", 0);
	ft_dest = ft_strnstr(src, "", 0);
	ft_test("ft_strnstr",
		"big = \"\", little \"\", len = 0",
		dest != ft_dest,
		"Return value is wrong.");

	src = "aaabcabcd";
	dest = strnstr(src, "aabc", -1);
	ft_dest = ft_strnstr(src, "aabc", -1);
	ft_test("ft_strnstr",
		"big = \"aaabcabcd\", little \"aabc\", len = -1",
		dest != ft_dest,
		"Return value is wrong.");

	src = "aaabcabcd";
	dest = strnstr(src, "aabc", 5);
	ft_dest = ft_strnstr(src, "aabc", 5);
	ft_test("ft_strnstr",
		"big = \"aaabcabcd\", little \"aabc\", len = 5",
		dest != ft_dest,
		"Return value is wrong.");
	// NOTE: ft_atoi
	int i_res;
	int ft_i_res;
	i_res = atoi("  \n\t\v\r \n \f-0");
	ft_i_res = ft_atoi("  \n\t\v\r \n \f-0");
	ft_test("ft_atoi",
		"nptr = \"  \\n\\t\\v\\r \\n \\f-0\"",
		i_res != ft_i_res,
		"Return value is wrong.");
	i_res = atoi("  \n\t\v\r \n \f+0");
	ft_i_res = ft_atoi("  \n\t\v\r \n \f+0");
	ft_test("ft_atoi",
		"nptr = \"  \\n\\t\\v\\r \\n \\f+0\"",
		i_res != ft_i_res,
		"Return value is wrong.");;
	i_res = atoi("  \n\t\v\r \n \f-10");
	ft_i_res = ft_atoi("  \n\t\v\r \n \f-10");
	ft_test("ft_atoi",
		"nptr = \"  \\n\\t\\v\\r \\n \\f-10\"",
		i_res != ft_i_res,
		"Return value is wrong.");
	i_res = atoi("  \n\t\v\r \n \f+10");
	ft_i_res = ft_atoi("  \n\t\v\r \n \f+10");
	ft_test("ft_atoi",
		"nptr = \"  \\n\\t\\v\\r \\n \\f+10\"",
		i_res != ft_i_res,
		"Return value is wrong.");
	i_res = atoi("  \n\t\v\r \n \f+2147483647");
	ft_i_res = ft_atoi("  \n\t\v\r \n \f+2147483647");
	ft_test("ft_atoi",
		"nptr = \"  \\n\\t\\v\\r \\n \\f+2147483647\"",
		i_res != ft_i_res,
		"Return value is wrong.");
	i_res = atoi("  \n\t\v\r \n \f-2147483648");
	ft_i_res = ft_atoi("  \n\t\v\r \n \f-2147483648");
	ft_test("ft_atoi",
		"nptr = \"  \\n\\t\\v\\r \\n \\f-2147483648\"",
		i_res != ft_i_res,
		"Return value is wrong.");

	// NOTE: ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint
	i_res = -1;
	params = NULL;
	while (++i_res <= 127)
	{
		if (!ft_isalpha(i_res) ^ !isalpha(i_res))
		{
			params = malloc(11);
			sprintf(params, "c = 0x%02X", i_res);
			break ;
		}
	}
	error_msg = malloc(40);
	sprintf(error_msg, "Expected: 0x%02X, Got: 0x%02X", isalpha(i_res), ft_isalpha(i_res));
	ft_test("ft_isalpha",
		params == NULL ? "c = ASCII characters up to 127" : params,
		params == NULL ? 0 : (!ft_isalpha(i_res) ^ !isalpha(i_res)),
		error_msg);
	if (params != NULL)
		free(params);
	free(error_msg);

	i_res = -1;
	params = NULL;
	while (++i_res <= 127)
	{
		if (!ft_isdigit(i_res) ^ !isdigit(i_res))
		{
			params = malloc(11);
			sprintf(params, "c = 0x%02X", i_res);
			break ;
		}
	}
	error_msg = malloc(40);
	sprintf(error_msg, "Expected: 0x%02X, Got: 0x%02X", isalpha(i_res), ft_isalpha(i_res));
	ft_test("ft_isdigit",
		params == NULL ? "c = ASCII characters up to 127" : params,
		params == NULL ? 0 : (!ft_isdigit(i_res) ^ !isdigit(i_res)),
		error_msg);
	if (params != NULL)
		free(params);
	free(error_msg);

	i_res = -1;
	params = NULL;
	while (++i_res <= 127)
	{
		if (!ft_isalnum(i_res) ^ !isalnum(i_res))
		{
			params = malloc(11);
			sprintf(params, "c = 0x%02X", i_res);
			break ;
		}
	}
	error_msg = malloc(40);
	sprintf(error_msg, "Expected: 0x%02X, Got: 0x%02X", isalpha(i_res), ft_isalpha(i_res));
	ft_test("ft_isalnum",
		params == NULL ? "c = ASCII characters up to 127" : params,
		params == NULL ? 0 : (!ft_isalnum(i_res) ^ !isalnum(i_res)),
		error_msg);
	if (params != NULL)
		free(params);
	free(error_msg);

	i_res = -1;
	params = NULL;
	while (++i_res <= 255)
	{
		if (!ft_isascii(i_res) ^ !isascii(i_res))
		{
			params = malloc(11);
			sprintf(params, "c = 0x%02X", i_res);
			break ;
		}
	}
	error_msg = malloc(40);
	sprintf(error_msg, "Expected: 0x%02X, Got: 0x%02X", isalpha(i_res), ft_isalpha(i_res));
	ft_test("ft_isascii",
		params == NULL ? "c = 0 to 255" : params,
		params == NULL ? 0 : (!ft_isascii(i_res) ^ !isascii(i_res)),
		error_msg);
	if (params != NULL)
		free(params);
	free(error_msg);

	i_res = -1;
	params = NULL;
	while (++i_res <= 127)
	{
		if (!ft_isprint(i_res) ^ !isprint(i_res))
		{
			params = malloc(11);
			sprintf(params, "c = 0x%02X", i_res);
			break ;
		}
	}
	error_msg = malloc(40);
	sprintf(error_msg, "Expected: 0x%02X, Got: 0x%02X", isalpha(i_res), ft_isalpha(i_res));
	ft_test("ft_isprint",
		params == NULL ? "c = ASCII characters up to 127" : params,
		params == NULL ? 0 : (!ft_isprint(i_res) ^ !isprint(i_res)),
		error_msg);
	if (params != NULL)
		free(params);
	free(error_msg);

	// NOTE: ft_toupper ft_tolower
	i_res = -1;
	params = NULL;
	while (++i_res <= 127)
	{
		if (ft_toupper(i_res) != toupper(i_res))
		{
			params = malloc(11);
			sprintf(params, "c = 0x%02X", i_res);
			break ;
		}
	}
	error_msg = malloc(40);
	sprintf(error_msg, "Expected: 0x%02X, Got: 0x%02X", isalpha(i_res), ft_isalpha(i_res));
	ft_test("ft_toupper",
		params == NULL ? "c = ASCII characters up to 127" : params,
		params == NULL ? 0 : (ft_toupper(i_res) != toupper(i_res)),
		error_msg);
	if (params != NULL)
		free(params);
	free(error_msg);

	i_res = -1;
	params = NULL;
	while (++i_res <= 127)
	{
		if (ft_tolower(i_res) != tolower(i_res))
		{
			params = malloc(11);
			sprintf(params, "c = 0x%02X", i_res);
			break ;
		}
	}
	error_msg = malloc(40);
	sprintf(error_msg, "Expected: 0x%02X, Got: 0x%02X", isalpha(i_res), ft_isalpha(i_res));
	ft_test("ft_tolower",
		params == NULL ? "c = ASCII characters up to 127" : params,
		params == NULL ? 0 : (ft_tolower(i_res) != tolower(i_res)),
		error_msg);
	if (params != NULL)
		free(params);
	free(error_msg);

	// NOTE: ft_calloc
	dest_mem = calloc(10, sizeof(char));
	ft_dest_mem = ft_calloc(10, sizeof(char));
	ft_test("ft_calloc",
		"nmemb = 10, size = sizeof(char)",
		memcmp(dest_mem, ft_dest_mem, 10),
		"Allocated memory is not set to 0");
	free(dest_mem);
	free(ft_dest_mem);
	ft_dest_mem = ft_calloc(0, sizeof(char));
	ft_test("ft_calloc",
		"nmemb = 0, size = sizeof(char)",
		ft_dest_mem != NULL,
		"Return value is not NULL");
	free(ft_dest_mem);
	ft_dest_mem = ft_calloc(10, 0);
	ft_test("ft_calloc",
		"nmemb = 0, size = sizeof(char)",
		ft_dest_mem != NULL,
		"Return value is not NULL");
	free(ft_dest_mem);

	// NOTE: ft_strdup
	src = "alo galera do forro";
	ft_dest = ft_strdup(src);
	ft_test("ft_strdup",
		"s = \"alo galera do forro\"",
		strcmp(src, ft_dest),
		"Dup String does not match");
	free(ft_dest);
	src = "";
	ft_dest = ft_strdup(src);
	ft_test("ft_strdup",
		"s = \"\"",
		strcmp(src, ft_dest),
		"Dup String does not match");
	free(ft_dest);

	// NOTE: ft_strjoin
	src = "alo ";
	dest = "galera";

	ft_dest = ft_strjoin(src, dest);
	ft_test("ft_strjoin",
		"s1 = \"alo \", s2 = \"galera\"",
		strcmp(ft_dest, "alo galera"),
		"Joined string does not match expected result");
	free(ft_dest);

	src = "";
	dest = "";

	ft_dest = ft_strjoin(src, dest);
	ft_test("ft_strjoin",
		"s1 = \"alo \", s2 = \"galera\"",
		strcmp(ft_dest, ""),
		"Joined string does not match expected result");
	free(ft_dest);

	src = "";
	dest = "alo galera";

	ft_dest = ft_strjoin(src, dest);
	ft_test("ft_strjoin",
		"s1 = \"alo \", s2 = \"galera\"",
		strcmp(ft_dest, "alo galera"),
		"Joined string does not match expected result");
	free(ft_dest);

	src = "alo galera";
	dest = "";

	ft_dest = ft_strjoin(src, dest);
	ft_test("ft_strjoin",
		"s1 = \"alo \", s2 = \"galera\"",
		strcmp(ft_dest, "alo galera"),
		"Joined string does not match expected result");
	free(ft_dest);

	// NOTE: ft_strtrim
	dest = strcpy(malloc(11), "alo galera");
	ft_dest = ft_strtrim(dest, "a");
	ft_test("ft_strtrim",
		"s1 = \"alo galera\", set = \"a\"",
		strcmp(ft_dest, "lo galer"),
		"Trailing characters from set");
	free(dest);
	free(ft_dest);

	dest = strcpy(malloc(11), "alo galera");
	ft_dest = ft_strtrim(dest, "alr");
	ft_test("ft_strtrim",
		"s1 = \"alo galera\", set = \"alr\"",
		strcmp(ft_dest, "o gale"),
		"Trailing characters from set");
	free(dest);
	free(ft_dest);

	dest = strcpy(malloc(11), "alo galera");
	ft_dest = ft_strtrim(dest, "");
	ft_test("ft_strtrim",
		"s1 = \"alo galera\", set = \"\"",
		strcmp(ft_dest, "alo galera"),
		"Trailing characters from set");
	free(dest);
	free(ft_dest);

	dest = strcpy(malloc(1), "");
	ft_dest = ft_strtrim(dest, "a\n\tbcdef");
	ft_test("ft_strtrim",
		"s1 = \"\", set = \"a\\n\\tbcdef\"",
		strcmp(ft_dest, ""),
		"Trailing characters from set");
	free(dest);
	free(ft_dest);

	dest = strcpy(malloc(1), "");
	ft_dest = ft_strtrim(dest, "");
	ft_test("ft_strtrim",
		"s1 = \"\", set = \"\"",
		strcmp(ft_dest, ""),
		"Trailing characters from set");
	free(dest);
	free(ft_dest);

	// NOTE: ft_split
	src = "Alo     isso e    uma  string. ";
	char **strs;
	char *lookup[5] = { "Alo", "isso", "e", "uma", "string." };

	strs = ft_split(src, ' ');
	ft_i_res = 0;
	i_res = -1;
	while (strs[++i_res] != NULL && i_res < 10);
	if (i_res != 5)
	{
		ft_i_res = 1;
		ft_test("ft_split",
			"s = \"Alo     isso e    uma  string. \", c = ' '",
			1,
			"Wrong words number.");
	}
	i_res = -1;
	while (ft_i_res == 0 && ++i_res < 5)
	{
		if (strcmp(strs[i_res], lookup[i_res]))
		{
			ft_i_res = 1;
			ft_test("ft_split",
				"s = \"Alo     isso e    uma  string. \", c = ' '",
				1,
				"Splitted words don't match expected result");
		}
		free(strs[i_res]);
	}
	if (!ft_i_res)
	{
		ft_test("ft_split",
			"s = \"Alo     isso e    uma  string. \", c = ' '",
			0,
			"");
	}
	free(strs);

	// NOTE: ft_itoa
	i_res = INT_MAX;
	dest = ft_itoa(i_res);
	ft_test("ft_itoa",
		"n = INT_MAX",
		strcmp(dest, "2147483647"),
		"String does not match INT_MAX.");
	free(dest);

	i_res = INT_MIN;
	dest = ft_itoa(i_res);
	ft_test("ft_itoa",
		"n = INT_MIN",
		strcmp(dest, "-2147483648"),
		"String does not match INT_MIN.");
	free(dest);

	i_res = 0;
	dest = ft_itoa(i_res);
	ft_test("ft_itoa",
		"n = 0",
		strcmp(dest, "0"),
		"String does not match 0.");
	free(dest);

	// NOTE: ft_strmapi
	src = "alo galera do forro";
	dest = ft_strmapi(src, mapi_t1);
	error_msg = malloc(100);
	sprintf(error_msg,
		"Expected: \"AlO GaLeRa dO FoRrO\", got: \"%s\"",
		dest);
	ft_test("ft_strmapi",
		"src = \"alo galera do forro\", f = mapi_t1",
		strcmp(dest, "AlO GaLeRa dO FoRrO"),
		error_msg);
	free(dest);
	free(error_msg);

	src = "alo galera do forro";
	dest = ft_strmapi(src, mapi_t2);
	error_msg = malloc(100);
	sprintf(error_msg,
		"Expected: \"aLo gAlErA Do fOrRo\", got: \"%s\"",
		dest);
	ft_test("ft_strmapi",
		"src = \"alo galera do forro\", f = mapi_t2",
		strcmp(dest, "aLo gAlErA Do fOrRo"),
		error_msg);
	free(dest);
	free(error_msg);

	src = "";
	dest = ft_strmapi(src, mapi_t1);
	error_msg = malloc(100);
	sprintf(error_msg,
		"Expected: \"\", got: \"%s\"",
		dest);
	ft_test("ft_strmapi",
		"src = \"\", f = mapi_t1",
		strcmp(dest, ""),
		error_msg);
	free(dest);
	free(error_msg);
	return (0);
}
