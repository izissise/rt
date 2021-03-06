/*
** antialiasing.c for antialiasing.c in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Apr  8 21:05:59 2013 luc sinet
** Last update Sat Jun  8 18:14:48 2013 maxime lavandier
*/

#include <unistd.h>
#include "main.h"
#include "supersampling.h"

void	emphasize_edges(int *img, t_par *ppt)
{
  int	y;
  int	x;

  y = 0;
  while (y < ppt->imgheight)
    {
      x = 0;
      while (x < ppt->imgwidth)
        {
          if (img[y * ppt->imgwidth + x] == -1)
            my_pixel_put_to_image(x, y, ppt, 0x000000);
          ++x;
        }
      print_i(ppt);
      usleep(8000);
      ++y;
    }
  print_i(ppt);
}

void	apply_supersampling(t_rt *rpt, t_par *ppt, t_samp *spt)
{
  int	*img;
  int	x;
  int	y;

  y = 0;
  img = ppt->timg_obj;
  emphasize_edges(img, ppt);
  print_i(ppt);
  while (y < ppt->imgheight)
    {
      x = 0;
      while (x < ppt->imgwidth)
        {
          if (img[y * ppt->imgwidth + x] == -1)
            my_pixel_put_to_image(x, y, ppt, supersampling(rpt, spt, x, y));
          ++x;
        }
      usleep(8000);
      print_i(ppt);
      ++y;
    }
}
