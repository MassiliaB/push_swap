#include "../libps.h"

void	clean_all(t_stack *a, t_stack *b)
{
	free(a->tab);
	free(b->tab);
}
