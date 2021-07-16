#include "fdf.h"

size_t		get_cnt(char *s, char c)
{
	size_t		cnt;

	cnt = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			cnt++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (cnt);
}

int		free_machine_str(char **s, size_t idx)
{
	while (s[idx] != NULL && idx >= 0)
	{
		free(s[idx]);
		s[idx] = NULL;
		idx--;
	}
	free(s);
	s = NULL;
	return (0);
}

int		ft_strsplit(char *s, char c)
{
	size_t		idx;
	size_t		len;
	size_t		word_cnt;
	char		**words;
	int			i;
	if (!s || !(words = (char **)malloc(sizeof(char *) * (get_cnt(s, c) + 1))))
		return (0);
	word_cnt = get_cnt(s, c);
	idx = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = 0;
			while (*(s + len) && *(s + len) != c)
				len++;
			if (idx < word_cnt && !(words[idx++] = ft_substr(s, 0, len)))
				return (free_machine_str(words, idx));
			s += len;
		}
	}
	words[idx] = 0;
	return ((int)idx);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	index;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	index = 0;
	while (index < len)
	{
		substr[index] = *(s + start + index);
		index++;
	}
	substr[index] = '\0';
	return (substr);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s1);
	if (!(ptr = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memcpy(ptr, s1, size);
	*(ptr + size) = '\0';
	return (ptr);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		n--;
	}
	return (dst);
}

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
		return (i);
}

char	**ft_split(char *s, char c)
{
	size_t		idx;
	size_t		len;
	size_t		word_cnt;
	char		**words;
	int			i;
	if (!s || !(words = (char **)malloc(sizeof(char *) * (get_cnt(s, c) + 1))))
		return (NULL);
	word_cnt = get_cnt(s, c);
	idx = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = 0;
			while (*(s + len) && *(s + len) != c)
				len++;
			if (idx < word_cnt && !(words[idx++] = ft_substr(s, 0, len)))
				return (free_machine(words, idx));
			s += len;
		}
	}
	words[idx] = 0;
	return (words);
}

char		**free_machine(char **s, size_t idx)
{
	while (s[idx] != NULL && idx >= 0)
	{
		free(s[idx]);
		s[idx] = NULL;
		idx--;
	}
	free(s);
	s = NULL;
	return (NULL);
}