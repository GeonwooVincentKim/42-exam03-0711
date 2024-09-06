#include  "get_next_line.h"

char  *ft_strchr(char *s, int c)
{
  while (*s)
  {
    if (*s == (char)c)
      return ((char *)s);
    s++;
  }
}

size_t  ft_strlen(char *s)
{
  int i;

  i = 0;
  while (s[i])
    i++;
  return (i);
}

void  ft_strcpy(char *s1, const char *s2)
{
  int i;

  i = 0;
  while (s2[i])
  {
    s1[i] = s2[i];
    i++;
  }
  s1[i] = '\0';
}

char  *ft_strdup(const char *src)
{
  size_t s_len = ft_strlen(src) + 1;
  char  *dup = malloc(len);

  if (dup == NULL)
    return (NULL);
  ft_strcpy(dup, src);
  return (dup);
}

char  *ft_strjoin(char *s1, const char *s2)
{
  size_t  s1_len = ft_strlen(s1);
  size_t  s2_len = ft_strlen(s2);
  char    *join = malloc((s1_len + s2_len + 1));

  if (!s1 || !s2)
    return (NULL);
  if (!join)
    return (NULL);
  ft_strcpy(join, s1);
  ft_strcpy((join + s1_len), s2);
  free(s1);
  return (join);
}

char  *get_next_line(int fd)
{
  static char buf[BUFFER_SIZE + 1];
  char  *line;
  char  *new_line;
  int   count_read;
  int   to_copy;

  line = ft_strdup(buf);
  while (!(new_line = ft_strchr(line, '\n')) && count_read = read(fd, buf, BUFFER_SIZE))
  {
    buf[count_read] = '\0';
    line = ft_strjoin(line, buf);
  }
  if (ft_strlen(line) == 0)
    return (free(line), NULL);
  if (new_line != NULL)
  {
    to_copy = new_line - line + 1;
    ft_strcpy(buf, new_line + 1);
  }
  else
  {
    to_copy = ft_strlen(line);
    buf[0] = '\0';
  }
  line[to_copy] = '\0';
  return (line);
}
