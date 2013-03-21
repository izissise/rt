/*
** init.c for init in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Feb 25 17:22:40 2013 luc sinet
** Last update Wed Mar 20 23:24:11 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "pars.h"

void	init_light(t_lig *ltab, t_pars *opt)
{
  int	i;
  int	x;

  i = 0;
  while (i < opt->nb_light)
    {
      x = 0;
      ltab[i].on = 0;
      while (x < 3)
	ltab[i].pos[x++] = IVAL;
      ltab[i].intensity = 1.0;
      i++;
    }
}

void    init_elem(t_obj *tab, t_pars *opt)
{
  int   i;
  int   x;

  i = 0;
  while (i < opt->nb_shape)
    {
      x = 0;
      tab[i].type = -1;
      while (x < 3)
	tab[i].pos[x++] = IVAL;
      x = 0;
      while (x < 4)
	tab[i].angle[x++] = IVAL;
      tab[i].color = 0x000000;
      tab[i].rayon = 0;
      tab[i].bright = 1.0;
      i++;
    }
}

void	init_cos(t_obj *obj)
{
  int	i;
  int	x;

  i = 0;
  while (obj[i].type != -1)
    {
      x = 0;
      while (x < 3)
	{
	  obj[i].ocos[x] = cos(-RAD(obj[i].angle[x]));
	  obj[i].osin[x] = sin(-RAD(obj[i].angle[x]));
	  ++x;
	}
      ++i;
    }
}