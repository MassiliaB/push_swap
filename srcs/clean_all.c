#include "../libps.h"

void	clean_all(s_stack *a, s_stack *b)
{
	free(a->tab);
	free(b->tab);
}
