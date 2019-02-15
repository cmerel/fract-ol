/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 17:12:27 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/12 15:57:07 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int				motion_mouse(int x, int y, t_all *all)
{
	int			i;

	i = 0;
	if (all->choice != 1)
		return (0);
	if (all->p.lock % 2 == 0)
		return (0);
	x = x - (all->p.w / 2);
	y = (all->p.w / 2) - y;
	all->nb.c_i = y / all->p.zoom;
	all->nb.c_r = x / all->p.zoom;
	while (i < all->p.w * all->p.h)
	{
		all->img.data[i] = 0;
		i++;
	}
	julia(all);
	mlx_put_image_to_window(all->img.mlx, all->img.win, all->img.img, 0, 0);
	return (0);
}

static int		zoom_in(int x, int y, t_all *all)
{
	int			i;

	i = 0;
	x++;
	y++;
	all->p.x1 /= 1.1;
	all->p.y1 /= 1.1;
	all->p.x2 /= 1.1;
	all->p.y2 /= 1.1;
	all->p.zoom *= 1.1;
	while (i < all->p.w * all->p.h)
	{
		all->img.data[i] = 0;
		i++;
	}
	comp(all);
	mlx_put_image_to_window(all->img.mlx, all->img.win, all->img.img, 0, 0);
	return (0);
}

static int		zoom_out(int x, int y, t_all *all)
{
	int			i;

	i = 0;
	x++;
	y++;
	all->p.x1 *= 1.1;
	all->p.x2 *= 1.1;
	all->p.y1 *= 1.1;
	all->p.y2 *= 1.1;
	all->p.zoom /= 1.1;
	while (i < all->p.w * all->p.h)
	{
		all->img.data[i] = 0;
		i++;
	}
	comp(all);
	mlx_put_image_to_window(all->img.mlx, all->img.win, all->img.img, 0, 0);
	return (0);
}

int				zoom(int button, int x, int y, t_all *all)
{
	if (button == 1)
		all->p.lock++;
	if (button == 4)
		zoom_out(x, y, all);
	if (button == 5)
		zoom_in(x, y, all);
	return (1);
}
