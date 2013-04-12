/*
** normals.c for normals in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Mar 31 13:20:23 2013 luc sinet
** Last update Fri Apr 12 15:44:26 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "light.h"

void	perturb_normal(double *nvec, double *obj_coor, double *pert)
{
  if (pert[0] == 1)
    nvec[0] = nvec[0] + cos(obj_coor[0] / pert[1])
      * (vec_norme(nvec) / pert[1]);
  if (pert[2] == 1)
    nvec[1] = nvec[1] + cos(obj_coor[1] / pert[3])
      * (vec_norme(nvec) / pert[3]);
  if (pert[4] == 1)
    nvec[2] = nvec[2] + cos(obj_coor[2] / pert[5])
      * (vec_norme(nvec) / pert[5]);
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
