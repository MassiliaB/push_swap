#include "libps.h"

void    print_stack(t_stack *a)
{
//	char *end = "";

(void)a;
(void)a->b;
 /* int i = -1;
	while (++i < a->b->len)
    {

//		printf("\033[0;31m");
		printf(" [%ld]  ", a->b->tab[i]);
//	    printf("\033[0m");
    }
    printf("\n ----------");
	printf("    b.     \n");
	i = -1;
	while (++i < a->len)
	{	
//		printf("\033[0;96m");
        printf(" [%ld]  ",  a->tab[i]);
//		printf("\033[0m");
    }
    printf("\n ----------");
	printf("    a.     \n");
*/
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