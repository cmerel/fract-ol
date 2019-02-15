/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandel.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/03 14:11:59 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/13 13:52:52 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void		color_fractal(t_all *all)
{
	t_color		color;
	float		a;

	a = (float)all->p.i / (float)all->p.it_max;
	color.r = all->color.r * (a);
	color.g = all->color.g * (a);
	color.b = all->color.b * (a);
	setpx(all, all->p.x, all->p.y, (color.r << 16) + (color.g << 8)
			+ color.b);
}

static void		draw2(t_all *all)
{
	all->p.y = 0;
	while (all->p.y < all->p.h)
	{
		all->nb.z_r = 0;
		all->nb.z_i = 0;
		all->nb.c_r = all->p.x / all->p.zoom + all->p.x1;
		all->nb.c_i = all->p.y / all->p.zoom + all->p.y1;
		all->p.i = 0;
		while (all->nb.z_r * all->nb.z_r + all->nb.z_i * all->nb.z_i < 4
				&& all->p.i < all->p.it_max)
		{
			all->p.tmp = all->nb.z_r;
			all->nb.z_r = all->nb.z_r * all->nb.z_r - all->nb.z_i * all->nb.z_i
				+ all->nb.c_r;
			all->nb.z_i = 2 * all->nb.z_i * all->p.tmp + all->nb.c_i;
			all->p.i++;
		}
		if (all->p.i == all->p.it_max)
			setpx(all, all->p.x, all->p.y, 0x00000000);
		else
			color_fractal(all);
		all->p.y++;
	}
}

void			mandel(t_all *all)
{
	all->p.x = 0;
	while (all->p.x < all->p.w)
	{
		draw2(all);
		all->p.x++;
	}
}
