/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   keyboard.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 17:13:38 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 14:47:17 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	color_change(int key, t_all *all)
{
	if (key == 14 || key == 17)
		all->color.r += 25 * (key == 14 ? -1 : 1);
	if (key == 2 || key == 5)
		all->color.g += 25 * (key == 2 ? -1 : 1);
	if (key == 8 || key == 11)
		all->color.b += 25 * (key == 8 ? -1 : 1);
	check_color(&all->color);
}

int			hook_keydown(int key, t_all all)
{
	(void)all.img.mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int			move(int key, t_all *all)
{
	all->p.i = 0;
	if (key == 123)
	{
		all->p.x1 -= 0.1 / (all->p.zoom / 100);
		all->p.x2 -= 0.1 / (all->p.zoom / 100);
		while (all->p.i < all->p.w * all->p.h)
		{
			all->img.data[all->p.i] = 0;
			all->p.i++;
		}
	}
	if (key == 124)
	{
		all->p.x1 += 0.1 / (all->p.zoom / 100);
		all->p.x2 += 0.1 / (all->p.zoom / 100);
		while (all->p.i < all->p.w * all->p.h)
		{
			all->img.data[all->p.i] = 0;
			all->p.i++;
		}
	}
	return (0);
}

int			move2(int key, t_all *all)
{
	all->p.i = 0;
	if (key == 125)
	{
		all->p.y1 += 0.1 / (all->p.zoom / 100);
		all->p.y2 += 0.1 / (all->p.zoom / 100);
		while (all->p.i < all->p.w * all->p.h)
		{
			all->img.data[all->p.i] = 0;
			all->p.i++;
		}
	}
	if (key == 126)
	{
		all->p.y1 -= 0.1 / (all->p.zoom / 100);
		all->p.y2 -= 0.1 / (all->p.zoom / 100);
		while (all->p.i < all->p.w * all->p.h)
		{
			all->img.data[all->p.i] = 0;
			all->p.i++;
		}
	}
	return (0);
}

int			iter(int key, t_all *all)
{
	all->p.i = 0;
	if (key == 69)
	{
		all->p.it_max += 5;
		while (all->p.i < all->p.w * all->p.h)
		{
			all->img.data[all->p.i] = 0;
			all->p.i++;
		}
	}
	if (key == 78)
	{
		all->p.it_max -= 10;
		while (all->p.i < all->p.w * all->p.h)
		{
			all->img.data[all->p.i] = 0;
			all->p.i++;
		}
	}
	move(key, all);
	move2(key, all);
	color_change(key, all);
	comp(all);
	mlx_put_image_to_window(all->img.mlx, all->img.win, all->img.img, 0, 0);
	return (0);
}
