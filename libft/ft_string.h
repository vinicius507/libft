/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:55:26 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 15:51:20 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H

# include <stdlib.h>

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_strnjoin(const char *s1, const char *s2, size_t n);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

size_t	ft_strlcat(char *dest, const char *src, size_t size);

char	*ft_striter(const char *s, int (*f)(int));

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

int		ft_strcmp(const char *s1, const char *s2);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strtrim(const char *str, const char *set);

char	*ft_substr(const char *s, unsigned int start, size_t len);

char	**ft_split(const char *s, char c);

#endif
