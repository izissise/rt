/*
** supersampling.c for supersampling in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Apr  5 11:07:42 2013 luc sinet
** Last update Fri Apr 12 19:03:03 2013 Adrien Della Maggiora
*/

#include "include/main.h"
#include "include/change_color.h"
#include "include/supersampling.h"

unsigned int	mix_color(unsigned int *tab, int ssp)
{
  unsigned char	final_comp[3];
  unsigned char	temp_comp[3];
  int		i;

  i = 1;
  decomp_color(tab[0], final_comp);
  while (i < ssp)
    {
      decomp_color(tab[i], temp_comp);
      final_comp[0] = (final_comp[0] + temp_comp[0]) / 2.0;
      final_comp[1] = (final_comp[1] + temp_comp[1]) / 2.0;
      final_comp[2] = (final_comp[2] + temp_comp[2]) / 2.0;
      ++i;
    }
  return (recomp_color(final_comp));
}

unsigned int   	supersampling(t_rt *rpt, t_samp *spt, int x, int y)
{
  double	spacing;
  double	pos[2];
  int		i;
  int		ssp;

  spacing = spt->spacing;
  pos[1] = y;
  i = 0;
  ssp = rpt->opt->aa;
  while (i < ssp)
    {
      pos[0] = x;
      while (i < ssp && pos[0] < x + 1)
	{
	  new_coor(rpt->vpt, rpt->cpt, pos[0], pos[1]);
	  spt->pixel[i] = get_pixel_color(rpt);
	  pos[0] += spacing;
	  ++i;
	}
      pos[1] += spacing;
    }
  return (mix_color(spt->pixel, ssp));
}
