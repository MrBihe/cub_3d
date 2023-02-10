#include "cub3d.h"

int main(int argc, char **argv)
{
	(void)argc;
	t_map *map;

	map = malloc(sizeof(t_map));
	check_filename(argv[1]);
	set_map(argv[1], map);
	get_var(map);
	return (0);
}