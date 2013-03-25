/*
** lightning.h for light in /home/sinet_l//rtv1-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 14 13:09:39 2013 luc sinet
** Last update Thu Mar 21 17:10:55 2013 luc sinet
*/

#ifndef LIG_H_
# define LIG_H_

# define NX(type, xp) (type == 1) ? 0.0 : xp;
# define NY(type, yp) (type == 1) ? 0.0 : yp;
# define NZ(t, c, zp) (t == 1) ? 100 : (t == 2) ? (-c * zp) : (t == 3) ? 0 : zp

typedef struct	s_lco
{
  double	obj_coor[3];
  double	nvec[3];
}		t_lco;

unsigned int	get_light(t_rt *rpt, double k, unsigned int color);
unsigned int    apply_light(unsigned int color, double cosa, t_lig *lpt);

#endif