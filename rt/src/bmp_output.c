/*
** bmp_output.c for bmp_output in /home/adrien/output_bmp
**
** Made by Adrien Della Maggiora
** Login   <adrien@mint>
**
** Started on  Wed May 22 16:27:01 2013 Adrien Della Maggiora
** Last update Sat Jun  8 18:15:02 2013 maxime lavandier
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"
#include "pp_image.h"
#include "bmp_loader.h"

void	init_bmp(t_info_bmp *image, t_par *ppt)
{
  image->magic_nb[0] = 0x42;
  image->magic_nb[1] = 0x4D;
  image->size = ((ppt->imgwidth * 3) + ((ppt->imgwidth * 3) % 4))
                * ppt->imgheight + 54;
  image->reserve = 0;
  image->offset = 54;
  image->size_info = 40;
  image->widht = ppt->imgwidth;
  image->height = ppt->imgheight;
  image->un[0] = 1;
  image->un[1] = 0;
  image->deep_color[0] = 0x18;
  image->deep_color[1] = 0;
  image->compression = 0;
  image->size_image = ((ppt->imgwidth + ppt->imgwidth % 4) * 3)
                      * ppt->imgheight;
  image->widht_image = 2833;
  image->height_image = 2833;
  image->color = 0;
  image->nb_color = 0;
}

void	fill_with_zero(int fd, int rest)
{
  void	*zero;
  int	i;

  i = 0;
  if ((zero = malloc(rest)) == NULL)
    return ;
  while (i < rest)
    {
      ((char*)zero)[i] = 0x0;
      ++i;
    }
  my_putbyte(zero, fd, rest);
  free(zero);
}

void	fill_bmp(char *img, int fd, t_info_bmp *info, t_par *ppt)
{
  int	x;
  int	y;
  int	octet;
  int	width;

  width = ppt->imgwidth;
  octet = ppt->bpp / 8;
  my_putbyte((void *)info, fd, sizeof(t_info_bmp));
  y = ppt->imgheight - 1;
  while (y >= 0)
    {
      x = 0;
      while (x < (width * octet))
        {
          if ((octet == 4 && x % 4 != 3) || octet == 3)
            {
              my_putbyte((&(img[(y * octet * width) + x])), fd, 3);
              x += 3;
            }
          ++x;
        }
      fill_with_zero(fd, (width * 3) % 4);
      --y;
    }
}

void	nb_to_str(char *str, int nb, int size)
{
  int	i;

  i = 0;
  while (size > 0)
    {
      ++i;
      size /= 10;
    }
  size = i;
  nb *= 10;
  while (nb >= 10 && i > 0)
    {
      nb /= 10;
      str[--i] = nb % 10 + '0';
    }
  str[size] = '\0';
}

int		output_bmp(t_par *ppt)
{
  t_info_bmp	image;
  char		name[17];
  int		fd;

  if (ppt->bpp != 32 && ppt->bpp != 24)
    return (merror("Color should be coded on 32 or 24 bits\n", -1));
  if (get_file_name(name, ".bmp") == NULL)
    return (-1);
  init_bmp(&image, ppt);
  if ((fd = check_perror("Couldn't create the bmp file",
                         open(&name[2], O_WRONLY | O_CREAT | O_TRUNC, 0664)))
            == -1)
    return (-1);
  fill_bmp(ppt->data, fd, &image, ppt);
  check_perror("Close", close(fd));
  return (0);
}
