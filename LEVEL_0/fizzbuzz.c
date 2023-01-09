#include <unistd.h>

void print_numbers(int nb)
{
    char numbers[] = "0123456789";
    if(nb > 9)
        print_numbers(nb/10);
    write(1,&numbers[nb%10],1);
}

int main (void)
{
    int i = 1;
        while (i <= 100)
        {
            if (i%3 == 0 && i%5 == 0)
                write(1,"fizzbuzz\n",9);
            else if (i%3 == 0)
                write(1,"fizz\n",5);
            else if (i%5 == 0)
                write(1,"buzz\n",5);
            else
            {
                print_numbers(i);
                write(1,"\n",1);
            }
            i++;
        }
}