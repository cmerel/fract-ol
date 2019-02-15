/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/18 15:32:56 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/13 11:07:38 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int		choice(char *str)
{
	if (strcmp(str, "julia") == 0)
		return (1);
	if (strcmp(str, "mandelbrot") == 0)
		return (2);
	if (strcmp(str, "cmerel") == 0)
		return (3);
	return (0);
}

void	comp(t_all *all)
{
	if (all->choice == 1)
		julia(all);
	if (all->choice == 2)
		mandel(all);
	if (all->choice == 3)
		cmerel(all);
	if (all->img.win == NULL)
		all->img.win = mlx_new_window(all->img.mlx, all->p.w, all->p.h,
				"fract'ol");
	mlx_put_image_to_window(all->img.mlx, all->img.win, all->img.img, 0, 0);
	event(all);
}

int		event(t_all *all)
{
	mlx_hook(all->img.win, 6, 1L << 6, motion_mouse, all);
	mlx_hook(all->img.win, 4, 1L << 2, zoom, all);
	mlx_hook(all->img.win, 2, 1L << 0, iter, all);
	mlx_key_hook(all->img.win, hook_keydown, NULL);
	return (0);
}

int		main(int argc, char **argv)
{
	t_all			all;
	char			*str;

	if (argc == 1)
	{
		ft_putstr("Choose your fractal\n");
		return (0);
	}
	str = argv[1];
	all.choice = choice(str);
	if (argc > 2 || all.choice == 0)
	{
		ft_putstr("What do you mean ?\n -julia\n -mandelbrot\n -cmerel\n");
		return (0);
	}
	else
	{
		init_all(str, &all);
		comp(&all);
	}
	mlx_loop(all.img.mlx);
	return (0);
}
