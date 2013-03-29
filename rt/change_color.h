/*
** change_color.h for change in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 27 17:42:09 2013 luc sinet
** Last update Thu Mar 28 17:49:30 2013 luc sinet
*/

#ifndef CCL_H_
# define CCL_H_

unsigned int	apply_light(unsigned int color, double lamb, t_lig *lpt,
			    t_obj *ept);
void	   	decomp_color(unsigned int color, unsigned char *ncolor);
unsigned int   	recomp_color(unsigned char *color);

#endif