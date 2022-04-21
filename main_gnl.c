#include	"so_long.h"
#include	<fcntl.h>
#include	<stdio.h>

int	main(void)
{
	int	fd;

	fd = open("map_test.ber", O_RDONLY);
	printf ("%s", get_next_line(fd));
	return (0);
}