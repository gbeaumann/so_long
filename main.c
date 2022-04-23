/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoirebeaumann <gregoirebeaumann@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:26:39 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/23 21:10:42 by gregoirebea      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	main(void)
{
	static t_read_map	gnl = {.fd = -1};
	t_data				img;
	int					fd;
	char				*map_gnl;
	int	i;
	
	i = 0;
	img.img_height = 52;
	img.img_width = 52;
	img.mlx = mlx_init();
	fd = open("map_test.ber", O_RDONLY);
	map_gnl = get_next_line(fd, &gnl);
	img.mlx_window = mlx_new_window(img.mlx, (gnl.width * 52), (gnl.height * 52), "test");
	//img.img = mlx_new_image(img.mlx, (gnl.width * 52), (gnl.height * 52));
	//img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_length, &img.endian);
	//get_map(&gnl, &img, map_gnl); a effacer
	img.map = ft_split(map_gnl, '\n');
	check_error(&img, &gnl, map_gnl);
	print_map(&img, &gnl);
	mlx_hook(img.mlx_window, 2, 1L<<0, ft_close, &img);
	mlx_hook(img.mlx_window, 17, 1L<<5, ft_clic_close, &img);
	mlx_loop(img.mlx);
}