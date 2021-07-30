#include "libps.h"

void    print_line(s_stack *current, int i)
{
    int num;

    if (!current->tab[i])
        return ;
    if (!current->len)
    {
        write(1, "*", 1);
        return ;
    }
    num = current->tab[i];
    while (num-- / 2)
        ft_putstr("+");

}

void    print_stack(s_stack *a, s_stack *b)
{
 //   int i;
   // static int n_mooves;
  //  int j;
//    int len;
(void)a;
(void)b;
/*	i = -1;
	while (b->tab[++i])
		printf("      %d[%d]  \n", i, b->tab[i]);
	printf(" ----------\n");
	printf("    b.     \n");
	i = -1;
	while (a->tab[++i])
		printf("      %d[%d]  \n", i, a->tab[i]);
	printf(" ----------\n");
	printf("    a.     \n");*/
  /*  n_mooves += 1;
    ft_putnbr(n_mooves);*/
/*
    i  = 0;
    len = 0;
    if (!a->len)
    {
        while (b->tab[i])
        {
            if (b->tab[i] > len)
                len = b->tab[i];
            i++;
        }
    }
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
        print_line(b, j);
        write(1, "\n", 1);
        i++;
        j++;
    }
    write(1, "\n", 1);
    ft_putstr("-----a-----   ");
    ft_putstr("  -----b-----\n");
    usleep(75000);*/
}