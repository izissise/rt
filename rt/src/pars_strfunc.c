/*
** strcmp.c for strcmp in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Feb 15 12:36:24 2013 luc sinet
** Last update Thu May  9 10:27:19 2013 Adrien Della Maggiora
*/

#include <stdlib.h>
#include <unistd.h>
#include "str.h"
#include "main.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while ((s1[i] || s2[i]) && i < n)
    {
      if (s1[i] != s2[i])
        return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] || s2[i])
    {
      if (s1[i] != s2[i])
        return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return ;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

void	my_putchar(char c, int fd)
{
  my_putbyte(&c, fd, 1);
}
