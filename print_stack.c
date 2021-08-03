#include "libps.h"

void    print_line(s_stack *current, int i)
{
    int num;

    if (!current->len || i > current->len)
    {
        write(1, "*", 1);
        return ;
    }
    num = current->tab[i];
    while (num-- / 3)
        write(1, "+", 1);

}

void    print_stack(s_stack *a, s_stack *b)
{
    int i;

	i = -1;
	while (++i < b->len)
		printf("      %d[%d]  \n", i, b->tab[i]);
	printf(" ----------\n");
	printf("    b.     \n");
	i = -1;
	while (++i < a->len)
		printf("      %d[%d]  \n", i, a->tab[i]);
	printf(" ----------\n");
	printf("    a.     \n");
    a->nbr_mooves += 1;
 /*   
    int j;
    int len;

    i  = 0;
    len = 0;
    if (!a->len)
        len = 3;
    else
    { 
        while (a->tab[i])
        {
            if (a->tab[i] > len)
                len = a->tab[i];
            i++;
        }
    }
    i = 0;
    j = 0;
    int l;
    while (i < a->len && j < b->len)
    {
        print_line(a, i);
        l = 0;
        while (l++ < (len - a->tab[i]))
            write(1, " ", 1);
         write(1, " | ", 3);
        print_line(b, j);
        write(1, "\n", 1);
        i++;
        j++;
    }
    write(1, "\n", 1);
    usleep(200000);*/
}