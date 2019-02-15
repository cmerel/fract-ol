/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   img.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 15:10:18 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 14:48:48 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void		check_color(t_color *color)
{
	if (color->r < 0)
		color->r = 255 + color->r;
	if (color->r > 255)
		color->r = color->r - 255;
	if (color->g < 0)
		color->g = 255 + color->g;
	if (color->g > 255)
		color->g = color->g - 255;
	if (color->b < 0)
		color->b = 255 + color->b;
	if (color->b > 255)
		color->b = color->b - 255;
}

t_img		create_image(int w, int h)
{
	t_img	img;
	int		tmp[3];

	img.mlx = mlx_init();
	img.img = mlx_new_image(img.mlx, w, h);
	img.data = (unsigned int *)mlx_get_data_addr(img.img, &tmp[0],
			&tmp[1], &tmp[2]);
	img.w = w;
	img.h = h;
	ft_memset(img.data, 0, w * h * 4);
	return (img);
}

void		setpx(t_all *all, int x, int y, int color)
{
	if (x < 0 || x >= all->img.w || y < 0 || y >= all->img.h)
		return ;
	all->img.data[x + y * 1000] = color;
}

int			colorpoint(t_color color)
{
	return (color.r * 65536 + color.g * 256 + color.b);
}
