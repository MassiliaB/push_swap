#include "libps.h"

void clean_all(char **a_tab)
{
	int	i;

	i = 0;
	while (a_tab[i])
		free(a_tab[i++]);
	free(a_tab);
}
