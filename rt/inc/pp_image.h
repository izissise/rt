/*
** pp_image.h for pp_image in /home/sinet_l//igraph
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Nov 14 20:45:42 2012 luc sinet
** Last update Sat Jun  8 17:53:50 2013 adrien dellamaggiora
*/

#ifndef PP_IMAGE_H_
# define PP_IMAGE_H_

typedef struct	s_par
{
  int		imgwidth;
  int		imgheight;
  void		*win_ptr;
  void		*mlx_ptr;
  void		*img_ptr;
  char		*data;
  double       	**img_obj;
  int		*timg_obj;
  int		state;
  int		bpp;
  int		sizeline;
  int		endian;
}		t_par;

int	my_pixel_put_to_image(int x, int y, t_par *par, unsigned int color);

#endif /* !PP_IMAGE_H_ */
