/*
** solve_quartic.c for rt in /home/debas_e//Desktop/projet/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Jun  3 20:50:18 2013 etienne debas
** Last update Mon Jun  3 20:55:59 2013 etienne debas
*/

# include "solve.h"
# include "include/main.h"

void		set_pqr_quartic(double *pqr, double *coef)
{
  pqr[0] = -3.0 * (coef[1] * coef[1]) / (8.0 * coef[0] * coef[0])
    + (coef[2] / coef[0]);
  pqr[1] = (pow(coef[1] / 2.0, 3) / pow(coef[0], 3)) - (0.5 * coef[1] * coef[2])
    / pow(coef[0], 2) + coef[3] / coef[0];
  pqr[2] = -3.0 * pow((coef[1] / 4.0) / coef[0], 4)
    + coef[2] * (pow(coef[1] / 4.0, 2) / pow(coef[0], 3))
    - ((0.25 * coef[1] * coef[3]) / (coef[0] * coef[0]))
    + (coef[4] / coef[0]);
}

void		init_to_send_cubic(double p, double q,
				   double r, double *coef)
{
  coef[0] = 8.0;
  coef[1] = -4.0 * p;
  coef[2] = -8.0 * r;
  coef[3] = 4.0 * r * p - q * q;
}

int		init_and_send_second(double *pqr, double y0, double *res)
{
  double	a0;
  double	b0;
  double	coef[3];
  int		nb_sol;

  nb_sol = 0;
  a0 = sqrt(-pqr[0] + 2.0 * y0);
  if ((2.0 * y0 - pqr[0]) != 0.0)
    b0 = -pqr[1] / (2.0 * a0);
  else
    b0 = sqrt(y0 * y0 - pqr[2]);
  coef[0] = 1.0;
  coef[1] = -a0;
  coef[2] = y0 - b0;
  nb_sol = solve_quadratic(coef, res);
  coef[0] = 1.0;
  coef[1] = a0;
  coef[2] = y0 + b0;
  nb_sol += solve_quadratic(coef, &(res[nb_sol]));
  return (nb_sol);
}

/*
** Résoud les équations du quatrième degrée
** Prend un pointeur sur les tableau de res
** Renvoi le nombre de solution de trouvé
*/

int		solve_quartic(double *coef, double *res)
{
  double	pqr[3];
  double	coef_tmp[4];
  double	res_tmp[3];
  int		nb_sol;
  int		count;

  count = 0;
  nb_sol = 0;
  if (fabs(coef[0]) <= ZERO)
    return (solve_cubic(&(coef[1]), res));
  set_pqr_quartic(pqr, coef);
  init_to_send_cubic(pqr[0], pqr[1], pqr[2], coef_tmp);
  if (solve_cubic(coef_tmp, res_tmp) == 0)
    return (0);
  nb_sol = init_and_send_second(pqr, res_tmp[0], res);
  while (count < nb_sol)
    res[count++] -= coef[1] / (4.0 * coef[0]);
  return (nb_sol);
}
