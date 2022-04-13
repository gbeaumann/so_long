#include	<stdio.h>
#include	"so_long.h"
#include	<stdlib.h>
#include	<unistd.h>

typedef	struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
int clic_close(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit (0);
}
int	ft_close(int keycode, t_data *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
	return (0);
}

/*int	key_hook(int keycode, t_data *img)
{
	printf("%d\n", keycode);
	return (0);
}*/

int	render_next_frame(t_data *img)
{
	static int	check = 0;
	int			x;
	int			y;

	if (img->mlx != NULL && check == 0)
	{
		y = 0;
		while (y < 600)
		{
			x = 0;
			while (x < 800)
			{
				my_mlx_pixel_put(img, x, y, 0x00ff0000);
				x++;
			}
			y++;
		}
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
		check = 1;
		sleep(1);
		return (0);
	}
	if (img->mlx != NULL && check == 1)
	{
		img->y = 0;
		while (img->y < 600)
		{
			img->x = 0;
			while (img->x < 800)
			{
				my_mlx_pixel_put(img, img->x, img->y, 0x0000ff00);
				img->x++;
			}
			img->y++;
		}
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
		check = 2;
		sleep(1);
		return (0);
	}
	if (img->mlx != NULL && check == 2)
	{
		img->y = 0;
		while (img->y < 600)
		{
			img->x = 0;
			while (img->x < 800)
			{
				my_mlx_pixel_put(img, img->x, img->y, 0x000000ff);
				img->x++;
			}
			img->y++;
		}
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
		check = 0;
		sleep(1);
		return (0);
	}
	return (0);
}

int	main(void)
{
	t_data	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 800, 600, "test");
	img.img = mlx_new_image(img.mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_loop_hook(img.mlx, render_next_frame, &img);
	//mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 2, 1L<<0, ft_close, &img);
	mlx_hook(img.mlx_win, 17, 1L<<5, clic_close, &img);
	//mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_loop(img.mlx);
}
