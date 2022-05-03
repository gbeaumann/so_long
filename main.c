/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:26:39 by gbeauman          #+#    #+#             */
/*   Updated: 2022/05/03 15:20:43 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	main(int argc, char **argv)
{
	static t_read_map	gnl = {.fd = -1};
	t_data				img;
	int					fd;
	char				*map_gnl;

	if (argc != 2)
		check_arguments();
	init_struct(&img);
	fd = open(argv[1], O_RDONLY);
	if (fd < 1)
		check_map_existance();
	check_map_name(argv[1]);
	map_gnl = get_next_line(fd, &gnl, &img);
	img.coins = count_coins(map_gnl);
	img.mlx_win = mlx_new_window(img.mlx,
			(img.w * 52), (img.h * 52), "so_long");
	img.map = ft_split(map_gnl, '\n');
	check_error(&img, &gnl, map_gnl);
	print_map(&img);
	img.count_pos = img.w / 2 * 52;
	move_count_init(&img);
	mlx_key_hook(img.mlx_win, player_movement, &img);
	mlx_hook(img.mlx_win, 2, 1L << 0, ft_close, &img);
	mlx_hook(img.mlx_win, 17, 1L << 5, ft_clic_close, &img);
	mlx_loop(img.mlx);
}
