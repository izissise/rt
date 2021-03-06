/*
** pars.h for pars in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 13 15:55:16 2013 luc sinet
** Last update Sun Jun  9 03:34:01 2013 luc sinet
*/

#ifndef PARS_H_
# define PARS_H_

# define LIMIT(x, n1, n2) (((x) < (n1)) ? (n1) : ((x) > (n2)) ? (n2) : (x))
# define BOOL(x) (x >= 1) ? 1 : 0
# define PARAM 19
# define NB_OBJ 13
# define T_ACCOL(x) (x == PARAM - 2) ? 1 : (x == PARAM - 1) ? -1 : 0

# define SPHERE 0
# define PLAN 1
# define CONE 2
# define CYLINDER 3
# define CIRCLE 4
# define SQUARE 5
# define TRIANGLE 6
# define PARABOLOIDE 7
# define HYERBOLOIDE 8
# define TANGLE 9
# define PILLOW 10
# define CHUBS 11
# define TORE 12
# define NB_OPT 8

typedef struct	s_obj	t_obj;
typedef struct	s_lig	t_lig;
typedef struct	s_cam	t_cam;

typedef struct	s_pars
{
  char		**file;
  char		*line;
  t_text	*text;
  int		accol;
  int		rv;
  int		nb_shape;
  int		nb_light;
  int		nb_cam;
  int		nb_opt;
  int		nb_model;
}		t_pars;

int	other_opt(char *line, t_obj *ept, t_text *text);
void	fill_angle(t_obj *ept, char *line);
void	fill_center(t_obj *ept, char *line);
void	init_light(t_lig *ltab, t_pars *opt);
int	init_elem(t_obj *tab, t_pars *opt);
void	init_elem_indices(t_indice *ipt);
void	init_single_elem(t_obj *obj);
void	init_nb_obj(t_pars *opt);
int	fill_tab(t_pars *opt, t_obj *tab);
int	fill_light(t_pars *opt, t_lig *ltab);
int	fill_cam(t_pars *opt, t_cam *cpt);
void	fill_pert(char *line, double *pert);
int	fill_opt(t_pars *opt, t_rt *rpt);
int	pars(t_rt *rpt, char **av, t_cam *cpt);
void	fill_limits(char *line, double *limit);
void	get_color(char *line, unsigned char *color);
void	init_shapes(char **shape);
void	init_triangle_size(t_obj *obj);
void	init_tangle_size(t_obj *obj);
void	init_cam(t_cam *cpt);
void	skip_adds(char *line, int *i);
int	light_carac(char *line, t_lig *ltab, int i);
int	file_error(char *line, int lnb, int ret);
int	get_config_file(t_pars *ppt, char *conf_name);
int	indice(char *line, t_obj *ept, t_text *text);
int	deformation(char *line, t_obj *ept, t_text *text);
int	shape_carac(char *line, t_obj *ept, t_text *text);
void	skip_adds(char *line, int *i);
void	init_tab_names(char **shape);
void	skip_fnumber(char *str, int *i);
void	fill_vec(double vec[3], char *line);
int	fill_texture(t_pars *opt, t_rt *rpt);
int	fill_model(t_pars *opt, t_obj **tab);
int	get_args(t_obj *tab, t_pars *opt, int *y);
void	skip_space(char *line, int *i);
int	parse_argv(char **av, t_rt *rpt, char **filename);
void	pars_color(char *line, t_obj *ept, t_text *text);
void	pars_brightness(char *line, t_obj *ept, t_text *text);
void	pars_texture(char *line, t_obj *ept, t_text *text);
void	pars_absorbance(char *line, t_obj *ept, t_text *text);
void	pars_limits(char *line, t_obj *ept, t_text *text);
void	pars_perturbations(char *line, t_obj *ept, t_text *text);
void	pars_normal1(char *line, t_obj *ept, t_text *text);
void	pars_normal2(char *line, t_obj *ept, t_text *text);
void	pars_normal(char *line, t_obj *ept, t_text *text);
void	pars_alpha(char *line, t_obj *ept, t_text *text);
void	pars_refraction(char *line, t_obj *ept, t_text *text);
void	pars_reflection(char *line, t_obj *ept, t_text *text);
void	pars_cst(char *line, t_obj *ept, t_text *text);
void	pars_size(char *line, t_obj *ept, t_text *text);
void	pars_perlin(char *line, t_obj *ept, t_text *text);
void	pars_checker(char *line, t_obj *ept, t_text *text);
void	pars_bump(char *line, t_obj *ept, t_text *text);
void	get_seed(t_opt *opt, char *line, int l);
void	init_objptr(void (**objptr)(char *line, t_obj *ept, t_text *text));
void	get_opt_filter(t_opt *opt, char *line, int l);
void	get_opt_fog(t_opt *opt, char *line, int l);
void	get_gamma_coef(t_opt *opt, char *line, int l);
void	get_aa_coef(t_opt *opt, char *line, int l);
void	get_shadows_type(t_opt *opt, char *line, int l);
void	get_contrast(t_opt *opt, char *line, int l);
void	get_saturation(t_opt *opt, char *line, int l);
void	init_opt(t_opt *opt);
void	init_opt_carac(char **tab);
void	init_opt_pt(void (**fptr)(t_opt *opt, char *line, int l));
int	link_text(t_obj *ept, char *line, t_text *text);

#endif /* !PARS_H_ */
