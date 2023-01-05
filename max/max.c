int max(int *tab, unsigned int len)
{
    int tempmax = 0;
    unsigned int i = 0;

    while(i <= len)
    {
        if (tab[i] > tempmax)
            tempmax = tab[i];
        i++;
    }
    return(tempmax);
}