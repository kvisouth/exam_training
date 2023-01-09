int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i])
    {
        if (s1[i] != s2[i])
            return(s1[i] - s2[i]);
        i++;
    }
    return(0);
}

// #include <stdio.h>
// #include <string.h>
// int main (void)
// {
//     char *s1 = "bonjour";
//     char *s2 = "bonjour";
//     printf("Real : %d\n",strcmp(s1, s2));
//     printf("Mine : %d\n",ft_strcmp(s1, s2));
// }