#include "lem-in.h"

int		main()
{
	t_farm	*farm;
	t_ps	*ps;

	farm = ft_init_farm();
	ft_print_farm(farm);
	ps = ft_start_bfs(farm);
	ft_print_path(ps->path);
	return (0);
}
