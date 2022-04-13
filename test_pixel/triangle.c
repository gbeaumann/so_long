#include	<stdio.h>
#include	"so_long.h"
#include	<math.h>

typedef	struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;
	int		x;
	int		y;

	x = 0;
	y = 100;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "test");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (y > 0)
	{
		my_mlx_pixel_put(&img, x, y, 0x0033FFFF);
		y--;
		x++;
	}
	while (y < 100)
	{
		my_mlx_pixel_put(&img, x, y, 0x00ff0000);
		y++;
		x++;
	}
	while (x > 0)
	{
		my_mlx_pixel_put(&img, x, y, 0x0000ffff);
		x--;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 200, 200);
	mlx_loop(mlx);
}
