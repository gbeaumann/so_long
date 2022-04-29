/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:26:39 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/29 15:25:31 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	main(int argc, char **argv)
{
	static t_read_map	gnl = {.fd = -1};
	t_data				img;
	t_find_player		player;
	int					fd;
	char				*map_gnl;
	
	if (argc != 2)
		check_arguments();
	img.img_height = 52;
	img.img_width = 52;
	img.exit_height = 0;
	img.exit_width = 0;
	img.coins = 0;
	img.move_count = 0;
	img.mlx = mlx_init();
	fd = open(argv[1], O_RDONLY);
	if (fd < 1)
		check_map_existance();
	check_map_name(argv[1]);
	map_gnl = get_next_line(fd, &gnl, &img);
	img.coins = count_coins(map_gnl);
	img.mlx_window = mlx_new_window(img.mlx, (img.width * 52), (img.height * 52), "so_long");
	img.map = ft_split(map_gnl, '\n');
	check_error(&img, &gnl, map_gnl);
	print_map(&img, &player);
	img.count_pos = img.width / 2 * 52;
	mlx_string_put(img.mlx, img.mlx_window, img.count_pos - 40, 30, 0x00ffff00, "Move: ");
	mlx_string_put(img.mlx, img.mlx_window, img.count_pos, 30, 0x00ffff00, "0");
	ft_printf("Move count: 0\n");
	mlx_key_hook(img.mlx_window, player_movement, &img);
	mlx_hook(img.mlx_window, 2, 1L<<0, ft_close, &img);
	mlx_hook(img.mlx_window, 17, 1L<<5, ft_clic_close, &img);
	mlx_loop(img.mlx);
}
