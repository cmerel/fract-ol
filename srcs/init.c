/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/28 14:28:35 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/13 11:08:50 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/fractol.h"

t_cmplx		init_cmplx(void)
{
	t_cmplx nb;

	nb.c_r = 0.285;
	nb.c_i = 0.01;
	nb.z_r = 0;
	nb.z_i = 0;
	return (nb);
}

t_color		init_color(void)
{
	t_color color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	return (color);
}

t_img		init_img(void)
{
	t_img	img;

	img.img = 0;
	img.win = 0;
	img.mlx = 0;
	img.data = 0;
	img.h = 0;
	img.w = 0;
	return (img);
}

t_draw		init_draw(char *str)
{
	t_draw	p;

	if (choice(str) == 1)
	{
		p.x1 = -1;
		p.y1 = -1.2;
		p.zoom = 500;
		p.h = 1200;
	}
	if (choice(str) == 2)
	{
		p.x1 = -2;
		p.y1 = -1.5;
		p.zoom = 350;
		p.h = 1000;
	}
	if (choice(str) == 3)
	{
		p.x1 = -1.8;
		p.y1 = -0.7;
		p.zoom = 300;
		p.h = 1000;
	}
	return (p);
}

void		init_all(char *str, t_all *all)
{
	all->img = create_image(1000, 1200);
	all->color = init_color();
	all->choice = choice(str);
	all->nb = init_cmplx();
	all->p = init_draw(str);
	all->p.y = 0;
	all->p.tmp = 0;
	all->p.lock = 0;
	all->p.x2 = 1.2;
	all->p.y2 = 1.2;
	all->p.x = 0;
	all->p.i = 0;
	all->p.it_max = 150;
	all->p.w = 1000;
}
