#include <stddef.h>

int is_rej(const char letter, const char *reject)
{
    int i = 0;
    while (reject[i])
    {
        if (letter == reject[i])
            return (1);
        i++;
    }
    return(0);
}

size_t  ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    while (s[i])
    {
        if (is_rej(s[i], reject) == 1)
            return (i);
        i++;
    }
    return(i);
}

// #include <string.h>
// #include <stdio.h>
// int main (void)
// {
//     char *str = "abd abd abc abc";
//     char *rej = "d";
//     printf("real : %ld\n",strcspn(str, rej));
//     printf("mine : %ld\n",ft_strcspn(str, rej));
// }