/*
** main.c for main in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Feb 25 10:36:59 2013 luc sinet
** Last update Thu May 30 21:14:46 2013 luc sinet
*/

#include <time.h>
#include "main.h"
#include "pars.h"
#include "mlx.h"
#include "bmp_loader.h"

void	free_all(t_rt *rpt, t_par *ppt)
{
  int	i;

  i = 0;
  free(rpt->obj);
  free(rpt->light);
  while (i < WINX * WINY)
    {
      free(ppt->img_obj[i]);
      ++i;
    }
  free(ppt->img_obj);
  free(ppt->timg_obj);
}

int	key_event(int key, t_rt *rpt)
{
  (void)rpt;
  if (key == K_ESC)
    exit(0);
  else if (key == K_P)
    output_bmp(rpt->ppt);
  return (0);
}

int	print_i(t_par *ppt)
{
  mlx_put_image_to_window(ppt->mlx_ptr, ppt->win_ptr, ppt->img_ptr, 0 , 0);
  return (0);
}

int	creat_win(t_par *ppt)
{
  int	y;

  y = 0;
  if ((ppt->mlx_ptr = mlx_init()) == NULL)
    return (merror("Couldn't init mlx\n", -1));
  else if ((ppt->img_obj = malloc(sizeof(double *) * (WINY * WINX))) == NULL ||
	   (ppt->timg_obj = malloc(sizeof(int) * (WINY * WINX))) == NULL)
    return (merror("Malloc error\n", -1));
  while (y < WINY * WINX)
    {
      if ((ppt->img_obj[y] = malloc(sizeof(double) * 3)) == NULL)
	return (merror("Malloc error\n", -1));
      ++y;
    }
  ppt->win_ptr =  mlx_new_window(ppt->mlx_ptr, WINX, WINY, " rt ");
  ppt->img_ptr = mlx_new_image(ppt->mlx_ptr, WINX, WINY);
  ppt->data = mlx_get_data_addr(ppt->img_ptr,
				&ppt->bpp, &ppt->sizeline, &ppt->endian);
  return (0);
}

int		main(int ac, char **av)
{
  t_rt		rpt;
  t_par		ppt;
  t_vec		vpt;
  t_cam		cpt;
  t_opt		opt;
  t_text	text;

  rpt.vpt = &vpt;
  rpt.cpt = &cpt;
  rpt.opt = &opt;
  rpt.text = &text;
  rpt.ppt = &ppt;
  if (ac == 1)
    return (merror("You need to specifie a config file in argument\n", -1));
  if (pars(&rpt, av[1], &cpt) < 0 || creat_win(&ppt) == -1)
    return (-1);
  init_cos(rpt.obj);
  calc_pixel(&rpt, &cpt, &vpt, &ppt);
  free_all(&rpt, &ppt);
  mlx_key_hook(ppt.win_ptr, key_event, &rpt);
  mlx_expose_hook(ppt.win_ptr, print_i, &ppt);
  mlx_loop(ppt.mlx_ptr);
  return (0);
}
