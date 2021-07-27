#include "libps.h"

void	clean_all(s_stack *a)
{
	int	i;

	i = 0;
	while (a->tab[i])
		free(a->tab[i++]);
	free(a->tab);
}
