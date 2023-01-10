#include <stdio.h>
#include <stdlib.h>

//Tout simplement

int main (int ac, char **av)
{
    if (ac == 4)
    {
        int a = atoi(av[1]);
        int b = atoi(av[3]);
        char op = av[2][0];

        if (op == '+')
            printf("%d",a+b);
        if (op == '-')
            printf("%d",a-b);
        if (op == '*')
            printf("%d",a*b);
        if (op == '/')
            printf("%d",a/b);
        if (op == '%')
            printf("%d",a%b);
    }
    printf("\n");
}