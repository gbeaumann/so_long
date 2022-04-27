/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:26:39 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/27 15:22:07 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	main(void)
{
	static t_read_map	gnl = {.fd = -1};
	t_data				img;
	t_find_player		player;
	int					fd;
	char				*map_gnl;
	int	i;
	
	i = 0;
	img.img_height = 52;
	img.img_width = 52;
	img.exit_height = 0;
	img.exit_height = 0;
	img.coins = 0;
	img.move_count = 0;
	//img.move = NULL;
	img.mlx = mlx_init();
	fd = open("map_test.ber", O_RDONLY);
	map_gnl = get_next_line(fd, &gnl, &img);
	img.coins = count_coins(map_gnl);
	img.mlx_window = mlx_new_window(img.mlx, (img.width * 52), (img.height * 52), "so_long");
	img.map = ft_split(map_gnl, '\n');
	check_error(&img, &gnl, map_gnl);
	print_map(&img, &player);
	find_exit(&img);
	mlx_key_hook(img.mlx_window, player_movement, &img);
	mlx_hook(img.mlx_window, 2, 1L<<0, ft_close, &img);
	mlx_hook(img.mlx_window, 17, 1L<<5, ft_clic_close, &img);
	mlx_loop(img.mlx);
}