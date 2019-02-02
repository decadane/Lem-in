#include "lem-in.h"

int		main()
{
	t_farm		*farm;
	t_path_set	*set;
	int			i;

	i = 0;
	farm = ft_init_farm();
	ft_print_farm(farm);
	set = ft_start_bfs(farm);
	while (i < 3)
	{
		printf("Path: ");
		ft_print_path(set->paths[i]);
		printf(", Len: %zu, Ants: %zu\n", set->lens[i], set->ants[i]);
		i++;
	}
	return (0);
}
