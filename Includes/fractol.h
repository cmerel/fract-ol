/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/21 17:03:42 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/13 13:54:27 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

typedef struct		s_img
{
	void			*img;
	void			*win;
	void			*mlx;
	unsigned int	*data;
	double			w;
	double			h;
}					t_img;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct		s_cmplx
{
	double			z_r;
	double			z_i;
	double			c_r;
	double			c_i;
}					t_cmplx;

typedef struct		s_draw
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				i;
	int				x;
	int				y;
	int				w;
	int				h;
	double			tmp;
	double			zoom;
	int				it_max;
	int				lock;
}					t_draw;

typedef struct		s_all
{
	t_img			img;
	t_color			color;
	t_cmplx			nb;
	t_draw			p;
	int				choice;
}					t_all;

void				setpx(t_all *img, int x, int y, int color);
void				mandel(t_all *all);
void				julia(t_all *all);
void				cmerel(t_all *all);
void				comp(t_all *all);
void				check_color(t_color *color);
void				init_all(char *str, t_all *all);

int					main(int argc, char **argv);
int					choice(char *str);
int					colorpoint(t_color color);
int					event(t_all *all);
int					hook_keydown(int key, t_all all);
int					motion_mouse(int x, int y, t_all *all);
int					zoom(int button, int x, int y, t_all *all);
int					move(int key, t_all *all);
int					move2(int key, t_all *all);
int					iter(int key, t_all *all);

t_img				create_image(int w, int h);

#endif
