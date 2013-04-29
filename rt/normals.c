/*
** normals.c for normals in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Mar 31 13:20:23 2013 luc sinet
** Last update Mon Apr 22 23:53:07 2013 luc sinet
*/

#include <math.h>
#include "include/main.h"
#include "include/light.h"

void	perturb_normal(double *nvec, double *obj_coor, double *pert)
{
  if ((int)pert[0] == 1)
    nvec[0] = nvec[0] + cos(obj_coor[0] / pert[1])
      * (norme_vec(nvec) / pert[1]);
  if ((int)pert[2] == 1)
    nvec[1] = nvec[1] + cos(obj_coor[1] / pert[3])
      * (norme_vec(nvec) / pert[3]);
  if ((int)pert[4] == 1)
    nvec[2] = nvec[2] + cos(obj_coor[2] / pert[5])
      * (norme_vec(nvec) / pert[5]);
}

void	sphere_normal(double *nvec, double *obj_coor, double *pert)
{
  nvec[0] = obj_coor[0];
  nvec[1] = obj_coor[1];
  nvec[2] = obj_coor[2];
  perturb_normal(nvec, obj_coor, pert);
}

void	plan_normal(double *nvec, double *obj_coor, double *pert)
{
  nvec[0] = 0;
  nvec[1] = 0;
  nvec[2] = 100;
  perturb_normal(nvec, obj_coor, pert);
}

void	cone_normal(double *nvec, double *obj_coor, double *pert)
{
  nvec[0] = obj_coor[0];
  nvec[1] = obj_coor[1];
  nvec[2] = -0.6 * obj_coor[2];
  perturb_normal(nvec, obj_coor, pert);
}

void	cylinder_normal(double *nvec, double *obj_coor, double *pert)
{
  nvec[0] = obj_coor[0];
  nvec[1] = obj_coor[1];
  nvec[2] = 0;
  perturb_normal(nvec, obj_coor, pert);
}
void	moebius_normal(double *nvec, double *obj_coor, double *pert)
{
  nvec[0] = obj_coor[0];
  nvec[1] = obj_coor[1];
  nvec[2] = obj_coor[2];
  perturb_normal(nvec, obj_coor, pert);
}
