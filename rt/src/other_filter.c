/*
** other_filter.c for other_filter in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue May 28 13:44:12 2013 luc sinet
** Last update Sun Jun  9 03:36:01 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "change_color.h"
#include "pars.h"

unsigned int	revers_filter(unsigned int color, UNUSED t_opt *opt)
{
  unsigned char	comp[3];

  decomp_color(color, comp);
  comp[0] = LIMIT(2.0 * (128 - comp[0]) + comp[0], 0, 255);
  comp[1] = LIMIT(2.0 * (128 - comp[1]) + comp[1], 0, 255);
  comp[2] = LIMIT(2.0 * (128 - comp[2]) + comp[2], 0, 255);
  return (recomp_color(comp));
}

unsigned int	apply_contrast(unsigned int color, t_opt *opt)
{
  unsigned char	comp[3];

  decomp_color(color, comp);
  comp[0] = LIMIT((((double)comp[0] / 255 - 0.5) * opt->contrast + 0.5)
                  * 255, 0, 255);
  comp[1] = LIMIT((((double)comp[1] / 255 - 0.5) * opt->contrast + 0.5)
                  * 255, 0, 255);
  comp[2] = LIMIT((((double)comp[2] / 255 - 0.5) * opt->contrast + 0.5)
                  * 255, 0, 255);
  return (recomp_color(comp));
}

unsigned int	saturation(unsigned int color, double val)
{
  double	pert;
  unsigned char	comp[3];

  decomp_color(color, comp);
  pert = sqrt(comp[0] * comp[0] * 0.299 + comp[1] * comp[1] * 0.587
	      + comp[2] * comp[2] * 0.114);
  comp[0] = LIMIT(pert + (comp[0] - pert) * val, 0 , 255);
  comp[1] = LIMIT(pert + (comp[1] - pert) * val, 0 , 255);
  comp[2] = LIMIT(pert + (comp[2] - pert) * val, 0 , 255);
  return (recomp_color(comp));
}

unsigned int	xorus_filter(unsigned int color, UNUSED t_opt *opt)
{
  color = (color ^ 0x64a8bdfe);
  return (color);
}
